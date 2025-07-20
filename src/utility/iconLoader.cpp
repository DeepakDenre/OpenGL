//
// Created by denre on 20-07-2025.
//

#define STB_IMAGE_IMPLEMENTATION
#include "utility/iconLoader.h"
#include "stb/stb_image.h"
#include <iostream>

bool loadWindowIcon(GLFWwindow* window, const char* iconPath) {
    int width, height, channels;
    unsigned char* pixels = stbi_load(iconPath, &width, &height, &channels, 4);

    if (!pixels) {
        std::cerr << "Failed to load icon: " << iconPath << std::endl;
        return false;
    }

    GLFWimage icon;
    icon.width = width;
    icon.height = height;
    icon.pixels = pixels;

    glfwSetWindowIcon(window, 1, &icon);

    stbi_image_free(pixels);
    return true;
}
