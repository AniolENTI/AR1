#pragma once
#include <GL/glew.h>
#include <glm\gtc\type_ptr.hpp>
#include <Program.h>
#include <renderers/Renderer.h>
#include <objects/TexturePlane.h>

class Billboard
{
public:
    Billboard(glm::vec3 topRight, glm::vec3 topLeft, glm::vec3 botLeft, glm::vec3 botRight, char* path);
    ~Billboard();

    void Render();

    void SetTransforms(CameraTransforms cam);

    void SetColorTextureUnit(unsigned int TextureUnit);

private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    GLuint texture;

    Program* program;

    CameraTransforms cam;
};