#include "Window.hpp"

Window::Window(int w, int h, std::string title) 
:  m_window(nullptr), m_w(w), m_h(h), m_isOpen(true)
{
    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(m_w, m_h, title.c_str(), NULL, NULL);
    if (!m_window)
    {	
		std::cout << "could not create glfw window\n";
        m_isOpen = false;
    }

	glfwSwapInterval(1);
	/* Make the window's context current */
    glfwMakeContextCurrent(m_window);

	// load all OpenGL function after creating GL context
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		std::cout << "Error: " << glewGetErrorString(err) << std::endl;
		glfwTerminate();
	}
}

void Window::Update() {
	m_isOpen = !glfwWindowShouldClose(m_window);
	/* Swap front and back buffers */
	glfwSwapBuffers(m_window);

	/* Poll for and process events */
	glfwPollEvents();
}

bool Window::IsOpen() {
	return m_isOpen;
}

int Window::GetWidth() {
	return m_w;
}
int Window::GetHeight() {
	return m_h;
}

Window::~Window() {
	
}
