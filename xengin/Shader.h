#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader
{
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void setVec3(const std::string& name, const glm::vec3& value)const
	{
		glUniform3fv(glGetUniformLocation(ID, name.c_str()),1,&value[0]);
	}
	void setVec4(const std::string& name, const glm::vec4& value)const
	{
		glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}
	void setMat3(const std::string& name, const glm::mat3& mat)const
	{
		glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	void setMat4(const std::string& name, const glm::mat4& mat)const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	void setFloat(const std::string& name, float value)const {
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setInt(const std::string& name, int value)const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

};

