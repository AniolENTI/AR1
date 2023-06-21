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
	glm::vec3 topRightBillboard = { 10.5f, 10.5f, -1.0f };
	glm::vec3 topLeftBillboard = { -10.5f, 10.5f, -1.0f };
	glm::vec3 botLeftBillboard = { -10.5f, -10.5f, -1.0f };
	glm::vec3 botRightBillboard = { 10.5f, -10.5f, -1.0f };
	char* pathBillboard = "textures/thomas.jpg";
	
	//COTXE
	Model* model;
};