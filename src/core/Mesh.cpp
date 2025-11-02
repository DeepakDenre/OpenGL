#include <stb/stb_image.h>
#include <core/Mesh.h>
#include <utils/Logger.h>
#include <sstream>

Mesh::Mesh(std::array<GLfloat, 3> Pos, const std::vector<Vertex> &ver, const std::vector<GLuint> &in)
{
    vertexData.reserve(ver.size() * 7);
    this->PosX = Pos[0];
    this->PosY = Pos[1];
    this->PosZ = Pos[2];

    for (const Vertex &v : ver)
    {
        auto data = v.getPositions();
        vertexData.push_back(data[0] + PosX);
        vertexData.push_back(data[1] + PosY);
        vertexData.push_back(data[2] + PosZ);
        auto color = v.getColors();
        auto tecCord = v.getTextureCordinates();
        vertexData.insert(vertexData.end(), color.begin(), color.end());
        vertexData.insert(vertexData.end(), tecCord.begin(), tecCord.end());
    }

    Logger::log(LogLevel::LOG_INFO, "Mesh created:\n" + printVertexData(vertexData));
    this->indices = in;
}

Mesh::Mesh(std::array<GLfloat, 3> Pos, const std::vector<Vertex> &ver,
           const std::vector<GLuint> &in, const std::string &imagePath)
    : Mesh(Pos, ver, in)
{
    stbi_set_flip_vertically_on_load(true);
    this->imageData = stbi_load(imagePath.c_str(), &this->imgWidth, &this->imgHeight, &this->nrChannels, 0);
    if (!this->imageData)
        Logger::log(LogLevel::LOG_ERROR, "Failed to load texture at " + imagePath);
}

std::string Mesh::printVertexData(const std::vector<GLfloat> &vertexData) const
{
    constexpr int stride = 9; // 3 position + 4 color + 2 texture
    std::ostringstream oss;

    oss << "Vertex Data (" << vertexData.size() / stride << " vertices):\n";

    for (size_t i = 0; i < vertexData.size(); i += stride)
    {
        oss << "  Vertex " << (i / stride) << ": "
            << "Pos(" << vertexData[i] << ", " << vertexData[i + 1] << ", " << vertexData[i + 2] << ") "
            << "Color(" << vertexData[i + 3] << ", " << vertexData[i + 4] << ", "
            << vertexData[i + 5] << ", " << vertexData[i + 6] << ") "
            << "Tex(" << vertexData[i + 7] << ", " << vertexData[i + 8] << ")\n";
    }

    return oss.str();
}

void Mesh::setVertices(const std::vector<Vertex> &ver)
{
    vertexData.clear();
    vertexData.reserve(ver.size() * 7);
    for (const Vertex &v : ver)
    {
        auto data = v.getPositions();
        vertexData.push_back(data[0] + PosX);
        vertexData.push_back(data[1] + PosY);
        vertexData.push_back(data[2] + PosZ);
        auto color = v.getColors();
        vertexData.insert(vertexData.end(), color.begin(), color.end());
    }
    Logger::log(LogLevel::LOG_INFO, "Mesh vertices updated:\n" + printVertexData(vertexData));
}

void Mesh::setIndices(const std::vector<GLuint> &in)
{
    this->indices = in;
}

void Mesh::setup()
{
    if (VAO == 0)
        glGenVertexArrays(1, &VAO);
    if (VBO == 0)
        glGenBuffers(1, &VBO);
    if (EBO == 0)
        glGenBuffers(1, &EBO);
    if (texture == 0)
        glGenTextures(1, &texture);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (imageData)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(imageData);
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void *)(7 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}

void Mesh::draw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    if (VAO)
        glDeleteVertexArrays(1, &VAO);
    if (VBO)
        glDeleteBuffers(1, &VBO);
    if (EBO)
        glDeleteBuffers(1, &EBO);
}
