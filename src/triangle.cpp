#include "custom/triangle.h"

Triangle::Triangle(float* vertices, size_t size_v, unsigned int* indicies, size_t size_i) : Object(vertices, size_v, indicies, size_i){}
Triangle::~Triangle(){}
void Triangle::draw() 
{
    m_VAO.Bind();
    m_Shader.linkProgram();
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT,  0);
    m_VAO.Unbind();
    m_Shader.unLinkProgram();
}
