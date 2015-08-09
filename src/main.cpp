
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "Pixels.h"

using namespace std;

int width = 1024;
int height = 800;

void Display()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (EXIT_FAILURE);

	window = glfwCreateWindow(width, height, "CPU Ray Tracing", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return (EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);

	Pixels pixels(width, height);
	pixels.Render();

	while (!glfwWindowShouldClose(window))
	{
		//glViewport(0, 0, width, height);
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels.GetPixels());
		//glFlush();
		//Display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return (EXIT_SUCCESS);
}