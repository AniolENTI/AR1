#include <objects/Model.h>

extern bool loadOBJ(
	const char* path,
	std::vector < glm::vec3 >& out_vertices,
	std::vector < glm::vec2 >& out_uvs,
	std::vector < glm::vec3 >& out_normals
);

Model::Model()
{
	loadModel();

	const char* vertShaderFile = "shaders/triangle.vert";
	const char* fragShaderFile = "shaders/triangle.frag";

	program = new Program("Triangle");
	program->compileAndAttachShader(vertShaderFile, GL_VERTEX_SHADER, "vertex");
	program->compileAndAttachShader(fragShaderFile, GL_FRAGMENT_SHADER, "fragment");
	program->link();

	// Create the vertex array object
	// This object maintains the state related to the input of the OpenGL pipeline
	// In this example, the VAO defined will contain all the state related to the
	// below operations for vertex attributes definition.
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Create the vertex buffer object
	// It contains arbitrary data for the vertices. In our case, its coordinates.
	glGenBuffers(1, &VBO);

	// From this point until we bind another buffer, calls related to the
	// array buffer will use VBO.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// For example, copy the data to the array buffer...
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	// ...and specify the layout of the arbitrary data setting the attributes of the vertex buffer
	glVertexAttribPointer(
		0, // Set the location for this attribute to 0 (same that we specified in the shader)
		3, // Size of the vertex attribute. In this case, 3 coordinates x, y, z
		GL_FLOAT,
		GL_FALSE, // Don't normalize the data.
		3 * sizeof(float),  // stride (space between consecutive vertex attributes)
		(void*)0 // offset of where the position data begins in the buffer (in this case 0)
	);

	// Once the attribute is specified, we enable it. The parameter is the location of the attribute
	glEnableVertexAttribArray(0);

	// Not necessary, but recomendable as it ensures that we will not use the VAO accidentally.
	glBindVertexArray(0);


	int index = 0;
	for (int y = -2; y < 2; y += 2)
	{
		for (int x = -5; x < 5; x += 2)
		{
			glm::vec3 translation;
			translation.x = (float)x * 10;
			translation.y = 0.0f;
			translation.z = (float)y * 10;
			translations[index++] = translation;
		}
	}
}

Model::~Model()
{
	delete program;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Model::setTransforms(CameraTransforms cam)
{
	this->cam = cam;
}

void Model::draw()
{
	program->use();
	glBindVertexArray(VAO);

	// Get location of uniforms
	GLuint colorLoc = program->getUniform("aCol");
	GLuint objMatLoc = program->getUniform("objMat");
	GLuint mvpMatLoc = program->getUniform("mvpMat");
	GLuint offsetLoc = program->getUniform("offsets");

	// Declare all the matrices that we will use
	glm::mat4 model, view, objMat;

	// Draw model
	glUniform4f(colorLoc, 0.9f, 0.1f, 0.1f, 1.0f);
	model = glm::rotate(glm::mat4(), glm::radians(rotacio), glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::translate(glm::mat4(), glm::vec3(0.0f + moviment.x, -10.0f, -20.0f + moviment.z));
	objMat = view * model;
	

	glUniform3fv(offsetLoc, 10 , glm::value_ptr(translations[0]));
	glUniformMatrix4fv(objMatLoc, 1, GL_FALSE, glm::value_ptr(objMat));
	glUniformMatrix4fv(mvpMatLoc, 1, GL_FALSE, glm::value_ptr(cam._MVP));
	glDrawArraysInstanced(GL_TRIANGLES, 0, vertices.size(), 10);
		
	if (goForward)
	{
		moviment.x++;
		if (moviment.x >= 25)
		{
			goForward = false;
			goRight = true;
			rotacio = 360.0f;
		}
	}
	else if (goRight)
	{
		moviment.z++;
		if (moviment.z >= 25)
		{
			goRight = false;
			goBackward = true;
			rotacio = 270.0f;
		}
	}
	else if (goBackward)
	{
		moviment.x--;
		if (moviment.x <= -25)
		{
			goBackward = false;
			goLeft = true;
			rotacio = 180.0f;
		}
	}
	else if (goLeft)
	{
		moviment.z--;
		if (moviment.z <= -25)
		{
			goLeft = false;
			goForward = true;
			rotacio = 90.0f;
		}
	}
}

void Model::loadModel()
{
	bool res = loadOBJ(path, vertices, uvs, normals);
}