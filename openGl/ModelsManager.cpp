#include "ModelsManager.h"

using namespace Managers;

ModelsManager::ModelsManager()
{
}


ModelsManager::~ModelsManager()
{
	for (auto model : this->gameModels)
	{
		delete model.second;

	}
	gameModels.clear();
}

void Managers::ModelsManager::draw()
{
	for (auto model : gameModels)
	{
		model.second->draw();
	}
}

void Managers::ModelsManager::update()
{
	for (auto model : gameModels)
	{
		model.second->update();
	}
}

void Managers::ModelsManager::addModel(const std::string & modelName, Rendering::IGameObject * model)
{
	this->gameModels[modelName] = model;
}

void Managers::ModelsManager::deleteModel(const std::string & modelName)
{
	Rendering::IGameObject* model = this->gameModels[modelName];
	delete model;
	gameModels.erase(modelName);


}

const Rendering::IGameObject & Managers::ModelsManager::getModel(const std::string & modelName) const
{
	return (*gameModels.at(modelName));
}
