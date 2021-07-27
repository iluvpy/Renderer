#pragma once

#include "Shader.hpp"

class ColorShader {
public:
	ColorShader(float r=255.0f, float g=255.0f, float b=255.0f, float a=255.0f);
	void bind();
	void unbind();
	inline void setR(float _r) { r = _r/255.0f; }
	inline void setG(float _g) { g = _g/255.0f; }
	inline void setB(float _b) { b = _b/255.0f; }
	inline void setA(float _a) { a = _a/255.0f; }
	inline float getR() { return r;}
	inline float getG() { return g;}
	inline float getB() { return b;}
	inline float getA() { return a;}
	~ColorShader();
private:
	Shader m_shader;
	uint m_location;
	float r, g, b, a;
};