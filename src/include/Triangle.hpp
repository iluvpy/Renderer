#pragma once

#include <vector>
#include "Structs.hpp"
#include "Color.hpp"

class Triangle {
public:
    Triangle();
    Triangle(float x, float y, float w, float h, const Color& color=Color());
    void Init(float x, float y, float w, float h, const Color& color=Color());
    void Rotate(float degrees);
    void SetV1XY(float x, float y);
    void SetV2XY(float x, float y);
    void SetV3XY(float x, float y);
    void SetV1Color(const Color& color);
    void SetV2Color(const Color& color);
    void SetV3Color(const Color& color);
    void SetV1X(float x);
    void SetV2X(float x);
    void SetV3X(float x);
    void SetV1Y(float y);
    void SetV2Y(float y);
    void SetV3Y(float y);

    float GetV1X();
    float GetV2X();
    float GetV3X();
    float GetV1Y();
    float GetV2Y();
    float GetV3Y();

    std::vector<float> GetAsVertexBufferData() const;
private:
    std::vector<float> m_vertices;
    Color m_color;
};