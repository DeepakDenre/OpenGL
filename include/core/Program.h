#ifndef PROGRAM_H
#define PROGRAM_H

#include <core/Shader.h>

class Program
{
private:
    int shaderProgram;

public:
    Program(const Shader& vertexShader, const Shader& fragmentShader);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    ~Program();
};

#endif