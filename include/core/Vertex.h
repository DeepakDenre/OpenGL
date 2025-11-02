#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <glad/glad.h>
#include <core/Color.h>

/**
 * @class Vertex
 * @brief Represents a 3D vertex with position (X,Y,Z) and an RGBA color.
 *
 * Vertex stores position as three GLfloats and color as a Color object.
 * Convenient constructors and setters accept both normalized floats (0.0-1.0)
 * and 0-255 integer color values.
 */
class Vertex
{
private:
    GLfloat posX;      ///< X coordinate
    GLfloat posY;      ///< Y coordinate
    GLfloat posZ;      ///< Z coordinate
    Color vertexColor; ///< RGBA color associated with this vertex
    GLfloat texCordS,texCordT;

public:
    /** @brief Default constructor. Initializes position to (0,0,0) and color to black. */
    Vertex();

    /**
     * @brief Construct vertex with position and a Color object.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param col Color object containing normalized RGBA values.
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z, Color col);

    /**
     * @brief Construct vertex with position and normalized RGBA floats.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red component [0.0 - 1.0].
     * @param G Green component [0.0 - 1.0].
     * @param B Blue component [0.0 - 1.0].
     * @param A Alpha (opacity) [0.0 - 1.0].
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A);

    /**
     * @brief Construct vertex with position and 0-255 RGBA unsigned ints.
     *        Values will be normalized (divided by 255.0f) internally.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red component [0 - 255].
     * @param G Green component [0 - 255].
     * @param B Blue component [0 - 255].
     * @param A Alpha (opacity) [0 - 255].
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A);

    /**
     * @brief Construct vertex with position only (color set to black).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z);

    /**
     * @brief Construct vertex with a Color only (position = origin).
     * @param Col Color object.
     */
    Vertex(Color Col);


    /**
     * @brief Construct vertex with position and a Color object.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param col Color object containing normalized RGBA values.
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z, Color col,GLfloat S,GLfloat T);

    /**
     * @brief Construct vertex with position and normalized RGBA floats.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red component [0.0 - 1.0].
     * @param G Green component [0.0 - 1.0].
     * @param B Blue component [0.0 - 1.0].
     * @param A Alpha (opacity) [0.0 - 1.0].
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A,GLfloat S,GLfloat T);

    /**
     * @brief Construct vertex with position and 0-255 RGBA unsigned ints.
     *        Values will be normalized (divided by 255.0f) internally.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red component [0 - 255].
     * @param G Green component [0 - 255].
     * @param B Blue component [0 - 255].
     * @param A Alpha (opacity) [0 - 255].
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A,GLfloat S,GLfloat T);

    /**
     * @brief Construct vertex with position only (color set to black).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     */
    Vertex(GLfloat X, GLfloat Y, GLfloat Z,GLfloat S,GLfloat T);

    /**
     * @brief Construct vertex with a Color only (position = origin).
     * @param Col Color object.
     */
    Vertex(Color Col,GLfloat S,GLfloat T);

    /**
     * @brief Set vertex position and color (Color object).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param col Color object with normalized RGBA.
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z, Color col);

    /**
     * @brief Set vertex position and normalized RGBA floats.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red [0.0 - 1.0].
     * @param G Green [0.0 - 1.0].
     * @param B Blue [0.0 - 1.0].
     * @param A Alpha [0.0 - 1.0].
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A);

    /**
     * @brief Set vertex position and 0-255 RGBA values (values will be normalized).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red [0 - 255].
     * @param G Green [0 - 255].
     * @param B Blue [0 - 255].
     * @param A Alpha [0 - 255].
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A);

    /**
     * @brief Set only the vertex position (color unchanged).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z);

    /**
     * @brief Set only the vertex color (position unchanged).
     * @param Col Color object.
     */
    void setVertex(Color Col);

        /**
     * @brief Set vertex position and color (Color object).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param col Color object with normalized RGBA.
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z, Color col,GLfloat S,GLfloat T);

    /**
     * @brief Set vertex position and normalized RGBA floats.
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red [0.0 - 1.0].
     * @param G Green [0.0 - 1.0].
     * @param B Blue [0.0 - 1.0].
     * @param A Alpha [0.0 - 1.0].
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLfloat R, GLfloat G, GLfloat B, GLfloat A,GLfloat S,GLfloat T);

    /**
     * @brief Set vertex position and 0-255 RGBA values (values will be normalized).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     * @param R Red [0 - 255].
     * @param G Green [0 - 255].
     * @param B Blue [0 - 255].
     * @param A Alpha [0 - 255].
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z, GLuint R, GLuint G, GLuint B, GLuint A,GLfloat S,GLfloat T);

    /**
     * @brief Set only the vertex position (color unchanged).
     * @param X X-coordinate.
     * @param Y Y-coordinate.
     * @param Z Z-coordinate.
     */
    void setVertex(GLfloat X, GLfloat Y, GLfloat Z,GLfloat S,GLfloat T);

    /**
     * @brief Set only the vertex color (position unchanged).
     * @param Col Color object.
     */
    void setVertex(Color Col,GLfloat S,GLfloat T);

    /**
     * @brief Get the vertex position as a 3-element vector.
     * @return std::vector<GLfloat> {X, Y, Z}
     */
    std::vector<GLfloat> getPositions() const;

    /**
     * @brief Get the vertex color as a 4-element vector.
     * @return std::vector<GLfloat> {R, G, B, A}
     */
    std::vector<GLfloat> getColors() const;

    /**
     * @brief Get the vertex color as a 4-element vector.
     * @return std::vector<GLfloat> {R, G, B, A}
     */
    std::vector<GLfloat> getTextureCordinates() const;

    /**
     * @brief Get combined vertex data (position followed by color).
     * @return std::vector<GLfloat> {X, Y, Z, R, G, B, A}
     */
    std::vector<GLfloat> getAllData() const;
};

#endif