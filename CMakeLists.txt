cmake_minimum_required(VERSION 3.16)
project(OpenGLProject LANGUAGES C CXX)

# ---------------------------------------
# 🔧 Language standards
# ---------------------------------------
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------
# ⚙️ Executable name
# ---------------------------------------
set(APP_NAME "OpenGL")

# ---------------------------------------
# 📦 Output directories
# ---------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# ---------------------------------------
# 🧩 Global preprocessor definitions
# ---------------------------------------
add_compile_definitions(
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    byte=win_byte_override
)

# ---------------------------------------
# 🧱 GLFW (build from source)
# ---------------------------------------
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

# ---------------------------------------
# 🔆 GLAD (OpenGL loader)
# ---------------------------------------
add_library(glad STATIC src/app/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/include)

# ---------------------------------------
# 💾 Source files
# ---------------------------------------
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
add_executable(${APP_NAME} ${SRC_FILES})

target_include_directories(${APP_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/glfw/include
)

# ---------------------------------------
# 🎯 Apply modern C++ features only to your app (not C libs)
# ---------------------------------------
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${APP_NAME} PRIVATE -std=c++2b)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang")
    target_compile_options(${APP_NAME} PRIVATE -std=c++2b)
elseif (MSVC)
    target_compile_options(${APP_NAME} PRIVATE /std:c++latest)
endif()

# ---------------------------------------
# 🔗 Link libraries (platform-aware)
# ---------------------------------------
find_package(OpenGL REQUIRED)

if (WIN32)
    target_link_libraries(${APP_NAME} PRIVATE glfw glad OpenGL::GL gdi32)
elseif (APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED)
    target_link_libraries(${APP_NAME} PRIVATE
        glfw glad OpenGL::GL
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVIDEO_LIBRARY}
    )
elseif (ANDROID)
    target_link_libraries(${APP_NAME} PRIVATE glfw glad GLESv3 EGL log)
elseif (UNIX AND NOT ANDROID)
    find_package(Threads REQUIRED)
    find_package(X11 REQUIRED)
    target_link_libraries(${APP_NAME} PRIVATE
        glfw glad OpenGL::GL Threads::Threads
        ${X11_LIBRARIES} dl
    )
else()
    message(WARNING "⚠️ Unknown platform — linking generic OpenGL + dl/pthread")
    target_link_libraries(${APP_NAME} PRIVATE glfw glad OpenGL::GL dl pthread)
endif()

# ---------------------------------------
# ⚠️ Compiler warnings
# ---------------------------------------
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(${APP_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif (MSVC)
    target_compile_options(${APP_NAME} PRIVATE /W4)
endif()

# ---------------------------------------
# 📁 Copy runtime assets (shaders, textures, etc.)
# ---------------------------------------
file(COPY ${CMAKE_SOURCE_DIR}/src/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# ---------------------------------------
# 🧾 Info summary
# ---------------------------------------
message(STATUS "=== OpenGL Project Configuration ===")
message(STATUS "App Name: ${APP_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "System: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Build System: ${CMAKE_GENERATOR}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Output Directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "====================================")
