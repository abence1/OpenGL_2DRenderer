#include "custom/rectangle.h"

Rectangle::Rectangle(float* vertices, size_t size_v, unsigned int* indicies, size_t size_i) : Object(vertices, size_v, indicies, size_i){}
Rectangle::~Rectangle(){}

void Rectangle::draw()
{
    m_VAO.Bind();
    m_Shader.linkProgram();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,  0);
    m_VAO.Unbind();
}
