#pragma once

#include <string>
#include <iostream>
#include <map>

#include "GL\glew.h"
#include "GL\freeglut.h"
#include "Variable.h"
namespace Managers
{
	class ShaderManager
	{
	public:
		ShaderManager();
		~ShaderManager();


		ProgramGL createProgram(
			std::string shadername,
			std::string VSFilePath,
			std::string FSFilePath);

		ProgramGL getShader(std::string name);

	private:
		std::string readFile(std::string fileName);
		ShaderGL createShader(GLenum shaderType, std::string source, std::string shaderName);

		std::map<std::string, ProgramGL> programs;
	};
}
