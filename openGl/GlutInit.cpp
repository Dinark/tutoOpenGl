#include "GlutInit.h"

#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include "GlewInit.h"


using namespace Core;
using namespace Core::Init;

Core::IListener *GlutInit::listener = NULL;
Core::WindowsInfo GlutInit::windowInfo;

void Core::Init::GlutInit::init(Core::ContextInfo contextInfo,
	Core::WindowsInfo windowsInfo,
	Core::FrameBufferInfo frameBufferInfo)
{
	Argument argument(1,NULL);
	init(contextInfo, windowsInfo, frameBufferInfo, argument);

}

void Core::Init::GlutInit::init(Core::ContextInfo contextInfo, Core::WindowsInfo windowsInfo, Core::FrameBufferInfo frameBufferInfo, Argument &argument)
{

	glutInit(&argument.argc, argument.argv);
	/*
	GlutInit::windowInfo = windowInfo;
	//GLUT INIT
	glutInit(&argument.argc, argument.argv);


	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.major_version, contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	//WINDOWS GENERATION
	glutInitDisplayMode(frameBufferInfo.flags);
	glutInitWindowPosition(windowsInfo.start_pos_x, windowsInfo.start_pos_y);
	glutInitWindowSize(windowsInfo.width, windowsInfo.height);

	//glutCreateWindow("test");
	glutCreateWindow(windowsInfo.name.c_str());

	std::cout << "GLUT:initialized" << std::endl;
	


	//CALLBACKS
	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	//GLEW init
	GlewInit::init();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//INFO WRITING
	GlutInit::printOpenGLInfo(windowsInfo, contextInfo);
	*/

}

void Core::Init::GlutInit::setListener(Core::IListener *& iListener)
{
	GlutInit::listener = iListener;
}

void Core::Init::GlutInit::run()
{
	std::cout << "GLUT:\t Start Running " << std::endl;
	glutMainLoop();
}

void Core::Init::GlutInit::close()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}


void Core::Init::GlutInit::printOpenGLInfo(const Core::WindowsInfo & windowInfo, const Core::ContextInfo & context)
{
	

	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "******************************************************               ************************" << std::endl;
	std::cout << "GLUT:Initialise" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
	
}

void Core::Init::GlutInit::idleCallback(void)
{
	glutPostRedisplay();
}

void Core::Init::GlutInit::displayCallback(void)
{

	if (!listener)
		return;

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.0, 0.0, 0.5, 1);
	listener->notifyBeginFrame();
	listener->notifyDisplayFrame();
	glutSwapBuffers();

	listener->notifyEndFrame();
}

void Core::Init::GlutInit::reshapeCallback(int width, int height)
{
	if (!windowInfo.is_reshapable)
		return;

	if (!listener)
		return;

	listener->notifyReshape(width, height, windowInfo.width, windowInfo.height);

	windowInfo.width = width;
	windowInfo.height = height;
	//TODO

}

void Core::Init::GlutInit::closeCallback()
{
	close();
}

void Core::Init::GlutInit::enterFullScreen()
{
	glutFullScreen();
}

void Core::Init::GlutInit::exitFullScreen()
{
	glutLeaveFullScreen();
}

