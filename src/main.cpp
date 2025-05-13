#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "custom/main.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "custom/window.h"
#include "custom/vao.h"
#include "custom/shader.h"


float vertices[] = {
    // First triangle (red)
    -0.9f, -0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 
    0.0f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  
    -0.45f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  
};

int main()
{
    //create window
    Window win("GLFW Window");
    GLFWwindow* window = win.getWindow();

    // setup
    VAO vao(vertices, sizeof(vertices));
    Shader shader;

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        win.processInput();

        // draw
        vao.Bind();
        shader.linkProgram();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        vao.Unbind();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
