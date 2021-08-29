#pragma once

#include <vector>
#include "Color.hpp"
#include "Structs.hpp"

class Rect {
public:
    Rect(float x=0.0f, float y=0.0f, float w=0.0f, float h=0.0f, const Color& color=Color());
    void Init(float x, float y, float w, float h, const Color& color);

    Color GetColor() const;
    Color& GetColorRef();
    void SetColor(const Color& color);
    RectStruct GetRect();
    void SetRect(const RectStruct& rect);
    RectStruct& GetRectRef();
    
    std::vector<float> GetAsVertexBufferData() const;
    ~Rect();
private:
    RectStruct m_rect;
    Color m_color;
};