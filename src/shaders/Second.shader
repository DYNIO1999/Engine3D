#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 aColor;

uniform mat4 u_MVP;

out vec3 ourColor;
void main()
{
   gl_Position = u_MVP * position;
   ourColor = aColor;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 ourColor;

void main()
{
   color = vec4(ourColor, 1.0);;
}