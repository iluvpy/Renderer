#pragma once

#include "glad/glad.h"
#include <cstdlib>

class VertexBuffer {

public:
	VertexBuffer();
	VertexBuffer(const void *vertices, uint numVertices);
	void Init(const void *vertices, uint numVertices);
	void BindNewData(const void *vertices, uint numVertices);
	void Bind() const;
	void Unbind() const;
	void Draw() const;
	uint GetCount() const;
	~VertexBuffer();  

private:

	GLuint m_vbo;
	uint m_numVertices;

};