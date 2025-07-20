#include <GLFW/glfw3.h>
#include <iostream>
#include <utility/AppStruct.h>
#include <utility/loadConfig.h>
#include <utility/color.h>
#include <utility/iconLoader.h>

using namespace std;

int main()
{
    // 1. Load the configuration from a file into your config instance
    //    (Make sure you have a "config.xml" file for this to work)
    AppStruct config{};
    if (!loadConfig::load("config.xml", config)) {
        // If loading fails, you might want to use default values
        // or just exit. For now, we'll set some defaults.
        cerr << "Using default configuration." << std::endl;
        config.width = 1920;
        config.height = 1080;
        config.title = "Default OpenGL App";
    }else {
        cerr << "Config loaded successfully." << std::endl;
    }

    // 2. Initialization of variables
    GLFWwindow* window;
    int Width = config.width;
    int Height = config.height;
    string Title = config.title;

    cout << "Height: " << Height << endl;
    cout << "Width: " << Width << endl;
    cout << "Title: " << Title << endl;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(Width ,Height ,Title.c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    if (!loadWindowIcon(window, "src/assets/icon.png")) {
        std::cerr << "Icon load failed, using default" << std::endl;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetWindowTitle(window, Title.c_str());
    glfwSwapInterval(1);

	color gb_Color = { 1.0f, 1.0f, 0.0f, 1.0f };

    glClearColor(gb_Color.red, gb_Color.green, gb_Color.blue, gb_Color.alpha);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Display Part*/
	

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}
