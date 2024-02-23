// far cry 1 inspired game
// made from scratch using c++ and opengl

// including glad and glfw
#include "libs/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

// including iostream
#include <iostream>

// making a window with glfw
int main()
{
	// initializing glfw
	glfwInit();
	// setting the version of opengl to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// setting the profile to core
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// creating a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Far Cry 1 Inspired Game", NULL, NULL);
	// checking if the window was created
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// making the window the current context
	glfwMakeContextCurrent(window);
	// initializing glad
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	// setting the viewport
	glViewport(0, 0, 800, 600);
	// the game loop
	while (!glfwWindowShouldClose(window))
	{
		// checking for events
		glfwPollEvents();
		// swapping the buffers
		glfwSwapBuffers(window);
	}
	// terminating glfw
	glfwTerminate();
	return 0;
}