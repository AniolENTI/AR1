#include "renderers/AA3.h"

AA3::AA3(int width, int height) : Renderer(width, height)
{
	texture = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
	billboard = new Billboard(topRightBillboard, topLeftBillboard, botLeftBillboard, botRightBillboard, pathBillboard);
}

AA3::~AA3()
{
	delete texture;
	delete billboard;
}

void AA3::render(float dt)
{
	texture->setTransforms(cam);
	texture->draw();

	billboard->SetTransforms(cam);
	billboard->Render();
}