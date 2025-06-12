#include <glad/glad.h>
#include "custom/window.h"
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window(const char* title) : m_Title(title), m_Window(nullptr)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor); 
    m_Window = glfwCreateWindow(
        mode->width, 
        mode->height, 
        m_Title, 
        NULL,
        NULL
    );

    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    int framebuffer_width, framebuffer_height;
    glfwGetFramebufferSize(m_Window, &framebuffer_width, &framebuffer_height);
    glViewport(0, 0, framebuffer_width, framebuffer_height);
    glfwSetFramebufferSizeCallback(m_Window, Window::framebuffer_size_callback);
}

Window::~Window() {
    if (m_Window) {
        glfwDestroyWindow(m_Window);
    }
    glfwTerminate();
}

GLFWwindow* Window::getWindow()
{
    return m_Window;
}

void Window::processInput()
{
    if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(m_Window, true);
    }
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

float* Window::pixelToNDC(int* vertices, unsigned int size)
{
    if (size % 6 != 0) {
        return nullptr;    
    }
    int width, height;
    glfwGetFramebufferSize(m_Window, &width, &height);
    float* result = new float[size];

    for (int i = 0; i < size; i += 6) {
        float x_ndc = (vertices[i]  / (float)width) * 2.0f - 1.0f; 
        float y_ndc = 1.0f - (vertices[i + 1]  / (float)height) * 2.0f; 
        float z = (float)vertices[i + 2];
        float r = vertices[i + 3] / 255.0f;
        float g = vertices[i + 4] / 255.0f;
        float b = vertices[i + 5] / 255.0f;

        result[i] = x_ndc;
        result[i + 1] = y_ndc;
        result[i + 2] = z;
        result[i + 3] = r;
        result[i + 4] = g;
        result[i + 5] = b;
    }        
    return result;
}
