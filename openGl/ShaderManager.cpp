#include "ShaderManager.h"

#include <fstream>
#include <vector>

#include <exception>

using namespace Managers;

ShaderManager::ShaderManager()
{
}


ShaderManager::~ShaderManager()
{
}



ProgramGL ShaderManager::createProgram(std::string shadername, std::string VSFilePath, std::string FSFilePath)
{
	//lecture et creation VS
	std::string vertexCode = readFile(VSFilePath);
	ShaderGL vertexShader = createShader(GL_VERTEX_SHADER, vertexCode, "Vertex shader");
	
	std::string fragmentCode = readFile(FSFilePath);
	ShaderGL fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentCode, "Fragment shader");

	ProgramGL program = glCreateProgram();

	// Attache les shaders
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	int link_result = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &link_result);
	//check for link errors
	if (link_result == GL_FALSE)
	{

		int info_log_length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> program_log(info_log_length);
		glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
		std::cout << "Shader Loader : LINK ERROR" << std::endl << &program_log[0] << std::endl;
		throw std::string("ERROR PROGRAM GL");
	}

	this->programs[shadername] = program;

	return program;
}

ProgramGL ShaderManager::getShader(std::string name)
{
	return this->programs.at(name);
}

std::string ShaderManager::readFile(std::string fileName)
{
	std::string shaderCode;
	std::ifstream file(fileName.c_str(), std::ios::in);

	if (!file.good())
	{
		std::cout << "Can't read file " << fileName << std::endl;
		std::terminate();
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();
	return shaderCode;
}

ShaderGL ShaderManager::createShader(GLenum shaderType, std::string source, std::string shaderName)
{
	//creation du shader
	ShaderGL shader = glCreateShader(shaderType);

	int compileResult = 0;

	const char* script = source.c_str();
	int size = source.size();

	// mise des sources
	glShaderSource(shader, 1, &script, &size);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		int info_log_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> shader_log(info_log_length);
		glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
		std::cout << "ERROR compiling shader: " << shaderName << std::endl << &shader_log[0] << std::endl;

		throw std::string("ERROR compiling shader");
	}

	return shader;
}
