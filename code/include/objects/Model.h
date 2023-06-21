#pragma once
#include <GL/glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <Program.h>
#include <renderers/Renderer.h>
#include <vector>

class Model
{
public:
	Model();
	~Model();
	void setTransforms(CameraTransforms cam);
	void draw();
	void loadModel();
private:
	Program* program;
	GLuint VAO;
	GLuint VBO;
	CameraTransforms cam;

	float moviment = 1.0f;
	float rotacio = 0.0f;

	std::vector <glm::vec3> vertices;
	std::vector <glm::vec2> uvs;
	std::vector <glm::vec3> normals;
	char* path = "objects/cotxe.obj";
};