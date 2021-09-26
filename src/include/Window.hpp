#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
	Window(int w, int h, std::string title);
	bool IsOpen();
	void Update();
	int GetWidth();
	int GetHeight();
	~Window();
private:
	GLFWwindow *m_window;
	int m_w, m_h;
	bool m_isOpen;
};