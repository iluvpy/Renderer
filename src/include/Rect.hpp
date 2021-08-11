#pragma once

#include <vector>
#include "Color.hpp"

class Rect {
public:
    Rect(float x=0.0f, float y=0.0f, float w=0.0f, float h=0.0f, const Color& color=Color());
    void Init(float x, float y, float w, float h, const Color& color);

    float GetX() const;
    float GetY() const;
    float GetW() const;
    float GetH() const;
    Color GetColor() const;
    void SetX(float x);
    void SetY(float y);
    void SetW(float w);
    void SetH(float h);
    void SetColor(const Color& color);
    std::vector<float> GetAsVertexBufferData() const;
    ~Rect();
private:
    float m_x, m_y, m_w, m_h;
    Color m_color;
};