#version 410 core

layout(location=0) in vec4 pos;
layout(location=1) in vec3 inColour;
out vec3 particleColour;
uniform mat4 MVP;
void main()
{
  particleColour=inColour;
  gl_Position = MVP * vec4(pos.xyz,1.0);
  gl_PointSize = pos.w;
}