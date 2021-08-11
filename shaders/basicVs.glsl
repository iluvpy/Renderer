#version 330 core

layout (location = 0) in vec4 aPos;
uniform mat4 u_Proj;

void main()
{   
    gl_Position = u_Proj * aPos;
}
