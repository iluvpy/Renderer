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

	// float w = 400.0f;
	// float h = 400.0f;
	// float x = width/2.0f-w/2.0f;
	// float y = height/2.0f-h/2.0f;
	// uint numVertices = 30;
	// float vertices[] = {
	// 	x,   y,     1.0f, 0.0f, 0.0f,
	// 	x+w, y,     0.0f, 1.0f, 0.0f, 
	// 	x, 	 y+h, 	0.0f, 0.0f, 1.0f,

	// 	x,   y+h, 	0.0f, 0.0f, 1.0f,
	// 	x+w, y+h, 	1.0f, 0.0f, 0.0f,
	// 	x+w, y,    	0.0f, 1.0f, 0.0f
	// };  


	// glm::mat4 ortho = glm::ortho(0.0f, width, height, 0.0f);

	// VertexBuffer buffer(vertices, numVertices);
	// Shader sh;
	// sh.Init(BASIC_FS, BASIC_VS);
	// sh.SetUniformMatrix4f("u_Proj", ortho);

	Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
	
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
		// draw here
		//renderer.DrawRect(r1);

		// sh.Bind();
		// buffer.Bind();
		// glDrawArrays(GL_TRIANGLES, 0, buffer.GetCount());
		// sh.Unbind();
		// buffer.Unbind();

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