#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "custom/main.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "custom/window.h"

std::string vertexShaderCode = readShader("res/shaders/vertex.shader");
const char* vertexShaderSource = vertexShaderCode.c_str();

std::string fragmentShaderCode = readShader("res/shaders/fragment.shader");
const char* fragmentShaderSource = fragmentShaderCode.c_str();

std::vector<unsigned int> VAO;
std::vector<unsigned int> VBO;



float vertices[] = {
    // First triangle (red)
    -0.9f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 
    0.0f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  
    -0.45f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  

    // Second triangle (green)
     0.0f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  
     0.9f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 
     0.45f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
     
     // Third triangle (blue)
     0.0f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  
     -0.45f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 
     0.45f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   
};

int main()
{
    //create window
    Window win("GLFW Window");
    GLFWwindow* window = win.getWindow();

    // setup
    int objectCount = sizeof(vertices) / (6 * 3 * sizeof(float));
    generateVAO(objectCount);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        win.processInput();

        // draw
        for (int i = 0; i < objectCount; i++)
        {
            glBindVertexArray(VAO[i]);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // cleanup
    glDeleteVertexArrays(VAO.size(), VAO.data());
    glDeleteBuffers(VBO.size(), VBO.data());
    
    return 0;
}

std::string readShader(const std::string& filepath)
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

void generateVAO(int objectCount)
{
    VAO.resize(objectCount);
    VBO.resize(objectCount);

    glGenVertexArrays(objectCount, VAO.data());
    glGenBuffers(objectCount, VBO.data());

    //vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // shader program 
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    for (int i = 0; i < objectCount; i++)
    {
        glBindVertexArray(VAO[i]);

        //data buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) / objectCount, vertices + i * 18, GL_STATIC_DRAW);

        // vertex arrays
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }
    
}
