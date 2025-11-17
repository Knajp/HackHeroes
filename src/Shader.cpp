#include "Shader.hpp"
#include <iostream>
sk::rutils::Shader::~Shader()
{
	glDeleteShader(mID);
}

sk::rutils::Shader::Shader(const char* shaderSource, GLenum type)
{
	mID = glCreateShader(type);
	glShaderSource(mID, 1, &shaderSource, NULL);
	glCompileShader(mID);

}

GLuint sk::rutils::Shader::getID() const
{
	return mID;
}

void sk::rutils::Shader::destroy()
{
	glDeleteShader(mID);
	mID = 0;
}

GLuint sk::rutils::ShaderProgram::getID() const
{
	return mID;
}

void sk::rutils::ShaderProgram::bind() const 
{
	glUseProgram(mID);
}

void sk::rutils::ShaderProgram::unbind()
{
	glUseProgram(0);
}

sk::rutils::ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(mID);
}

sk::rutils::ShaderProgram::ShaderProgram(GLuint vertexShader, GLuint fragmentShader)
{
	mID = glCreateProgram();
	glAttachShader(mID, vertexShader);
	glAttachShader(mID, fragmentShader);
	glLinkProgram(mID);

	int success;
	glGetProgramiv(mID, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(mID, 512, NULL, infoLog);
		std::cout << "Shader link error: " << infoLog << std::endl;
	}
}
