#include "custom/shader.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Shader::Shader() 
{
    std::string vertexShaderCode = readShader("res/shaders/vertex.shader");
    const char* vertexShaderSource = vertexShaderCode.c_str();

    std::string fragmentShaderCode = readShader("res/shaders/fragment.shader");
    const char* fragmentShaderSource = fragmentShaderCode.c_str();

    //vertex shader
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_VertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(m_VertexShader);

    //fragment shader
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_FragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(m_FragmentShader);

}

Shader::~Shader() 
{
    glDeleteProgram(m_ShaderProgram);
}

void Shader::linkProgram()
{
    // shader program 
    m_ShaderProgram = glCreateProgram();
    glAttachShader(m_ShaderProgram, m_VertexShader);
    glAttachShader(m_ShaderProgram, m_FragmentShader);
    glLinkProgram(m_ShaderProgram);
    glUseProgram(m_ShaderProgram);

    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);
}

std::string Shader::readShader(const std::string& filepath)
{
    std::ifstream file(filepath);
    std::string line;

    if (file.is_open())
    {
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
    else {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }
}
