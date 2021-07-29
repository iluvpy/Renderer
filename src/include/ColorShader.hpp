#pragma once

#include "Shader.hpp"

class ColorShader {
public:
	ColorShader(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	void bind() const;
	void unbind() const;
	inline void setR(float _r) { m_r = _r/255.0f; }
	inline void setG(float _g) { m_g = _g/255.0f; }
	inline void setB(float _b) { m_b = _b/255.0f; }
	inline void setA(float _a) { m_a = _a/255.0f; }
	inline float getR() { return m_r;}
	inline float getG() { return m_g;}
	inline float getB() { return m_b;}
	inline float getA() { return m_a;}
	~ColorShader();
private:
	Shader m_shader;
	uint m_location;
	float m_r, m_g, m_b, m_a;
};