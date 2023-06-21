#include "renderers/AA3.h"

AA3::AA3(int width, int height) : Renderer(width, height)
{
	oneCar = true;
	freeCam = true;

	if(oneCar)
		model = new Model();
	else
	{
		modelM1 = new Model();
		modelM2 = new Model();
		modelM3 = new Model();
		modelM4 = new Model();
		modelM5 = new Model();
		modelM6 = new Model();
		modelM7 = new Model();
		modelM8 = new Model();
		modelM9 = new Model();
		modelM10 = new Model();
	}

	texture = new TexturePlane(topRight, topLeft, botLeft, botRight, path);
	billboard = new Billboard(topRightBillboard, topLeftBillboard, botLeftBillboard, botRightBillboard, pathBillboard);
	mirror = new TexturePlane(topRightMirror, topLeftMirror, botLeftMirror, botRightMirror, pathMirror);
	this->width = width;
	this->height = height;
	setupFBO();
}

AA3::~AA3()
{
	delete texture;
	delete billboard;
	if (oneCar)
		delete model;
	else
	{
		delete modelM1;
		delete modelM2;
		delete modelM3;
		delete modelM4;
		delete modelM5;
		delete modelM6;
		delete modelM7;
		delete modelM8;
		delete modelM9;
		delete modelM10;
	}
}

void AA3::render(float dt)
{
	texture->setTransforms(cam);
	texture->draw();

	billboard->SetTransforms(cam);
	billboard->draw();

	if (oneCar)
	{
		model->setTransforms(cam);
		model->draw();
	}
	else
	{
		modelM1->setTransforms(cam);
		modelM1->draw();

		modelM2->setTransforms(cam);
		modelM2->draw();

		modelM3->setTransforms(cam);
		modelM3->draw();

		modelM4->setTransforms(cam);
		modelM4->draw();

		modelM5->setTransforms(cam);
		modelM5->draw();

		modelM6->setTransforms(cam);
		modelM6->draw();

		modelM7->setTransforms(cam);
		modelM7->draw();

		modelM8->setTransforms(cam);
		modelM8->draw();

		modelM9->setTransforms(cam);
		modelM9->draw();

		modelM10->setTransforms(cam);
		modelM10->draw();
	}
	

	//Render Mirall
	{
		// Setup FBO camera
		CameraTransforms fbCam;
		fbCam._modelView = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 3.f));
		fbCam._projection = glm::perspective(FOV, 1.f, zNear, zFar);
		fbCam._MVP = fbCam._projection * fbCam._modelView;

		// Render in FBO
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		glViewport(0, 0, 800, 800);
		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		// Restore the state
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glViewport(0, 0, width, height);

		// Draw the textured plane with the FBO
		mirror->setTransforms(cam);
		mirror->setTexture(fbo_tex);
		mirror->draw();
	}

	//Camera Segueix el cotxe
	if (!freeCam)
	{
		setPanv1(0.0f - moviment.x);
		setPanv2(7.0f);
		setPanv3(20.0f - moviment.z);

		if (goForward)
		{
			moviment.x++;
			if (moviment.x >= 25)
			{
				goForward = false;
				goRight = true;
			}
		}
		else if (goRight)
		{
			moviment.z++;
			if (moviment.z >= 25)
			{
				goRight = false;
				goBackward = true;
			}
		}
		else if (goBackward)
		{
			moviment.x--;
			if (moviment.x <= -25)
			{
				goBackward = false;
				goLeft = true;
			}
		}
		else if (goLeft)
		{
			moviment.z--;
			if (moviment.z <= -25)
			{
				goLeft = false;
				goForward = true;
			}
		}
	}
}

void AA3::setupFBO()
{
	glGenFramebuffers(1, &fbo);

	GLuint rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 800);  // 24 bits for depth, 8 bits for stencil
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glGenTextures(1, &fbo_tex);
	glBindTexture(GL_TEXTURE_2D, fbo_tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 800, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture2D(
		GL_FRAMEBUFFER,
		GL_COLOR_ATTACHMENT0,  // En quin buffer ho guardem (color, depth, stencil)
		GL_TEXTURE_2D,
		fbo_tex,
		0
	);
	// WARNING: If this part is commented we will not see the model
	 glFramebufferRenderbuffer(
	 	GL_FRAMEBUFFER,
	 	GL_DEPTH_STENCIL_ATTACHMENT,
	 	GL_RENDERBUFFER,
	 	rbo
	 );
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}