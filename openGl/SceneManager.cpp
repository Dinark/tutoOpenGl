#include "SceneManager.h"

#include "GL\freeglut.h"
#include "Triangle.h"
#include "IGameObject.h"

using namespace Managers;

SceneManager::SceneManager(std::string fragmentShader,
	std::string vertexShader)
{
	this->shaderManager = new ShaderManager();
	modelsManager = new ModelsManager();
	shaderManager->createProgram("Simple", vertexShader, fragmentShader);


	//create Triangle
	Rendering::Models::Triangle*  t = new  Rendering::Models::Triangle();
	t->setProgram(shaderManager->getShader("Simple"));
	t->Create();
	modelsManager->addModel("triangle",dynamic_cast<Rendering::IGameObject*>(t));

}


SceneManager::~SceneManager()
{
	delete this->shaderManager;
	delete this->modelsManager;
}

void Managers::SceneManager::notifyBeginFrame()
{
}

void Managers::SceneManager::notifyDisplayFrame()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	modelsManager->draw();
	
}

void Managers::SceneManager::notifyEndFrame()
{
}

void Managers::SceneManager::notifyReshape(int width, int height, int previous_width, int previous_height)
{
}
