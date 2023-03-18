#ifndef RENDER_H
#define RENDER_H

#define PI 3.1415926

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <vector>
#include <string>
#include "shaderProgram.h"
#include "geometryBuffer.h"
#include "mesh.h"
#include "camera.h"
#include "light.h"

struct Light {
    std::vector<DirectionLight> dirLights = {};
    std::vector<PointLight> pointLights = {};
    std::vector<SpotLight> spotLights = {};
};




void createShaderArr();
void createVaoArr();
void init0();
unsigned int getSphere(int ySegments, int xSegments);
unsigned int getCylinder(int segments);
unsigned int getBox();
glm::vec3 colorRgb(int color);
void setLightColor(ShaderProgram shader, int color, std::string lightname);
void setLightPosition(ShaderProgram shader, glm::vec3 position, std::string lightname);
void setLightDirection(ShaderProgram shader, glm::vec3 direction, std::string lightname);
void setLightParameter(ShaderProgram shader, float constant, float linear, float quadratic, std::string lightname);
void setLightRad(ShaderProgram shader, float cutOff, float outerCutOff);
void render(std::vector<Mesh> meshs, Camera camera, Light light);


#endif 