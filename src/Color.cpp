#include "Color.hpp"

Color::Color(float r, float g, float b)
: m_r(r), m_g(g), m_b(b)
{}


float Color::GetR() const {
    return  m_r/255.0f;
}   

float Color::GetG() const {
    return  m_g/255.0f;
}   

float Color::GetB() const {
    return  m_b/255.0f;
}   

void Color::SetR(float r) {
    m_r = r;
}
void Color::SetG(float g) {
    m_g = g;
}
void Color::SetB(float b) {
    m_b = b;
}

Color::~Color() {

}