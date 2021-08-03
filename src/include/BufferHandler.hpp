#pragma once

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "types.hpp"
#include "Shader.hpp"


class BufferHandler {
public:
	BufferHandler();
	BufferHandler(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& sh);
	void bind() const;
	void unbind() const;
	void draw() const;


	inline Shader& getShader() {return m_shader;}
	~BufferHandler();
private:

	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
};