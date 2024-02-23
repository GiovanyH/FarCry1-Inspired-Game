#include <GLFW/glfw3.h>

class Window
{
	unsigned int width;
	unsigned int height;

public:
	GLFWwindow* glfw_window;
	Window(unsigned int w, unsigned int h)
	{
		this->width = w;
		this->height = h;
		// initializing glfw
		glfwInit();
		// setting the version of opengl to 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// setting the profile to core
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// creating a window
		GLFWwindow* window = glfwCreateWindow(width, height, "Far Cry 1 Inspired Game", NULL, NULL);
		// checking if the window was created
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		// making the window the current context
		glfwMakeContextCurrent(window);

		this->glfw_window = window;
	}

	void Update()
	{
		// processing input
		ProcessInput();
		// swapping the buffers
		glfwSwapBuffers(glfw_window);
		// polling for events
		glfwPollEvents();
	}

	void ProcessInput()
	{
		// checking if the escape key was pressed
		if (glfwGetKey(glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			// setting the window should close flag to true
			glfwSetWindowShouldClose(glfw_window, true);
		}
	}

	~Window()
	{
		glfwTerminate();
	}
};