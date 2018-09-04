#pragma once

#include "IListener.h"
#include "ShaderManager.h"
#include "ModelsManager.h"

namespace Managers
{

	class SceneManager : public Core::IListener
	{
	public:

		SceneManager(std::string fragmentShader, std::string vertexShader);
		~SceneManager();
	
	virtual void notifyBeginFrame();
	virtual void notifyDisplayFrame();
	virtual void notifyEndFrame();
	virtual void notifyReshape(int width,
			int height,
			int previous_width,
			int previous_height);

	private:
		ShaderManager* shaderManager;
		ModelsManager* modelsManager;
	};




}
