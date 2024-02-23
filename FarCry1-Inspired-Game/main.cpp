// far cry 1 inspired game
// made from scratch using c++ and opengl

// for today: set up opengl, render models, add textures, add lighting, add shadow
// for tomorrow: add sound, add physics, add skybox, add terrain, 
// some other day: add water, add particles, add ai, add foliage
// add vehicles, add weapons, add multiplayer, add scripting, add cutscenes, add level editor

// render model using assimp
// https://learnopengl.com/Model-Loading/Assimp

// including glad and glfw
#include "libs/glad/include/glad/glad.h"

// including iostream
#include <iostream>

namespace Gio
{
#include "engine/OS/OS.h"
#include "engine/Renderer/Renderer.h"
}

// Now that we put the GLFW stuff into a separate own class, let's do the same with the OpenGL stuff
// We'll put the OpenGL stuff into a separate class called "Renderer"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

// making a window with glfw
int main()
{
	Gio::Window window(800, 600);
	Gio::Renderer renderer;

	glViewport(0, 0, 800, 600);
	// creating the vertex shader
	unsigned int vertexShader = renderer.create_shader(vertexShaderSource, GL_VERTEX_SHADER);
	unsigned int fragmentShader = renderer.create_shader(fragmentShaderSource, GL_FRAGMENT_SHADER);

	// creating the shader program
	unsigned int shader = renderer.shaderProgram(vertexShader, fragmentShader);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	// uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// unbinding the vertex array object
	glBindVertexArray(0);


	// the game loop
	while (!glfwWindowShouldClose(window.glfw_window))
	{
		renderer.update();

		// draw our first triangle
		glUseProgram(shader);
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// glBindVertexArray(0); // no need to unbind it every time 
		
		window.Update();
	}


	return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
/*void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}*/