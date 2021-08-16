#pragma once

#include <GL/glew.h>
#include <cstdlib>

class VertexBuffer {

public:
	VertexBuffer();
	VertexBuffer(const void *vertices, uint size);
	void BindNewData(const void *vertices, uint size);
	void Bind() const;
	void Unbind() const;
	void Draw() const;
	uint GetCount() const;
	~VertexBuffer();  

private:

	GLuint m_vbo;
	uint m_size;
};