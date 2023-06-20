#version 330

in vec3 in_Position;
in vec3 in_Normal;

uniform mat4 objMat;
uniform mat4 mvpMat;

out vec3 vert_Normal;

void main() {
	gl_Position = mvpMat * objMat * vec4(in_Position, 1.0);
	vert_Normal = normalize(vec3(mvpMat * objMat * vec4(in_Normal, 0.0)));
}