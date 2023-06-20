#pragma once
#include "Renderer.h"
#include <Program.h>

class ExTexture : public Renderer
{
public:
	ExTexture(int width, int height);
	~ExTexture();
protected:
	void render(float dt);
private:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint texture;

	Program* program;
};

