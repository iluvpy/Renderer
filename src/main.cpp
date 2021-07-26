#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "include/Shader.hpp"
#include "include/VertexBuffer.hpp"
#include "include/Color.hpp"
#include "include/IndexBuffer.hpp"
#include "include/BufferLayout.hpp"

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

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
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
	Shader sh("./shaders/fs.glsl", "./shaders/vs.glsl");
	BufferLayout bl(buffer, ibo, sh);	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		bl.draw();
		
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}