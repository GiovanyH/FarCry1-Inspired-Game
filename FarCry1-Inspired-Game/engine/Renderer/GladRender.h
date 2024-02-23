#include "libs/glad/include/glad/glad.h"

class Renderer
{
public:
	// function to create a shader
	unsigned int create_shader(const char* shaderSource, GLenum shaderType)
	{
		// creating the shader
		unsigned int shader;
		shader = glCreateShader(shaderType);
		// attaching the shader source to the shader object
		glShaderSource(shader, 1, &shaderSource, NULL);
		// compiling the shader
		glCompileShader(shader);
		// checking if the shader compiled successfully
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		return shader;
	}

	unsigned int shaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
	{
		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();
		// attaching the shaders to the program
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		// linking the program
		glLinkProgram(shaderProgram);

		// checking if the program linked successfully
		int success;
		char infoLog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		}
		// deleting the shaders
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return shaderProgram;
	}

	void update()
	{
		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
};