#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <cmath>



//ƽ�й��� ��������ɫ�ͷ���
class DirectionLight
{
public:
	int color;
	glm::vec3 direction;

	DirectionLight();
	DirectionLight(int color);
	DirectionLight(int color, glm::vec3(direction));
};

//���Դ�� ��������ɫ��λ�ú�˥������
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

//�۹���� ��������ɫ��λ�á�����˥���������й��
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
