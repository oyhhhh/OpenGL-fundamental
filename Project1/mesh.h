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

//物体参数
struct Object {
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f);
	std::string type;

};

//材质参数
struct Material {
	int color = NULL;
	std::vector<const char*> path = {};
	std::string type;
};

//物体类 组合物体几何形状和材质
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

protected:         //由于设置position、size需要额外操作，因此提供函数作为查询接口而隐藏变量
	glm::vec3 position;
	glm::vec3 size;
	std::vector<unsigned int> textureID;
	float radX;
	float radY;
	float radZ;

	void setModel();

};



#endif 

