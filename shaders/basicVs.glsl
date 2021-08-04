#version 330 core
layout (location = 0) in vec4 aPos;
uniform mat4 u_Ortho;
void main()
{
    gl_Position = u_Ortho * aPos;
}
