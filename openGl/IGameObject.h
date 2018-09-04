#pragma once

#include "Variable.h"
#include <vector>

namespace Rendering
{
	class IGameObject
	{
	public:
		virtual ~IGameObject() = 0;

		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void setProgram(ShaderGL shaderName) = 0;
		virtual void destroy() = 0;

		virtual GLVAO getVao() const = 0;
		virtual const std::vector<GLVBO>& getVbos() const = 0;
	};

	inline IGameObject::~IGameObject()
	{
	}

}



