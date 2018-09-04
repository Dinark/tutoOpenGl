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
/*
void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 1.0);

	glBindVertexArray(models->getModelVao("triangle1"));
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}
*/

/*
void init()
{

	glEnable(GL_DEPTH_TEST);

	models = new Models::ModelController();
	models->createTriangleModel("triangle1");

	//load and compile shaders
	Shaders::ShaderManager shaderLoader;
	program = shaderLoader.createProgram("toto",VERTEX_SHADER_FILE,
		FRAGMENT_SHADER_FILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
*/
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
/*
void clearBuffer()
{

	//Demande de Nettoyage du buffer de color et le Z-Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//change le buffer qui est déjà pret avec celui qu'on viens d'effacer
}

void renderScene()
{

	clearBuffer();
	// Clear Color 
	glClearColor(0.2, 0.2, 0.2, 1.0);
	GLuint model = models->getModelVao("triangle");
	//Use the Shader
	glBindVertexArray(model);
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//Swap buffer to an other ready buffers
	glutSwapBuffers();

}

void closeCallback()
{

	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void init()
{
	glEnable(GL_DEPTH_TEST);

	//Creation triangle
	models = new Models::ModelController();
	models->createTriangleModel("triangle");


	//init Program  Shaders
	ShaderManager shaderLoader;
	program = shaderLoader.createProgram(
		VERTEX_SHADER_FILE,
		FRAGMENT_SHADER_FILE
	);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}



int main(int argc, char **argv)
{

	glutInit(&argc, argv);

	//GLUT_DEPTH = Z-BUFFER
	//GLUT_DOUBLE = DOUBLE BUFFERING
	//GLUT_RGBA 255 * 255 * 255 * 255 color values
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);//optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	
	//init librairie glew librairies
	glewInit();
	if (glewIsSupported("GL_VERSION_3_3"))
	{
		std::cout << " GLEW Version is 3.3\n ";
	}
	else
	{
		std::cout << "GLEW 3.3 not supported\n ";
	}


	init();

	// mise en place du callbacks de rendu
	glutDisplayFunc(renderScene);
	// callback de fin
	glutCloseFunc(closeCallback);

	//le Loop principal du render, ou les callbacks sont appelés
	glutMainLoop();


	delete models;
	glDeleteProgram(program);

	return 0;
}

*/