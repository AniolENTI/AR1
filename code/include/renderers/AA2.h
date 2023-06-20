#pragma once
#include <renderers/Renderer.h>
#include <objects/TexturePlane.h>
#include <objects/Cube.h>
#include <objects/Billboard.h>
#include <stdlib.h>

class AA2 : public Renderer
{
public:
	AA2(int width, int height);
	~AA2();
	void render(float dt) override;

	void defineTexture1();
	void defineTexture2();
	void defineTexture3();
	void defineTexture4();
	void defineTexture5();
	void defineTexture6();

private:
//TEXTURES
	TexturePlane* tx1; //Front
	TexturePlane* tx2; //Back
	TexturePlane* tx3; //Left
	TexturePlane* tx4; //Right
	TexturePlane* tx5; //Top
	TexturePlane* tx6; //Bottom

	glm::vec3 topRight;
	glm::vec3 topLeft;
	glm::vec3 botLeft;
	glm::vec3 botRight;

	char* path;
	bool multipleTextures;

//CUBE
	Cube* explodingCube;
	
	glm::mat4 objMat;
	glm::vec4 cubeColor;

	bool explodeCube;

//BILLBOARD
	Billboard* billboard;
	glm::vec3 topRightBillboard;
	glm::vec3 topLeftBillboard;
	glm::vec3 botLeftBillboard;
	glm::vec3 botRightBillboard;
};

