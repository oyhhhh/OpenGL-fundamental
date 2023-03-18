#include "shader.h"

Shader::Shader(const char* path, GLenum shaderType)
{
	std::string code;
	std::ifstream shaderFile;

	shaderFile.open(path);
	std::stringstream shaderStream;
	shaderStream << shaderFile.rdbuf();

	code = shaderStream.str();
	const char* shaderCode = code.c_str();

	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


}