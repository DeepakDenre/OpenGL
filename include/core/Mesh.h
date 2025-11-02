/**
 * @file Mesh.h
 * @brief Defines the Mesh class for representing drawable 3D objects in OpenGL.
 */

 #ifndef MESH_H
 #define MESH_H
 
 #include <vector>
 #include <glad/glad.h>
 #include <stb/stb_image.h>
 #include <iostream>
 #include <array>
 #include <string>
 #include <core/Vertex.h>
 #include <core/Color.h>
 
 /**
  * @class Mesh
  * @brief Represents a 3D mesh with vertices, indices, and buffer objects.
  */
 class Mesh
 {
 private:
     GLfloat PosX = 0.3f, PosY = 0.0f, PosZ = 0.0f;
     std::vector<GLfloat> vertexData;
     std::vector<GLuint> indices;
     GLuint VAO = 0, VBO = 0, EBO = 0;
     int imgHeight = 0, imgWidth = 0, nrChannels = 0;
     unsigned char* imageData = nullptr;
     GLuint texture = 0;
 
     /**
      * @brief Print vertex data.
      */
     std::string printVertexData(const std::vector<GLfloat> &vertexData) const;
 
 public:
     Mesh(std::array<GLfloat, 3> Pos, const std::vector<Vertex> &ver, const std::vector<GLuint> &in);
     Mesh(std::array<GLfloat, 3> Pos, const std::vector<Vertex> &ver, const std::vector<GLuint> &in, const std::string &imagePath);
 
     void setVertices(const std::vector<Vertex> &ver);
     void setIndices(const std::vector<GLuint> &in);
     void setup();
     void draw();
     ~Mesh();
 };
 
 #endif // MESH_H
 