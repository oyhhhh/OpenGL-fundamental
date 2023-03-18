#include "shaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath)
{
	Shader vertexShader(vertexPath, GL_VERTEX_SHADER);
	Shader fragmentShader(fragmentPath, GL_FRAGMENT_SHADER);

	unsigned int vShader = vertexShader.shader;
	unsigned int fShader = fragmentShader.shader;

	ID = glCreateProgram();
	glAttachShader(ID, vShader);
	glAttachShader(ID, fShader);
	glLinkProgram(ID);

	int success;
	char infoLog[512];

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);

}

ShaderProgram::ShaderProgram(const ShaderProgram& shader)
{
	ID = shader.ID;
}

void ShaderProgram::setValue(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);

}

void ShaderProgram::setValue(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), int(value));

}

void ShaderProgram::setValue(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);

}

void ShaderProgram::setValue3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setMatrix3(const std::string& name, const glm::mat4& value) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::setMatrix4(const std::string& name, const glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::useProgram()
{
	glUseProgram(ID);
}

void ShaderProgram::deleteProgram()
{
	glDeleteProgram(ID);
}