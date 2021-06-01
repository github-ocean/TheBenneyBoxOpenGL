#pragma once
#include <string>
#include <GL/glew.h>

class Shader 
{
public:
	Shader(const std::string& FileName); 
	void Bind();
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADER = 2;
	GLuint m_GLProgram;
	GLuint m_Shader[NUM_SHADER];
};
