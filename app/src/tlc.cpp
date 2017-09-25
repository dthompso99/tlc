#ifdef _WIN32
#define APIENTRY __stdcall
#endif

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "tlc.h"


//implement https://github.com/vurtun/nuklear for gui

namespace Centauri {
	TLC::TLC() {

	};
	TLC::~TLC() {

	};

	void TLC::error(std::string err) {
		std::cout <<  err << std::endl;
	}

	void TLC::init() {
		if (!glfwInit()) {
			error("Failed to intialize glfw");
		}
	};

	TLCWindow* TLC::createWindow() {
		return new TLCWindow();
	}

	int TLC::test() {
		GLFWwindow* window;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			glFlush();

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}
}