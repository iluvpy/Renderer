#pragma once

#include "BufferHandler.hpp"

class Renderer {
public:

	Renderer();
	void Draw(const BufferHandler& handler);
	void Clear();
	void Update();
	~Renderer();

private:
	BufferHandler *layouts;
	uint layout_len;
};