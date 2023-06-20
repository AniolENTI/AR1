#version 330

layout (location = 0) in vec3 Position;
uniform mat4 ModelView;
uniform mat4 objMat;

void main()
{
    gl_Position = ModelView * objMat * vec4(Position, 1.0);
}