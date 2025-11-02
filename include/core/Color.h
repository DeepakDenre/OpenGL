#ifndef COLOR_H
#define COLOR_H

#include<vector>
#include<glad/glad.h>

/**
 * @brief A class that represents an RGBA color.
 *
 * This class encapsulates four floating-point color components (R, G, B, A)
 * and provides methods for setting and retrieving them.
 */
class Color
{
private:
    GLfloat r, g, b, a;

public:
    /**
     * @brief Default constructor that initializes color to black (0,0,0,1).
     */
    Color();

    /**
     * @brief Construct a new Color with given normalized RGBA values.
     *
     * @param R Red component [0.0 - 1.0]
     * @param G Green component [0.0 - 1.0]
     * @param B Blue component [0.0 - 1.0]
     * @param A Alpha (opacity) [0.0 - 1.0]
     */
    Color(GLfloat R, GLfloat G, GLfloat B, GLfloat A);

    /**
     * @brief Construct a new Color with given RGBA values.
     *
     * @param R Red component [0 - 255]
     * @param G Green component [0 - 255]
     * @param B Blue component [0 - 255]
     * @param A Alpha (opacity) [0 - 255]
     */
    Color(int R, int G, int B, int A);

    /**
     * @brief Construct a new Color with given vector or colors.
     *
     * @param colors Red vector<GLfloat> \
     */
    Color(std::vector<GLfloat> colors);

    /**
     * @brief method to set Colors with given normalized RGBA values.
     *
     * @param R Red component [0.0 - 1.0]
     * @param G Green component [0.0 - 1.0]
     * @param B Blue component [0.0 - 1.0]
     * @param A Alpha (opacity) [0.0 - 1.0]
     */
    void setColors(GLfloat R, GLfloat G, GLfloat B, GLfloat A);


    /**
     * @brief method to set Color with given vector or colors.
     *
     * @param colors Red vector<GLfloat> \
     */
    void setColors(std::vector<GLfloat> colors);

    /**
     * @brief method to set Colors with given RGBA values.
     *
     * @param R Red component [0 - 255]
     * @param G Green component [0 - 255]
     * @param B Blue component [0 - 255]
     * @param A Alpha (opacity) [0 - 255]
     */
    void setNormalizedColor(int R, int G, int B, int A);

    /**
     * @brief Get all color components as a vector of normalized Glfloat values.
     * @return std::vector<GLfloat> {R, G, B, A}
     */
    std::vector<GLfloat> getColors() const;

    /**
     * @brief Get normalized Value or R.
     * @return GLfloat R
     */
    GLfloat getR() const;

    /**
     * @brief Get normalized Value or G.
     * @return GLfloat G
     */
    GLfloat getG() const;

    /**
     * @brief Get normalized Value or B.
     * @return GLfloat B
     */
    GLfloat getB() const;

    /**
     * @brief Get normalized Value or A.
     * @return GLfloat A
     */
    GLfloat getA() const;

    
    /**
     * @brief Set normalized Value or R.
     */
    void setR(GLfloat R);
    
    /**
     * @brief Set normalized Value or G.
     */
    void setG(GLfloat G);
    
    /**
     * @brief Set normalized Value or B.
     */
    void setB(GLfloat B);
    
    /**
     * @brief Set normalized Value or A.
     */
    void setA(GLfloat A);
    
    /**
     * @brief Set Value or R.
     */
    void setR(int R);
    
    /**
     * @brief Set Value or G.
     */
    void setG(int G);
    
    /**
     * @brief Set Value or B.
     */
    void setB(int B);
    
    /**
     * @brief Set Value or A.
     */
    void setA(int A);


    /**
     * @brief set background Color
     */
    static void setBackground(GLfloat R, GLfloat G, GLfloat B, GLfloat A);


    /**
     * @brief set background Color
     */
    static void setBackground(int R, int G, int B, int A);
};

#endif