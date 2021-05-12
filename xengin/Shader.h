#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>


class Shader
{
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
};

