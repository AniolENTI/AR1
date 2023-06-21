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

	glm::vec3 moviment = glm::vec3(1.0f, 0.0f, 1.0f);
	float rotacio = 90.0f;
	bool goForward = true;
	bool goBackward, goLeft, goRight = false;

	std::vector <glm::vec3> vertices;
	std::vector <glm::vec2> uvs;
	std::vector <glm::vec3> normals;
	char* path = "objects/cotxe.obj";

	//instancing
	glm::vec3 translations[10];
};