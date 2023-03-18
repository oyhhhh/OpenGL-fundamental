#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include "shader.h"

class ShaderProgram
{
public:
	unsigned int ID;
	ShaderProgram(const char* vertexPath, const char* fragmentPath);
	ShaderProgram(const ShaderProgram& shader);
	void useProgram();
	void deleteProgram();
	void setValue(const std::string& name, int value) const;
	void setValue(const std::string& name, float value) const;
	void setValue(const std::string& name, bool value) const;
	void setValue3(const std::string& name, const glm::vec3& value) const;
	void setMatrix3(const std::string& name, const glm::mat4& value) const;
	void setMatrix4(const std::string& name, const glm::mat4& value) const;
};





#endif // !SHADERPROGRAM_H

