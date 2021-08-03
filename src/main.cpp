#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "Shader.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "BufferHandler.hpp"
#include "Renderer.hpp"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

int main(int argc, char **argv) {
	GLFWwindow* window;

    /* Initialize the includerary */
    if (!glfwInit()) {
		std::cout << "could not init glfw\n";
        return -1;
	}

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "Renderer", glfwGetPrimaryMonitor(), NULL);
    if (!window)
    {	
		std::cout << "could not create glfw window\n";
        glfwTerminate();
        return -1;
    }

	glfwSwapInterval(1);
	/* Make the window's context current */
    glfwMakeContextCurrent(window);

	// load all OpenGL function after creating GL context
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    	std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
    	return -1;
	}
	std::cout << "Opengl Version " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GPU " << glGetString(GL_RENDERER) << std::endl;

	
	uint numVertices = 4;
	float vertices[] = {
    -0.5f, -0.5f, // 0
     0.5f, -0.5f, // 1
     0.5f,  0.5f, // 2
	-0.5f,  0.5f  // 3
	};  

	uint index_count = 6;
	uint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	IndexBuffer ibo(indices, index_count);
	VertexBuffer buffer(vertices, numVertices);

	Shader color(BASIC_FS, BASIC_VS);
	BufferHandler bl(buffer, ibo, color);	

	Renderer renderer;
	renderer.appendDraw(&bl);

	float r = 0.0f;
	float increment = -0.01f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // /* Render here */
		// glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        // glClear(GL_COLOR_BUFFER_BIT);

		// bl.draw();
		if (r >= 1.0f || r <= 0.0f) increment = -increment;
		r += increment;
		bl.getShader().SetUniform4f("u_Color", r, 0.3f, 0.5f, 1.0f);
		renderer.clear(100, 100, 100);
		renderer.draw();
		
		
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}