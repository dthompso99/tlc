#include "tlc_window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Centauri {

		TLCWindow::TLCWindow() {
			window = glfwCreateWindow(640, 480, "TLCWindow", NULL, NULL);
		}

		TLCWindow::~TLCWindow() {

		}

		void TLCWindow::loop() {
			glfwMakeContextCurrent(window);
			gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			if (!glfwWindowShouldClose(window)) {
				/* Render here */
				glClear(GL_COLOR_BUFFER_BIT);

				glFlush();

				/* Swap front and back buffers */
				glfwSwapBuffers(window);

				/* Poll for and process events */
				glfwPollEvents();
			}
			else {
				shouldClose = true;
			}
		}

}