#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window {
public:
    Window(const char* title);
    ~Window();

    GLFWwindow* getWindow();
    void processInput();
    float* pixelToNDC(int* vertices, unsigned int size);
private:
    const char* m_Title;
    GLFWwindow* m_Window;

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif 
