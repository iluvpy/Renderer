#pragma once

#include <vector>
#include "BufferHandler.hpp"

class Renderer {
public:

	Renderer();
	void appendDraw(const BufferHandler& handler);
	void draw();
	void clear(float r=1.0f, float g=1.0f, float b=1.0f, float a=1.0f);
	void update();
	~Renderer();

private:
	std::vector<BufferHandler> m_buffers;
	
};