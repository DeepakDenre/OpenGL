#version 330 core

in vec4 vertexColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
    vec4 imageTeture = texture(ourTexture, TexCoord);
    float grey = 0.299 * imageTeture.r + 0.587 * imageTeture.g + 0.114 * imageTeture.b;
    FragColor = imageTeture * vertexColor;
}