#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(const char* title);
    ~Window();

    GLFWwindow* getWindow();
    void processInput();

private:
    const char* m_Title;
    GLFWwindow* m_Window;

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif 
