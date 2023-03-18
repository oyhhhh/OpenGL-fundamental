#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include "shaderProgram.h"
#include "geometryBuffer.h"
#include "texture.h"

//�������
struct Object {
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f);
	std::string type;

};

//���ʲ���
struct Material {
	int color = NULL;
	std::vector<const char*> path = {};
	std::string type;
};

//������ ������弸����״�Ͳ���
class Mesh
{
public:
	int color;
	std::string type;
	std::string mType;
	glm::mat4 model;
	Mesh(Object object, Material material);
	Mesh(const Mesh& mesh);
	void setPosition(float x, float y, float z);
	void setTexture(Material material);
	void rotateX(float rad);
	void rotateY(float rad);
	void rotateZ(float rad);
	void scale(float x, float y, float z);

	glm::vec3 getPosition();
	glm::vec3 getSize();
	std::vector<unsigned int> getTextureID();

protected:         //��������position��size��Ҫ�������������ṩ������Ϊ��ѯ�ӿڶ����ر���
	glm::vec3 position;
	glm::vec3 size;
	std::vector<unsigned int> textureID;
	float radX;
	float radY;
	float radZ;

	void setModel();

};



#endif 

