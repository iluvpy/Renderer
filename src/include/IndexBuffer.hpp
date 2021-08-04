#pragma once

#pragma once

#include "glad/glad.h"
#include <cstdlib>

class IndexBuffer {

public:
	IndexBuffer();
	IndexBuffer(uint *indices, uint count);
	void Bind() const;
	void Unbind() const;
	void Draw() const;
	inline GLuint GetCount() const { return m_count; }
	~IndexBuffer(); 

private:
	GLuint m_ibo;
	GLuint m_count;
};