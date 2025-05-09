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
    
        m_Window = glfwCreateWindow(
            800, 
            600, 
            m_Title, 
            monitor,
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
