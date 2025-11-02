#include <core/Shader.h>
#include <vector>
#include <iostream>
#include <fstream>

std::string Shader::readShader(std::string filePath)
{
    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open())
    {
        std::cerr << "Failed to open shader file: " << filePath << std::endl;
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(shaderFile)),
                        std::istreambuf_iterator<char>());
    return content;
}

Shader::Shader(std::string filePath, GLuint shaderType)
{
    std::string shaderSource = Shader::readShader(filePath);
    const char *shaderSourcePinter = shaderSource.c_str();

    this->shader = glCreateShader(shaderType);
    glShaderSource(this->shader, 1, &shaderSourcePinter, NULL);
    glCompileShader(this->shader);
    int success;
    char infoLog[512];
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(this->shader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED for " << filePath << "\n"
                  << infoLog << std::endl;
    }
}

int Shader::getShader() const
{
    return this->shader;
}

Shader::~Shader()
{
    glDeleteShader(this->shader);
}
