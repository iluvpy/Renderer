#pragma once

class Color {
public:
    Color(float r=0.0f, float g=0.0f, float b=0.0f);
    float GetR() const;    
    float GetG() const;    
    float GetB() const;    
    void SetR(float r);
    void SetG(float g);
    void SetB(float b);
    ~Color();

private:
    float m_r, m_g, m_b;
};