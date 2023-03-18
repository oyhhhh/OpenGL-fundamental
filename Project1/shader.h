#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class Shader
{
public:
	unsigned int shader;
	Shader(const char* path, GLenum shaderType);
};



#endif 
