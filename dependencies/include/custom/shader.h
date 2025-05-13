
#ifndef SHADER_H
#define SHADER_H
#include <iostream>
#include <string>
class Shader {
    public: 
        Shader();
        ~Shader();
        void linkProgram();
    private:
        unsigned int m_ShaderProgram, m_FragmentShader, m_VertexShader;
        static std::string readShader(const std::string& filename);
};

#endif // !SHADER_H
