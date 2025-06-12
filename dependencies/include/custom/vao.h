#ifndef VAO_H
#define VAO_H

#include <GLFW/glfw3.h>

class VAO {
    public:
        VAO(float* vertices, unsigned int size_v, unsigned int* indicies, unsigned int size_i);
        ~VAO();
        void Bind() const;
        void Unbind() const;
    private:
        unsigned int m_VAO;
        unsigned int m_VBO;
        unsigned int m_EBO;
};

#endif // !VAO_H
