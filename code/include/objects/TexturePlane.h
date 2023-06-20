#pragma once
#include <GL/glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <Program.h>
#include <renderers/Renderer.h>

class TexturePlane
{
public:
	TexturePlane(glm::vec3 topRight, glm::vec3 topLeft, glm::vec3 botLeft, glm::vec3 botRight, char* path);
	~TexturePlane();
	void setTransforms(CameraTransforms cam);
	void draw();
private:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint texture;

	Program* program;

	CameraTransforms cam;
};

