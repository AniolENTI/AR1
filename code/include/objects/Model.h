#pragma once
#include <GL/glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <Program.h>
#include <renderers/Renderer.h>

class Model
{
public:
	Model();
	~Model();
	void setTransforms(CameraTransforms cam);
	void draw();
private:
	Program* program;
	GLuint VAO;
	GLuint VBO;
	CameraTransforms cam;

	float moviment = 1.0f;
	float rotacio = 0.0f;
};