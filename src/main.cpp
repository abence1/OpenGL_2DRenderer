#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "custom/main.h"

#include "custom/window.h"
#include "custom/triangle.h"
#include "custom/rectangle.h"
/*
float vertices[] = {
    0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  
   -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  
   -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f 
};*/

int vertices_int[] = {
    600, 150, 0, 255, 0, 0,    // (0.5, 0.5) → pixel (600,150), color red
    600, 450, 0, 255, 0, 0,    // (0.5, -0.5) → pixel (600,450), color red
    200, 450, 0, 255, 0, 0,    // (-0.5, -0.5) → pixel (200,450), color red
    200, 150, 0, 255, 0, 0     // (-0.5, 0.5) → pixel (200,150), color red
};

unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

int main()
{
    //create window
    Window win("GLFW Window");
    GLFWwindow* window = win.getWindow();

    int vertexCount = sizeof(vertices_int) / sizeof(int);
    float* vertices = win.pixelToNDC(vertices_int, vertexCount);

    Rectangle rectangle(vertices, sizeof(float) * vertexCount, indices, sizeof(indices));
    delete[] vertices;

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        win.processInput();
        rectangle.draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}

