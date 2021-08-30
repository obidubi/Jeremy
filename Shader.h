#ifndef SHADER_CLASS
#define SHADER_CLASS

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
	unsigned int shaderProgram;
public:
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	void use();
	void setBool(const char* name, bool value) const;
	void setInt(const char* name, int value) const;
	void setFloat(const char* name, float value) const;
	void setMatrix4(const char* name, float* value) const;
private: 
	unsigned int loadShader(const char* path, int type);
	unsigned int loadProgram(const char* vertexPath, const char* fragmentPath);
};

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) {
	Shader::shaderProgram = loadProgram(vertexShaderPath, fragmentShaderPath);
}

unsigned int Shader::loadShader(const char* path, int type) {
	std::string source;
	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		file.open(path);
		std::stringstream stream;
		stream << file.rdbuf();
		file.close();
		source = stream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}

	const char* shaderCode = source.c_str();

	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED:\n" << path << "\n" << infoLog << std::endl;
		return 0;
	}

	return shader;
}

unsigned int Shader::loadProgram(const char* vertexPath, const char* fragmentPath) {
	unsigned int vertexShader = Shader::loadShader(vertexPath, GL_VERTEX_SHADER);
	unsigned int fragmentShader = Shader::loadShader(fragmentPath, GL_FRAGMENT_SHADER);

	unsigned int program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	int success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return 0;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}

void Shader::use() {
	glUseProgram(Shader::shaderProgram);
}

void Shader::setBool(const char* name, bool value) const {
	unsigned int location = glGetUniformLocation(Shader::shaderProgram, name);
	glUniform1i(location, (int)value);
}

void Shader::setInt(const char* name, int value) const {
	unsigned int location = glGetUniformLocation(Shader::shaderProgram, name);
	glUniform1i(location, value);
}

void Shader::setFloat(const char* name, float value) const {
	unsigned int location = glGetUniformLocation(Shader::shaderProgram, name);
	glUniform1f(location, value);
}

void Shader::setMatrix4(const char* name, float* value) const {
	unsigned int location = glGetUniformLocation(Shader::shaderProgram, name);
	glUniformMatrix4fv(location, 1, GL_FALSE, value);
}
#endif