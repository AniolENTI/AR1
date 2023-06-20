#version 330

layout(triangles) in;
layout(line_strip, max_vertices = 6) out;

in vec3 vert_Normal[];

const float MAGNITUDE = 0.4;

void generateLine(int index)
{
	gl_Position = gl_in[index].gl_Position;
	EmitVertex();
	gl_Position = gl_in[index].gl_Position + vec4(vert_Normal[index], 0.0) * MAGNITUDE;
	EmitVertex();
	EndPrimitive();
}

void main()
{
	for(int i = 0; i < 3; i++)
		generateLine(i);


}