#include "Rect.hpp"


Rect::Rect(float x, float y, float w, float h, const Color& color) {
    Init(x, y, w, h, color);
}
void Rect::Init(float x, float y, float w, float h, const Color& color) {
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    m_color = color;
}


float Rect::GetX() const {
    return m_x;
}
float Rect::GetY() const {
    return m_y;
}
float Rect::GetW() const {
    return m_w;
}
float Rect::GetH() const {
    return m_h;
}
Color Rect::GetColor() const {
    return m_color;
}

void Rect::SetX(float x) {
    m_x = x;
}
void Rect::SetY(float y) { 
    m_y = y;
}
void Rect::SetW(float w) {  
    m_w = w;
}
void Rect::SetH(float h) {
    m_h = h;
}
void Rect::SetColor(const Color& color) {
    m_color = color;
}

std::vector<float> Rect::GetAsVertexBufferData() const {
    std::vector<float> data {
		m_x,        m_y,       m_color.GetR(), m_color.GetG(), m_color.GetB(),
		m_x+m_w,    m_y,       m_color.GetR(), m_color.GetG(), m_color.GetB(),
		m_x, 	    m_y+m_h,   m_color.GetR(), m_color.GetG(), m_color.GetB(),
        
		m_x,        m_y+m_h,   m_color.GetR(), m_color.GetG(), m_color.GetB(),
        m_x+m_w,    m_y+m_h,   m_color.GetR(), m_color.GetG(), m_color.GetB(),
		m_x+m_w,    m_y,       m_color.GetR(), m_color.GetG(), m_color.GetB()
    };
    return data;
}

Rect::~Rect() {

}

