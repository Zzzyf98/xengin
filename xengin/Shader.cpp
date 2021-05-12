#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath){
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// ��֤ifstream��������׳��쳣��
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{

		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		// ��ȡstring�ļ���
		std::stringstream vShaderStream, fShaderStream; 
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();
		//ת����������string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

	}
	catch (const std::exception&)
	{
		std::cout << "read file error" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	
	//����Shader
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	//����Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	//��ӡ����
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//Ƭ��Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	//��ӡ����
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::fragment::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//����+ɾ��
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);


	glDeleteShader(vertex);
	glDeleteShader(fragment);

}




void Shader::use() {
	glUseProgram(ID);
}