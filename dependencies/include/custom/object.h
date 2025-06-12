#ifndef OBJECT_H
#define OBJECT_H

#include "vao.h"
#include "shader.h"

class Object {
    public: 
        Object(float* vertices, size_t size_v, unsigned int* indicies, size_t size_i);
        ~Object();
        virtual void draw() = 0;
    protected: 
        VAO m_VAO;
        Shader m_Shader;
};

#endif // !OBJECT_H
