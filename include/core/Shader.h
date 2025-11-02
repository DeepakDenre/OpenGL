/**
 * @file Shader.h
 * @brief Defines the Shader class for handling OpenGL shader creation, compilation, and linking.
 *
 * The Shader class provides an abstraction for managing GLSL vertex and fragment shaders.
 * It reads shader source code from files, compiles them, links them into an OpenGL program,
 * and provides utilities to use the shader program during rendering.
 */

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <string>

/**
 * @class Shader
 * @brief Manages OpenGL shader compilation, linking, and usage.
 *
 * This class encapsulates the process of reading, compiling, and linking GLSL shader files.
 * It automatically handles shader program creation and destruction, following RAII principles.
 */
class Shader
{
private:
    /**
     * @brief OpenGL ID for the shader object.
     */
    GLuint shader;

    /**
     * @brief Reads the source code of a shader file from disk.
     * @param filePath Path to the shader source file.
     * @return The contents of the shader file as a string.
     *
     * @note If the file cannot be opened, an empty string is returned and an error is printed to stderr.
     */
    std::string readShader(std::string filePath);

public:

    /**
     * @brief Constructors to setup and prepare shader
     */
    Shader(std::string filePath, GLuint shaderType);

    /**
     * @return shader ID is returned
     */
    int getShader() const;

    /**
     * @brief Destructor that cleans up the shader program resources.
     *
     * Automatically deletes the OpenGL shader program when the Shader object is destroyed.
     */
    ~Shader();
};

#endif // SHADER_H
