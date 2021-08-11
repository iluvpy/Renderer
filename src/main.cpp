#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.hpp"
#include "VertexBuffer.hpp"
#include "BufferHandler.hpp"
#include "Renderer.hpp"

#define WINDOW_WIDTH 1920.0f
#define WINDOW_HEIGHT 1080.0f

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
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Renderer", glfwGetPrimaryMonitor(), NULL);
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


	float x = 10.0f;
	float y = 10.0f;
	float width = 100.0f;
	uint numVertices = 30;
	float vertices[] = {
		x,  	 y,       	1.0f, 0.0f, 0.0f,
		x+width, y,  	  	0.0f, 1.0f, 0.0f, 
		x, 		 y+width, 	0.0f, 0.0f, 1.0f,

		x,  	 y+width, 	0.0f, 0.0f, 1.0f,
		x+width, y+width, 	0.0f, 1.0f, 0.0f,
		x+width, y,    		1.0f, 0.0f, 0.0f
	};  


	VertexBuffer buffer(vertices, numVertices);

	glm::mat4 ortho = glm::ortho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f);

	Shader color(BASIC_FS, BASIC_VS);
	color.SetUniformMatrix4f("u_Proj", ortho);
	BufferHandler bl(buffer, color);	

	Renderer renderer;
	renderer.AppendDraw(&bl);

	// float r = 0.0f;
	// float increment = -0.01f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // /* Render here */
		// glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        // glClear(GL_COLOR_BUFFER_BIT);

		// bl.Draw();
		// if (r >= 1.0f || r <= 0.0f) increment = -increment;
		// r += increment;
		// bl.GetShader().SetUniform4f("u_Color", r, 0.8f, 1.0f, 1.0f);

		renderer.Clear(100, 100, 100);
		renderer.Draw();
		
		
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}