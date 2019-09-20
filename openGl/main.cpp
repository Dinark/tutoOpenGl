#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "ShaderManager.h"
#include "Model.h"
#include "main.h"

//CORE
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowsInfo.h"
#include "IListener.h"

#include "GlutInit.h"

//Manager
#include "ShaderManager.h"
#include "SceneManager.h"

namespace
{
	const char* FRAGMENT_SHADER_FILE = "Shaders/FS.glsl";
	const char* VERTEX_SHADER_FILE   = "Shaders/VS.glsl";

	Rendering::Models::ModelController * models;
	ProgramGL program = 0;	
}
int main(int argc, char **argv)
{

	Core::Init::Argument args(argc, argv);

	Core::WindowsInfo window(std::string("Tutorial"),
		400, 200,//position
		800, 600, //size
		false);//reshape

	Core::ContextInfo context(3, 3, true);
	Core::FrameBufferInfo frameBufferInfo(true, true, true, true);
	
	Core::Init::GlutInit::init(context, window, frameBufferInfo, args);

	Core::IListener *scene = new Managers::SceneManager(
		FRAGMENT_SHADER_FILE, VERTEX_SHADER_FILE);

	Core::Init::GlutInit::setListener(scene);

	Core::Init::GlutInit::run();



	//init();
	// register callbacks
	

	
	//delete models;
	//glDeleteProgram(program);

	delete scene;
	return 0;
}