#pragma once

#include "BufferLayout.hpp"

class Renderer {
public:

	Renderer();
	void Draw(BufferLayout);
	void Clear();
	void Update();
	~Renderer();

private:
	BufferLayout *layouts;
	uint layout_len;
};