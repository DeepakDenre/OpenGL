#include <iostream>
#include <vector>
#include <core/Color.h>
#include <core/Vertex.h>

Vertex::Vertex() : posX(0.0f), posY(0.0f), posZ(0.0f), vertexColor(Color()), texCordS(0.0f), texCordT(0.0f) {};
Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z, Color col) : posX(X), posY(Y), posZ(Z), vertexColor(col), texCordS(0.0f), texCordT(0.0f) {};
Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setColors(R, G, B, A);
    texCordS = 0.0f;
    texCordT = 0.0f;
};

Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setNormalizedColor(R, G, B, A);
    texCordS = 0.0f;
    texCordT = 0.0f;
};

Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z) : posX(X), posY(Y), posZ(Z), vertexColor(Color()), texCordS(0.0f), texCordT(0.0f) {};
Vertex::Vertex(Color col) : posX(0.0f), posY(0.0f), posZ(0.0f), vertexColor(col), texCordS(0.0f), texCordT(0.0f) {};

Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z, Color col, GLfloat S, GLfloat T) : posX(X), posY(Y), posZ(Z), vertexColor(col), texCordS(S), texCordT(T) {};
Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A, GLfloat S, GLfloat T)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setColors(R, G, B, A);
    texCordS = S;
    texCordT = T;
};

Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A, GLfloat S, GLfloat T)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setNormalizedColor(R, G, B, A);
    texCordS = S;
    texCordT = T;
};

Vertex::Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat S, GLfloat T) : posX(X), posY(Y), posZ(Z), vertexColor(Color()), texCordS(S), texCordT(T) {};
Vertex::Vertex(Color col, GLfloat S, GLfloat T) : posX(0.0f), posY(0.0f), posZ(0.0f), vertexColor(col), texCordS(S), texCordT(T) {};

void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z, Color col)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setColors(col.getColors());
    texCordS = 0.0f;
    texCordT = 0.0f;
};
void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setColors(R, G, B, A);
    texCordS = 0.0f;
    texCordT = 0.0f;
};

void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setNormalizedColor(R, G, B, A);
    texCordS = 0.0f;
    texCordT = 0.0f;
};

void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setNormalizedColor(0, 0, 0, 0);
    texCordS = 0.0f;
    texCordT = 0.0f;
};
void Vertex::setVertex(Color col)
{
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    vertexColor.setColors(col.getColors());
    texCordS = 0.0f;
    texCordT = 0.0f;
};

void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z, Color col,GLfloat S,GLfloat T)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setColors(col.getColors());
    texCordS = S;
    texCordT = T;
};
void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A,GLfloat S,GLfloat T)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setColors(R, G, B, A);
    texCordS = S;
    texCordT = T;
};

void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A,GLfloat S,GLfloat T)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setNormalizedColor(R, G, B, A);
    texCordS = S;
    texCordT = T;
};

void Vertex::setVertex(GLfloat X, GLfloat Y, GLfloat Z,GLfloat S,GLfloat T)
{
    posX = X;
    posY = Y;
    posZ = Z;
    vertexColor.setNormalizedColor(0, 0, 0, 0);
    texCordS = S;
    texCordT = T;
};
void Vertex::setVertex(Color col,GLfloat S,GLfloat T)
{
    posX = 0.0f;
    posY = 0.0f;
    posZ = 0.0f;
    vertexColor.setColors(col.getColors());
    texCordS = S;
    texCordT = T;
};


std::vector<GLfloat> Vertex::getPositions() const
{
    return {posX, posY, posZ};
}

std::vector<GLfloat> Vertex::getColors() const
{
    return {vertexColor.getR(), vertexColor.getG(), vertexColor.getB(), vertexColor.getA()};
}

std::vector<GLfloat> Vertex::getTextureCordinates() const
{
    return {texCordS,texCordT};
}

std::vector<GLfloat> Vertex::getAllData() const
{
    return {posX, posY, posZ, vertexColor.getR(), vertexColor.getG(), vertexColor.getB(), vertexColor.getA(),texCordS,texCordT};
}