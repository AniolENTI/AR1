#version 330
layout (location = 0) in vec3 aPos;
uniform mat4 objMat;
uniform mat4 mvpMat;

uniform vec3 offsets[10];

void main() {
	vec3 offset = offsets[gl_InstanceID];
	gl_Position = mvpMat * objMat * vec4(aPos + offset, 1.0);
}