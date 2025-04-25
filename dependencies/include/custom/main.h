#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <istream>
#include <string>
#ifndef MAIN_H
#define MAIN_H

int main();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
std::string readShader(const std::string& filepath);
#endif 
