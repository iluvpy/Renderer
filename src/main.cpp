#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "lib/Shader.hpp"
#include "lib/VertexBuffer.hpp"
#include "lib/Color.hpp"


int main(int argc, char **argv) {
	GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
		std::cout << "could not init glfw\n";
        return -1;
	}


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "Renderer", NULL, NULL);
    if (!window)
    {	
		std::cout << "could not create glfw window\n";
        glfwTerminate();
        return -1;
    }

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	/* Make the window's context current */
    glfwMakeContextCurrent(window);

	// load all OpenGL function after creating GL context
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    	std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
    	return -1;
	}
	
	std::cout << "opengl version " << glGetString(GL_VERSION) << std::endl;
	size_t numVertices = 6;
	float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,

	 0.5f,  0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
	};  

	VertexBuffer buffer(vertices, numVertices);
	Color color(255, 40, 140);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		color.bind();
		buffer.bind();
		buffer.draw();
		color.unbind();
		buffer.unbind();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}