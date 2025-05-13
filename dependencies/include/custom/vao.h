#ifndef VAO_H
#define VAO_H

#include <GLFW/glfw3.h>
#include <string>

class VAO {
    public:
        VAO(float* vertices, unsigned int size);
        ~VAO();
        void Bind() const;
        void Unbind() const;
    private:
        unsigned int m_VAO;
        unsigned int m_VBO;
};

#endif // !VAO_H
