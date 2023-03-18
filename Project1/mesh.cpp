#include "mesh.h"

Mesh::Mesh(Object object, Material material)
{
	position = object.position;
	size = object.size;
	type = object.type;
	mType = material.type;
	color = material.color;

	for (unsigned int i = 0; i < material.path.size(); i++)
	{
		Texture tex(material.path[i]);
		textureID.push_back(tex.id);
	}

	radX = 0;
	radY = 0;
	radZ = 0;

	setModel();

}

Mesh::Mesh(const Mesh& mesh)
{
	color = mesh.color;
	type = mesh.type;
	mType = mesh.mType;
	model = mesh.model;
	position = mesh.position;
	size = mesh.size;
	textureID = mesh.textureID;
	radX = mesh.radX;
	radY = mesh.radY;
	radZ = mesh.radZ;
}


void Mesh::setPosition(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
	setModel();
}

void Mesh::setTexture(Material material)
{
	textureID.clear();
	for (unsigned int i = 0; i < material.path.size(); i++)
	{
		Texture tex(material.path[i]);
		textureID.push_back(tex.id);
	}
}

void Mesh::rotateX(float rad)
{
	radX = rad;
	setModel();
}

void Mesh::rotateY(float rad)
{
	radY = rad;
	setModel();
}

void Mesh::rotateZ(float rad)
{
	radZ = rad;
	setModel();
}

void Mesh::scale(float x, float y, float z)
{
	size = glm::vec3(x * size.x, y * size.y, z * size.z);
	setModel();
}

void Mesh::setModel()
{
	glm::mat4 smodel = glm::mat4(1.0f);
	glm::mat4 rmodel = glm::mat4(1.0f);
	glm::mat4 tmodel = glm::mat4(1.0f);

	smodel = glm::scale(smodel, size);
	rmodel = glm::rotate(rmodel, glm::radians(radX), glm::vec3(1.0f, 0.0f, 0.0f));
	rmodel = glm::rotate(rmodel, glm::radians(radY), glm::vec3(0.0f, 1.0f, 0.0f));
	rmodel = glm::rotate(rmodel, glm::radians(radZ), glm::vec3(0.0f, 0.0f, 1.0f));
	tmodel = glm::translate(tmodel, position);

	//先放缩再旋转再平移
	model = smodel * rmodel * tmodel;
}

glm::vec3 Mesh::getPosition()
{
	return position;
}

glm::vec3 Mesh::getSize()
{
	return size;
}

std::vector<unsigned int> Mesh::getTextureID()
{
	return textureID;
}


