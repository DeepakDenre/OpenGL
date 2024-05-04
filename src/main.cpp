#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stdio.h>
using namespace std;

int main(){

    int Width,Height;
    Width = 1920;
    Height = 1080;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(
        Width,
        Height,
        "OpenGL Window",
        NULL,
        NULL
    );
    if(window == NULL){
        printf("Faled to create GLFW Window!");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
    gladLoadGL();

    glViewport(40,40,Width,Height);

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.6f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

        glfwPollEvents();

    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}