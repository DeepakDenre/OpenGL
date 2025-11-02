#include<utils/Logger.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <mutex>

std::string Logger::timestamp()
{
    std::time_t now = std::time(nullptr);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);
}

std::string Logger::levelToString(LogLevel level)
{
    switch (level)
    {
    case LogLevel::LOG_INFO:
        return "[INFO]";
    case LogLevel::LOG_WARNING:
        return "[WARNING]";
    case LogLevel::LOG_ERROR:
        return "[ERROR]";
    case LogLevel::LOG_DEBUG:
        return "[DEBUG]";
    default:
        return "[UNKNOWN]";
    }
}

void Logger::init(const std::string &filename)
{
    std::lock_guard<std::mutex> lock(logMutex);
    if (!filename.empty())
    {
        logFile.open(filename, std::ios::app);
        fileEnabled = logFile.is_open();
    }
}

void Logger::log(LogLevel level, const std::string &message)
{
    std::lock_guard<std::mutex> lock(logMutex);
    std::ostringstream formatted;
    formatted << timestamp() << " " << levelToString(level) << " " << message << std::endl;

    std::cout << formatted.str();
    if (fileEnabled)
        logFile << formatted.str();
}

void Logger::shutdown()
{
    std::lock_guard<std::mutex> lock(logMutex);
    if (fileEnabled)
    {
        logFile.close();
        fileEnabled = false;
    }
}