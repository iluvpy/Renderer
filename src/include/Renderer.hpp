#pragma once

#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "VertexBuffer.hpp"
#include "Shader.hpp"
#include "Rect.hpp"

class Renderer {
public:

	Renderer(float width, float height);
	void Update(); // draws stored 
	void DrawRect(const Rect& rect);
	void Clear(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	~Renderer();

private:
	VertexBuffer m_buf;
	Shader m_shader;
	std::vector<float> m_data;
	
};