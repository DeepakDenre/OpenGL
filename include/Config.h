#ifndef CONFIG_H
#define CONFIG_H

#include <string>

/**
 * @brief Global configuration constants for the OpenGL project.
 */
namespace Config
{
	// Window settings
	constexpr int WINDOW_WIDTH = 800;
	constexpr int WINDOW_HEIGHT = 800;
	constexpr char WINDOW_TITLE[] = "OpenGL Engine";
	
	// Debugging options
	constexpr bool ENABLE_LOGGING = true;
	const std::string LOG_FILE = "app.log";
}

#endif // CONFIG_H
