#include "renderers/AA2.h"

AA2::AA2(int width, int height) : Renderer(width, height)
{
	multipleTextures = true;
	explodeCube = false;

	defineTexture1();
	defineTexture2();
	defineTexture3();
	defineTexture4();
	defineTexture5();
	defineTexture6();

	objMat = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -10.0f));
	cubeColor = { 1.0f, 0.3f, 0.6f, 1.0f };
	explodingCube = new Cube();

	topRightBillboard = { 0.5f, 0.5f, -1.0f };
	topLeftBillboard = { -0.5f, 0.5f, -1.0f };
	botLeftBillboard = { -0.5f, -0.5f, -1.0f };
	botRightBillboard = { 0.5f, -0.5f, -1.0f };
	billboard = new Billboard(topRightBillboard, topLeftBillboard, botLeftBillboard, botRightBillboard, "textures/thomas.jpg");
}

AA2::~AA2()
{
	delete tx1;
	delete tx2;
	delete tx3;
	delete tx4;
	delete tx5;
	delete tx6;

	delete explodingCube;

	delete billboard;
}

void AA2::render(float dt)
{
	tx1->setTransforms(cam);
	tx1->draw();

	tx2->setTransforms(cam);
	tx2->draw();

	tx3->setTransforms(cam);
	tx3->draw();

	tx4->setTransforms(cam);
	tx4->draw();

	tx5->setTransforms(cam);
	tx5->draw();

	tx6->setTransforms(cam);
	tx6->draw();

	explodingCube->setTransforms(objMat, cam);
	explodingCube->setColor(cubeColor);
	explodingCube->draw();

	billboard->SetTransforms(cam);
	billboard->draw();
}

#pragma region DefineTextures
void AA2::defineTexture1()
{
	topRight = { 0.5f, 0.5f, 0.0f };
	topLeft = { -0.5f, 0.5f, 0.0f };
	botLeft = { -0.5f, -0.5f, 0.0f };
	botRight = { 0.5f, -0.5f, 0.0f };

	if (multipleTextures)
		path = "textures/doritos.png";
	else
		path = "textures/container.jpg";

	tx1 = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
}
void AA2::defineTexture2()
{
	topRight = { 0.5f, 0.5f, -1.0f };
	topLeft = { -0.5f, 0.5f, -1.0f };
	botLeft = { -0.5f, -0.5f, -1.0f };
	botRight = { 0.5f, -0.5f, -1.0f };

	if (multipleTextures)
		path = "textures/grasa.jpg";
	else
		path = "textures/container.jpg";

	tx2 = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
}
void AA2::defineTexture3()
{
	topRight = { -0.5f, 0.5f, 0.0f };
	topLeft = { -0.5f, 0.5f, -1.0f };
	botLeft = { -0.5f, -0.5f, -1.0f };
	botRight = { -0.5f, -0.5f, 0.0f };

	if (multipleTextures)
		path = "textures/megusta.png";
	else
		path = "textures/container.jpg";

	tx3 = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
}
void AA2::defineTexture4()
{
	topRight = { 0.5f, 0.5f, -1.0f };
	topLeft = { 0.5f, 0.5f, 0.0f };
	botLeft = { 0.5f, -0.5f, 0.0f };
	botRight = { 0.5f, -0.5f, -1.0f };

	if (multipleTextures)
		path = "textures/servicio.jpg";
	else
		path = "textures/container.jpg";

	tx4 = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
}
void AA2::defineTexture5()
{
	topRight = { 0.5f, 0.5f, -1.0f };
	topLeft = { -0.5f, 0.5f, -1.0f };
	botLeft = { -0.5f, 0.5f, 0.0f };
	botRight = { 0.5f, 0.5f, 0.0f };

	if (multipleTextures)
		path = "textures/thomas.jpg";
	else
		path = "textures/container.jpg";

	tx5 = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
}
void AA2::defineTexture6()
{
	topRight = { 0.5f, -0.5f, -1.0f };
	topLeft = { -0.5f, -0.5f, -1.0f };
	botLeft = { -0.5f, -0.5f, 0.0f };
	botRight = { 0.5f, -0.5f, 0.0f };

	if (multipleTextures)
		path = "textures/smol.jpg";
	else
		path = "textures/container.jpg";

	tx6 = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
}
#pragma endregion