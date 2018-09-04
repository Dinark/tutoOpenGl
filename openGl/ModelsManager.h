#pragma once

#include "IGameObject.h"
#include <map>

namespace Managers
{


	class ModelsManager
	{
	public:
		ModelsManager();
		~ModelsManager();

		void draw();
		void update();
		void addModel(const std::string & modelName, Rendering::IGameObject * model);
		void deleteModel(const std::string & modelName);
		const Rendering::IGameObject& getModel(const std::string & modelName) const;

	private:
		std::map<std::string, Rendering::IGameObject*> gameModels;
	};
}

