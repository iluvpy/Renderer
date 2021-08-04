#pragma once

#include <vector>
#include "BufferHandler.hpp"

class Renderer {
public:

	Renderer();
	void AppendDraw(BufferHandler *handler);
	void Draw();
	void Clear(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	void Update();
	~Renderer();

private:
	std::vector<BufferHandler*> m_buffers;
	
};