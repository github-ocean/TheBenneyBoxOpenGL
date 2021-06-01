#include "Shader.h"
#include "iostream"
#include "fstream"

static void CheckShaderError(GLuint Shader, GLuint flag, bool IsProgram, const std::string& ErrorMessage);
static std::string LoadShader(const std::string& FileName);

Shader::Shader(const std::string& FileName)
{

}

void Shader::Bind()
{
}

Shader::~Shader()
{

}

static std::string LoadShader(const std::string& FileName)
{
	std::ifstream file;
	file.open((FileName).c_str());

	std::string Output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			Output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << FileName << std::endl;
	}
	return Output;
}

static void CheckShaderError(GLuint Shader, GLuint Flag, bool IsProgram, const std::string& ErrorMessage)
{
	GLint Success = 0;
	GLchar Error[1024] = { 0 };

	if (IsProgram)
	{
		glGetProgramiv(Shader, Flag, &Success);
	}
	else
	{
		glGetShaderiv(Shader, Flag, &Success);
	}

	if (Success == GL_FALSE)
	{
		if (IsProgram)
		{
			glGetProgramInfoLog(Shader, sizeof(Error), NULL, Error);
		}
		else
		{
			glGetShaderInfoLog(Shader, sizeof(Error), NULL, Error);
		}
		std::cerr << ErrorMessage << ": " << Error << "'" << std::endl;
	}
}
