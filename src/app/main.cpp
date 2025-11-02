#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <core/Vertex.h>
#include <core/Color.h>
#include <core/Mesh.h>
#include <core/Shader.h>
#include <core/Program.h>
#include <Config.h>
#include <utils/Logger.h>
#include <filesystem>

using namespace std;

#ifdef _WIN32
    #include <windows.h>
#elif __APPLE__
    #include <mach-o/dyld.h>
#else
#include <unistd.h>
#endif

std::filesystem::path getExecutablePath()
{
    char buffer[4096];

#ifdef _WIN32
    GetModuleFileNameA(NULL, buffer, sizeof(buffer));
#elif __APPLE__
    uint32_t size = sizeof(buffer);
    if (_NSGetExecutablePath(buffer, &size) != 0)
        throw std::runtime_error("Path buffer too small");
#else // Linux and other Unix
    ssize_t count = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (count == -1)
        throw std::runtime_error("Failed to read /proc/self/exe");
    buffer[count] = '\0';
#endif

    return std::filesystem::canonical(buffer);
}

std::string getResourcePath(const std::string &relativePath)
{
    std::filesystem::path exePath = getExecutablePath();
    std::filesystem::path rootPath = exePath.parent_path().parent_path(); // go up from /bin/
    std::filesystem::path fullPath = rootPath / relativePath;
    return fullPath.string();
}


void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
    glViewport(0, 0, width, height);
}

void handleInput(GLFWwindow *win)
{

    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(win, true);
    }
    else if (glfwGetKey(win, GLFW_KEY_R) == GLFW_PRESS)
    {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    }
    else if (glfwGetKey(win, GLFW_KEY_G) == GLFW_PRESS)
    {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    }
    else if (glfwGetKey(win, GLFW_KEY_B) == GLFW_PRESS)
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    }
    else if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
}

void getFps(std::chrono::high_resolution_clock::time_point &startTime, long long &frameCount)
{
    frameCount++;
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = currentTime - startTime;
    if (elapsedTime.count() >= 0.2)
    {
        double fps = frameCount / elapsedTime.count();
        frameCount = 0;
        startTime = currentTime;
        cout << "FPS:" << fps << std::endl;
    }
}

int main()
{
    if (Config::ENABLE_LOGGING)
        Logger::init(Config::LOG_FILE);

    Logger::log(LogLevel::LOG_INFO, "Starting OpenGL Project...");

    // auto startTime = std::chrono::high_resolution_clock::now();
    // long long frameCount = 0;

    GLfloat n = 1.0f;

    Mesh O1(
        {0.0f, 0.0f, 0.0f},
        {Vertex(0.5f, 0.5f, 0.0f, Color(255, 255, 255, 255), n, n),
         Vertex(0.5f, -0.5f, 0.0f, Color(255, 255, 255, 255), n, 0.0f),
         Vertex(-0.5f, -0.5f, 0.0f, Color(255, 255, 255, 255), 0.0f, 0.0f),
         Vertex(-0.5f, 0.5f, 0.0f, Color(255, 255, 255, 255), 0.0f, n)},
        {0, 1, 2,
         0, 2, 3},
         getResourcePath("bin/assets/images/image.jpg"));

    if (!glfwInit())
    {
        Logger::log(LogLevel::LOG_INFO, "Failed to iniatialize GLFW!");
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    GLFWwindow *window = glfwCreateWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, Config::WINDOW_TITLE, NULL, NULL);

    if (!window)
    {
        Logger::log(LogLevel::LOG_INFO, "Failed to create window!");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Logger::log(LogLevel::LOG_INFO, "Failed to iniatialize glad!");
        glfwTerminate();
        return -1;
    }

    O1.setup();

    glViewport(0, 0, Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    Color::setBackground(143,139,130,255);

    // -------------------- Shaders --------------------
    Shader verShader(getResourcePath("bin/assets/shader/default/defaultVert.vert"), GL_VERTEX_SHADER);
    Shader fragShader(getResourcePath("bin/assets/shader/default/defaultFrag.frag"), GL_FRAGMENT_SHADER);
    Program shaderProgram(verShader, fragShader);

    while (!glfwWindowShouldClose(window))
    {
        handleInput(window);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.use();
        O1.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Logger::log(LogLevel::LOG_INFO, "Exiting application.");
    Logger::shutdown();

    glfwTerminate();
    return 0;
}
