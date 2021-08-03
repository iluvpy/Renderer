#pragma once

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "ColorShader.hpp"
#include "ShaderHandler.hpp"
#include "types.hpp"


class BufferHandler {
public:
	BufferHandler();
	BufferHandler(const VertexBuffer& vb, const IndexBuffer& ib, const Shader& sh);
	BufferHandler(const VertexBuffer& vb, const IndexBuffer& ib, const ColorShader& sh);
	void bind() const;
	void unbind() const;
	void draw() const;


	template <typename shader_T>
	void setShader(const shader_T& _shader) {
		m_shader.setShader(_shader);
	}

	inline ShaderHandler& getShader() {return m_shader;}
	~BufferHandler();
private:

	VertexBuffer m_vb;
	IndexBuffer m_ib;
	ShaderHandler m_shader;
};