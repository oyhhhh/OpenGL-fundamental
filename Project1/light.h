#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <cmath>



//平行光类 属性有颜色和方向
class DirectionLight
{
public:
	int color;
	glm::vec3 direction;

	DirectionLight();
	DirectionLight(int color);
	DirectionLight(int color, glm::vec3(direction));
};

//点光源类 属性有颜色、位置和衰减参数
class PointLight
{
public:
	int color;
	glm::vec3 position;
	float constant;
	float linear;
	float quadratic;

	PointLight();
	PointLight(int color);
	PointLight(int color, glm::vec3 position);
	PointLight(int color, glm::vec3 position, float constant, float linear, float quadratic);
};

//聚光灯类 属性有颜色、位置、方向、衰减参数和切光角
class SpotLight
{
public:
	int color;
	glm::vec3 direction;
	glm::vec3 position;
	float constant;
	float linear;
	float quadratic;
	float cutOff;
	float outerCutOff;

	SpotLight();
	SpotLight(int color);
	SpotLight(int color, glm::vec3 direction);
	SpotLight(int color, glm::vec3 direction, glm::vec3 position);
	SpotLight(int color, glm::vec3 direction, glm::vec3 position, float constant, float linear, float quadratic);
	SpotLight(int color, glm::vec3 direction, glm::vec3 position, float constant, float linear, float quadratic, float cutOff, float outerCutOff);

};
#endif
