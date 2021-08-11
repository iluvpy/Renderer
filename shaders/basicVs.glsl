#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 u_Proj;
out vec3 v_Color; // vertex color
void main()
{   
    gl_Position = u_Proj * vec4(aPos.x, aPos.y, 1.0, 1.0);
    v_Color = aColor;
}
