#pragma once

#include <vector>
#include "BufferHandler.hpp"

class Renderer {
public:

	Renderer();
	void appendDraw(BufferHandler *handler);
	void draw();
	void clear(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	void update();
	~Renderer();

private:
	std::vector<BufferHandler*> m_buffers;
	
};