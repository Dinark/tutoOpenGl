#include "FrameBufferInfo.h"

using namespace Core;

FrameBufferInfo::FrameBufferInfo()
{
	flags = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
	msaa = false;

}

FrameBufferInfo::FrameBufferInfo(bool color, bool depth, bool stencil, bool msaa)
{
	//GLUT_DEPTH = Z-BUFFER
	//GLUT_DOUBLE = DOUBLE BUFFERING
	//GLUT_RGBA 255 * 255 * 255 * 255 color values
	if (color)
		flags |= GLUT_RGBA | GLUT_ALPHA;
	if (depth)
		flags |= GLUT_DEPTH;
	if (stencil)
		flags |= GLUT_STENCIL;
	if (msaa)
		flags |= GLUT_MULTISAMPLE;

	this->msaa = msaa;
}


FrameBufferInfo::~FrameBufferInfo()
{
}
