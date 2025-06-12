#include "custom/object.h"


Object::Object(float* vertices, size_t size_v, unsigned int* indicies, size_t size_i) : m_VAO(vertices, size_v, indicies, size_i){
    Shader m_Shader;
}

Object::~Object()
{
    m_VAO.Unbind();
}

