#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include <GLFW/glfw3.h>


#include "lib/Shader.hpp"
#include "lib/VertexBuffer.hpp"


int main(int argc, char **argv) {
	GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
		std::cout << "could not init glfw\n";
        return -1;
	}


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(920, 780, "Renderer", NULL, NULL);
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
	
	float vertices[] = {
     -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
	};  

	VertexBuffer buffer(vertices);
	Shader orange("./shaders/fragmentShader.glsl", "./shaders/vertexShader.glsl");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		orange.bind();
		buffer.bind();
		buffer.draw();
		buffer.unbind();
		orange.unbind();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}