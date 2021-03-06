#include <iostream>
#include <filesystem>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.hpp"
#include "VertexBuffer.hpp"
#include "Renderer.hpp"
#include "Triangle.hpp"
#include "Window.hpp"

#define WINDOW_WIDTH 1280.0f
#define WINDOW_HEIGHT 720.0f

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

int main(int argc, char **argv) {

    /* Initialize the includerary */
    if (!glfwInit()) {
		std::cout << "could not init glfw\n";
        return -1;
	}



	

	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Renderer");
	VertexBuffer buffer = Renderer::GenerateRenderingBuffer();
	Shader sh = Renderer::GenerateRenderingShader(&window);
	Renderer renderer(&sh, &buffer);

	Rect r1(100, 100, 100, 100, Color(140, 40, 255));
	float increment = 15.0f;
	float w = 100.0f;
	float h = 100.0f;
	float x = 500.0f;
	float y = 0.0f;

	Triangle tri1(200, 400, 200, 200);
	tri1.SetV1Color(Color(255.0f, 0.0f, 0.0f));
	tri1.SetV2Color(Color(0.0f, 255.0f, 0.0f));
	tri1.SetV3Color(Color(0.0f, 0.0f, 255.0f));

	std::cout << "Opengl Version " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GPU " << glGetString(GL_RENDERER) << std::endl;
	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // wireframe mode

    while (window.IsOpen())
    {
		renderer.Clear(100, 100, 100);	


		for (int i = 0; i+h < WINDOW_HEIGHT; i+=h) {
			renderer.DrawVertex(x+i,   y+i, 	Color(255.0f));
			renderer.DrawVertex(x+i+w, y+i,  	Color(0.0f, 255.0f));
			renderer.DrawVertex(x+i,   y+i+h, 	Color(0.0f, 0.0f, 255.0f));

			renderer.DrawVertex(x+i, 	 y+i+h, Color(0.0f, 0.0f, 255.0f));
			renderer.DrawVertex(x+i+w, y+i+h, Color(255.0f));
			renderer.DrawVertex(x+i+w, y+i,   Color(0.0f, 255.0f));
		}


		renderer.DrawRect(r1);
		r1.GetRectRef().x = r1.GetRect().x+increment;
		if (r1.GetRect().x+r1.GetRect().w > WINDOW_WIDTH || r1.GetRect().x <= 0) {increment = -increment;}
		

		renderer.DrawTriangle(tri1);
		// update renderer 
		renderer.Update();

        window.Update();
    }
	std::cout << "last error: " << glGetError() << std::endl;
    glfwTerminate();
    return 0;
}