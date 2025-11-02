#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <mutex>

enum class LogLevel
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_DEBUG
};

/**
 * @brief Thread-safe logging utility for console and file output.
 *
 * Example:
 * @code
 * Logger::init("app.log");
 * Logger::log(LogLevel::INFO, "Application started.");
 * @endcode
 */
class Logger
{
private:
    static inline std::ofstream logFile;
    static inline bool fileEnabled = false;
    static inline std::mutex logMutex;
    static std::string timestamp();
    static std::string levelToString(LogLevel level);

public:
    Logger() = delete;

    /**
     * @brief Initializes the logger with optional file output.
     * @param filename Optional file path for log output.
     */
    static void init(const std::string &filename = "");

    /**
     * @brief Logs a message with the given level.
     * @param level Log severity level.
     * @param message Message to log.
     */
    static void log(LogLevel level, const std::string &message);

    /**
     * @brief Closes the file stream safely.
     */
    static void shutdown();
};

#endif // LOGGER_H
