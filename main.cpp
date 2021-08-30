#include <stdio.h>
#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <map>

#include "Shader.h"
#include "MathUtils.h"

int run();
void processInput(GLFWwindow*);
unsigned int loadShaderProgram();
unsigned int loadVBO(float data[], int location, int dimension);
unsigned int loadVAO(float positions[]);

const char* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 position;\n"
	"void main(){\n"
	"	gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
	"}\n\0";

const char* fragmentShaderSource = "#version 330 core\n"
	"out vec4 fragColor;\n"
	"void main() {\n"
	"	fragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
	"}\n\0";

std::map<unsigned int, std::vector<unsigned int>> vaos;

int main() {

	run();

	return 0;
}

int run() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Mmyes OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//Load shader
	Shader shader = Shader("vertexShader.glsl", "fragmentShader.glsl");

	//Generate triangle and put it in VBO and VAO
	float vertices[] = { -0.5f, -0.5f, 0.0f,
						0.5f, -0.5f, 0.0f,
						0.0f, 0.5f, 0.0f };

	unsigned int vbo;
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glViewport(0, 0, 800, 600);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Vector3 position = {0, 0, 0};
	Vector3 rotation = {0, 0, 0};
	Vector3 scale = {1, 0.5, 1};
	float buffer[16];
	Matrix44 identity = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	Matrix44 transform;

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		rotation.x++;
		createTransformationMatrix(&position, &rotation, &scale, &transform);
		copyToBufferTransposed(&transform, buffer);

		shader.use();
		shader.setMatrix4("transform", buffer);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

unsigned int loadVBO(float data[], int location, int dimension) {
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	glVertexAttribPointer(location, dimension, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return vbo;
}

unsigned int loadVAO(float positions[]) {
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	unsigned int vertexID = loadVBO(positions, 0, 3);
	glBindVertexArray(0);
	vaos.insert(std::pair<unsigned int, std::vector<unsigned int>>(vao, std::vector<unsigned int>(vertexID)));
	return vao;
}

unsigned int loadShaderProgram() {
	//Compile and link shader program
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}