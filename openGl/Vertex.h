#pragma once

#include "glm/glm.hpp"
#include "Variable.h"
struct Vertex
{
	PositionVector position;
	ColorVector color;

	Vertex(const PositionVector &position,const ColorVector &couleur)
	{
		this->position = position;
		this->color = couleur;
	}
};