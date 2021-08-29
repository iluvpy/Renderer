#pragma once

#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "VertexBuffer.hpp"
#include "Shader.hpp"
#include "Rect.hpp"
#include "Triangle.hpp"

class Renderer {
public:

	Renderer(Shader *shader, VertexBuffer *buf);
	void Update(); // draws 
	void DrawRect(const Rect& rect);
	void DrawTriangle(const Triangle& triangle);
	void DrawVertex(float x, float y, const Color& color);
	void Clear(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	static VertexBuffer GenerateRenderingBuffer();
	static Shader GenerateRenderingShader(float window_width, float window_height);
	~Renderer();

private:
	VertexBuffer *m_buf;
	Shader *m_shader;
	std::vector<float> m_data;
};