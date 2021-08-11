#pragma once

#include "VertexBuffer.hpp"
#include "types.hpp"
#include "Shader.hpp"


class BufferHandler {
public:
	BufferHandler();
	BufferHandler(const VertexBuffer& vb, const Shader& sh);
	void Bind() const;
	void Unbind() const;
	void Draw() const;


	inline Shader& GetShader() {return m_shader;}
	~BufferHandler();
private:

	VertexBuffer m_vb;
	Shader m_shader;
};