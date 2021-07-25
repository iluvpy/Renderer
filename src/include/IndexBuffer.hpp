#pragma once

#pragma once

#include "glad/glad.h"
#include <cstdlib>

class IndexBuffer {

public:
	IndexBuffer();
	IndexBuffer(uint *indices, uint count);
	void bind() const;
	void unbind() const;
	void draw() const;
	inline GLuint getCount() const { return m_count; }
	~IndexBuffer(); 

private:
	GLuint ibo;
	GLuint m_count;
};