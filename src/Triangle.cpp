#include "Triangle.hpp"

#include <cmath>
#include "Utils.hpp"

Triangle::Triangle() {

}

Triangle::Triangle(float x, float y, float w, float h, const Color& color) {
    Init(x, y, w, h);
}

void Triangle::Init(float x, float y, float w, float h, const Color& color) {
    m_vertices = {
        x+w/2, y,   m_color.GetR(), m_color.GetG(), m_color.GetB(),
        x,     y+h, m_color.GetR(), m_color.GetG(), m_color.GetB(),
        x+w,   y+h, m_color.GetR(), m_color.GetG(), m_color.GetB() 
    };
    m_color = color;
}

// rotate triangle
void Triangle::Rotate(float degrees) {
    // origin of a 200, 400, 200, 200 triangle
    Point origin = {100, 100}; // middle XXX find a way to calculate the middle
    float radians = -Util::ToRadians(degrees);
    
    // rotate vertex 1
    Point new_pos = Util::Rotate(Point{GetV1X(), GetV1Y()}, origin, radians);
    // SetV1XY(new_pos.x, new_pos.y);

    // rotate vertex 2
    // new_pos = Util::Rotate(Point{GetV2X(), GetV2Y()}, origin, radians);
    // SetV2XY(new_pos.x, new_pos.y);

    // rotate vertex 3
    new_pos = Util::Rotate(Point{GetV3X(), GetV3Y()}, origin, radians);
    SetV3XY(new_pos.x, new_pos.y);

}

void Triangle::SetV1XY(float x, float y) {
    SetV1X(x);
    SetV1Y(y);
}

void Triangle::SetV2XY(float x, float y) {
    SetV2X(x);
    m_vertices[6] = y;
}

void Triangle::SetV3XY(float x, float y) {
    SetV3X(x);
    m_vertices[11] = y; 
}

void Triangle::SetV1Color(const Color& color) {
    m_vertices[2] = color.GetR();
    m_vertices[3] = color.GetG();
    m_vertices[4] = color.GetR();
}

void Triangle::SetV2Color(const Color& color) {
    m_vertices[7] = color.GetR();
    m_vertices[8] = color.GetG();
    m_vertices[9] = color.GetR();
}

void Triangle::SetV3Color(const Color& color) {
    m_vertices[12] = color.GetR();
    m_vertices[13] = color.GetG();
    m_vertices[14] = color.GetR();
}

void Triangle::SetV1X(float x) {
    m_vertices[0] = x;
}

void Triangle::SetV2X(float x) {
    m_vertices[5] = x;
}

void Triangle::SetV3X(float x) {
    m_vertices[10] = x;
}

void Triangle::SetV1Y(float y) {
    m_vertices[1] = y;
}

void Triangle::SetV2Y(float y) {
    m_vertices[6] = y;
}

void Triangle::SetV3Y(float y) {
    m_vertices[11] = y;
}


float Triangle::GetV1X() {
    return m_vertices[0];
}
float Triangle::GetV2X() {
    return m_vertices[5];
}
float Triangle::GetV3X() {
    return m_vertices[10];
}
float Triangle::GetV1Y() {
    return m_vertices[1];
}
float Triangle::GetV2Y() {
    return m_vertices[6];
}
float Triangle::GetV3Y() {
    return m_vertices[11];
}


std::vector<float> Triangle::GetAsVertexBufferData() const {
    return m_vertices;
}
