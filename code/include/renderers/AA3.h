#pragma once
#include <renderers/Renderer.h>
#include <objects/TexturePlane.h>
#include <objects/Billboard.h>
#include <objects/Model.h>
#include <stdlib.h>

class AA3 : public Renderer
{
public:
	AA3(int width, int height);
	~AA3();
	void render(float dt) override;

private:
	//TERRA
	TexturePlane* texture;
	glm::vec3 topRight = { 50.0f, -10.75f, -50.0f };
	glm::vec3 topLeft = { -50.0f, -10.75f, -50.0f };
	glm::vec3 botLeft = { -50.0f, -10.75f,  50.0f };
	glm::vec3 botRight = { 50.0f, -10.75f,  50.0f };
	char* path = "textures/gotele.jpg";

	//BILLBOARD
	Billboard* billboard;
	glm::vec3 topRightBillboard = { 0.5f, 0.5f, -1.0f };
	glm::vec3 topLeftBillboard = { -0.5f, 0.5f, -1.0f };
	glm::vec3 botLeftBillboard = { -0.5f, -0.5f, -1.0f };
	glm::vec3 botRightBillboard = { 0.5f, -0.5f, -1.0f };
	char* pathBillboard = "textures/thomas.jpg";
	
	//COTXE
	Model* model;

	//MIRALL
	TexturePlane* mirror;
	GLuint fbo, fbo_tex;
	glm::vec3 topRightMirror = { 10.5f, 10.5f, -50.0f };
	glm::vec3 topLeftMirror = { -10.5f, 10.5f, -50.0f };
	glm::vec3 botLeftMirror = { -10.5f, -10.5f, -50.0f };
	glm::vec3 botRightMirror = { 10.5f, -10.5f, -50.0f };
	char* pathMirror = "textures/gris.jpg";
	int width, height;
	void setupFBO();

	//OPCIONAL: FORMA DOLENTA DE FER MULTIPLES COTXES I PODER CANVIAR
	bool oneCar;
	Model* modelM1;
	Model* modelM2;
	Model* modelM3;
	Model* modelM4;
	Model* modelM5;
	Model* modelM6;
	Model* modelM7;
	Model* modelM8;
	Model* modelM9;
	Model* modelM10;
};