#ifndef GEOMETRYBUFFER_H
#define GEOMETRYBUFFER_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;

	Vertex(glm::vec3 _position, glm::vec3 _normal, glm::vec2 _texCoord): position(_position), normal(_normal), texCoord(_texCoord) {}
};

class GeometryBuffer
{
public:
	unsigned int VAO;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	GeometryBuffer(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	void deleteBuffer();

private:
	unsigned int VBO, EBO;
};


#endif // !OBJECT_H

