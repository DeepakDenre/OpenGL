#include<core/Color.h>
#include<iostream>
#include<glad/glad.h>
#include<vector>

Color::Color() : r(1.0f), g(1.0f), b(1.0f), a(1.0f){}

Color::Color(GLfloat R,GLfloat G, GLfloat B, GLfloat A) : r(R), g(G), b(B), a(A){}
Color::Color(int R,int G, int B, int A) : r(R/255.0f), g(G/255.0f), b(B/255.0f), a(A/255.0f){}
Color::Color(std::vector<GLfloat> colors){
    r=colors[0];
    g=colors[1];
    b=colors[2];
    a=colors[3];
}

void Color::setColors(GLfloat R,GLfloat G, GLfloat B, GLfloat A){
    r=R;
    g=G;
    b=B;
    a=A;
}

void Color::setNormalizedColor(int R,int G, int B, int A){
    r=R/255.0f;
    g=G/255.0f;
    b=B/255.0f;
    a=A/255.0f;
}

void Color::setColors(std::vector<GLfloat> colors){
    r=colors[0];
    g=colors[1];
    b=colors[2];
    a=colors[3];
}

std::vector<GLfloat> Color::getColors() const
{
    return {r, g, b, a};
}

GLfloat Color::getR() const { return r; }
GLfloat Color::getG() const { return g; }
GLfloat Color::getB() const { return b; }
GLfloat Color::getA() const { return a; }

void Color::setR(GLfloat R) { r = R; }
void Color::setG(GLfloat G) { g = G; }
void Color::setB(GLfloat B) { b = B; }
void Color::setA(GLfloat A) { a = A; }

void Color::setR(int R) { r = R/255.0f; }
void Color::setG(int G) { g = G/255.0f; }
void Color::setB(int B) { b = B/255.0f; }
void Color::setA(int A) { a = A/255.0f; }


void Color::setBackground(GLfloat R, GLfloat G, GLfloat B, GLfloat A){
    glClearColor(R,G,B,A);
}

void Color::setBackground(int R, int G, int B, int A){
    if(R>255)R=255;
    if(R<0)R=0;
    if(G>255)G=255;
    if(G<0)G=0;
    if(B>255)B=255;
    if(B<0)B=0;
    if(A>255)A=255;
    if(A<0)A=0;
    glClearColor(R/255.0f,G/255.0f,B/255.0f,A/255.0f);
}