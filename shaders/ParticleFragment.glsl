#version 410 core

layout (location=0) out vec4 fragColour;
in vec3 particleColour;
void main()
{

  vec2 circCoord = 2.0 * gl_PointCoord -  1.0;
  if(dot(circCoord,circCoord)>1.0)
  {
    discard;
  }
  fragColour=vec4(particleColour,1);
}