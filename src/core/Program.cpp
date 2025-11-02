#include <glad/glad.h>
#include <core/Program.h>

Program::Program(const Shader& vertexShader, const Shader& fragmentShader)
{
    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, vertexShader.getShader());
    glAttachShader(this->shaderProgram, fragmentShader.getShader());
    glLinkProgram(this->shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }
}

void Program::use()
{
    glUseProgram(this->shaderProgram);
}

void Program::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), (int)value);
}
void Program::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}
void Program::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}

Program::~Program()
{
    glDeleteProgram(this->shaderProgram);
}
