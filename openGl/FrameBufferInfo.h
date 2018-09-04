#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>

namespace Core
{
	struct FrameBufferInfo
	{

		FrameBufferInfo();
		FrameBufferInfo(bool color, bool depth, bool stencil, bool msaa);
		~FrameBufferInfo();

		unsigned int flags;
		bool msaa;
	};
}

