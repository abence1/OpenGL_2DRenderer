#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <istream>
#include <string>
#ifndef MAIN_H
#define MAIN_H

int main();
void processInput(GLFWwindow *window);
std::string readShader(const std::string& filepath);
void generateVAO(int objectCount);
GLFWwindow* createWindow();
#endif 
