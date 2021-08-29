#include "Rect.hpp"


Rect::Rect(float x, float y, float w, float h, const Color& color) {
    Init(x, y, w, h, color);
}
void Rect::Init(float x, float y, float w, float h, const Color& color) {
    m_rect = {x, y, w, h};
    m_color = color;
}


Color Rect::GetColor() const {
    return m_color;
}

Color& Rect::GetColorRef() {
    return m_color;
}

void Rect::SetColor(const Color& color) {
    m_color = color;
}

std::vector<float> Rect::GetAsVertexBufferData() const {
    float x, y, w, h;
    x = m_rect.x;
    y = m_rect.y;
    w = m_rect.w;
    h = m_rect.h;
    std::vector<float> data {
		x,      y,       m_color.GetR(), m_color.GetG(), m_color.GetB(),
		x+w,    y,       m_color.GetR(), m_color.GetG(), m_color.GetB(),
		x, 	    y+h,   m_color.GetR(), m_color.GetG(), m_color.GetB(),
        
		x,      y+h,   m_color.GetR(), m_color.GetG(), m_color.GetB(),
        x+w,    y+h,   m_color.GetR(), m_color.GetG(), m_color.GetB(),
		x+w,    y,       m_color.GetR(), m_color.GetG(), m_color.GetB()
    };
    return data;
}

RectStruct Rect::GetRect() {
    return m_rect;
}
void Rect::SetRect(const RectStruct& rect) {
    m_rect = rect;
}

RectStruct& Rect::GetRectRef() {
    return m_rect;
}


Rect::~Rect() {

}

