#pragma once

#pragma once

#include "glad/glad.h"

/*
3*3 vertex buffer

*/
#include <cstdlib>
class IndexBuffer {

public:
	IndexBuffer(uint *indices, uint count);
	void bind() const;
	void unbind() const;
	void draw() const;
	GLuint getCount() const;
	~IndexBuffer(); 

private:
	GLuint ibo;
	GLuint m_count;
};