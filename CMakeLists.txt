cmake_minimum_required(VERSION 3.16)
project(OpenGLProject LANGUAGES C CXX)

# ----------------------
# General configuration
# ----------------------
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ----------------------
# Executable name variable
# ----------------------
set(APP_NAME "OpenGL")

# ----------------------
# Output directories
# ----------------------
# Send all runtime (executables) to ./bin/<BuildType>
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release)

# Optional: also group library outputs if you later add them
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# ----------------------
# GLFW: Build from source
# ----------------------
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

# ----------------------
# GLAD
# ----------------------
add_library(glad STATIC src/app/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ----------------------
# Executable
# ----------------------
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
add_executable(${APP_NAME} ${SRC_FILES})

target_include_directories(${APP_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
)

# ----------------------
# Link libraries
# ----------------------
find_package(OpenGL REQUIRED)
target_link_libraries(${APP_NAME} PRIVATE glfw glad OpenGL::GL dl pthread)

# ----------------------
# Extra compiler warnings
# ----------------------
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${APP_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif (MSVC)
    target_compile_options(${APP_NAME} PRIVATE /W4)
endif()

# ----------------------
# Copy shader/assets to runtime directory
# ----------------------
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# ----------------------
# Info summary
# ----------------------
message(STATUS "=== OpenGL Project Configuration ===")
message(STATUS "App Name: ${APP_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Output Directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Using GLFW from: ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw")
message(STATUS "GLAD include path: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "Build system: ${CMAKE_GENERATOR}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "====================================")
