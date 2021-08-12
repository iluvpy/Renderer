#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.hpp"
#include "VertexBuffer.hpp"
#include "Renderer.hpp"

#define WINDOW_WIDTH 1920.0f
#define WINDOW_HEIGHT 1080.0f
#define width WINDOW_WIDTH
#define height WINDOW_HEIGHT

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

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

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

	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // wireframe mode
	

	VertexBuffer buffer = Renderer::GenerateRenderingBuffer();
	Shader sh = Renderer::GenerateRenderingShader(width, height);
	Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, &sh, &buffer);

	Rect r1(100, 100, 100, 100, Color(0, 0, 0));
	float increment = 15.0f;
	float w = 10.0f;
	float h = 10.0f;
	float x = 1920.0f/2.0f-w/2.0f;
	float y = 1080.0f/2.0f-h/2.0f;
    while (!glfwWindowShouldClose(window))
    {
    
		renderer.Clear(100, 100, 100);
		// render stuff here
	
		renderer.DrawVertex(x,   y, 	Color(255.0f));
		renderer.DrawVertex(x+w, y,  	Color(0.0f, 255.0f));
		renderer.DrawVertex(x,   y+h, 	Color(0.0f, 0.0f, 255.0f));

		renderer.DrawVertex(x, 	 y+h, Color(0.0f, 0.0f, 255.0f));
		renderer.DrawVertex(x+w, y+h, Color(255.0f));
		renderer.DrawVertex(x+w, y,   Color(0.0f, 255.0f));

		renderer.DrawRect(r1);
		r1.SetX(r1.GetX()+increment);
		if (r1.GetX()+r1.GetW() > width || r1.GetX() <= 0) {increment = -increment;}


		w += 1.0f;
		h += 1.0f;
		x = 1920.0f/2.0f-w/2.0f;
		y = 1080.0f/2.0f-h/2.0f;

		// update renderer 
		renderer.Update();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
	std::cout << glGetError() << std::endl;
    glfwTerminate();
    return 0;
}