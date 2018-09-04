#include "WindowsInfo.h"

using namespace Core;

WindowsInfo::WindowsInfo()
{

	this->name = "new Windows";
	this->start_pos_x = 500;
	this->start_pos_y = 500;
	this->height = 800;
	this->width = 600;
	this->is_reshapable = true;
}

WindowsInfo::WindowsInfo(std::string name, int start_position_x, int start_position_y, int width, int height, bool is_reshapable)
{
	this->name = name;
	this->start_pos_x = start_position_x;
	this->start_pos_y = start_position_y;
	this->height = height;
	this->width = width;
	this->is_reshapable = is_reshapable;
}

WindowsInfo::WindowsInfo(const WindowsInfo & tocopy)
{
	this->name = tocopy.name;
	this->start_pos_x = tocopy.start_pos_x;
	this->start_pos_y = tocopy.start_pos_y;
	this->height = tocopy.height;
	this->width = tocopy.width;
	this->is_reshapable = tocopy.is_reshapable;
}


WindowsInfo::~WindowsInfo()
{
}

void WindowsInfo::operator=(const WindowsInfo & tocopy)
{
	this->name = tocopy.name;
	this->start_pos_x = tocopy.start_pos_x;
	this->start_pos_y = tocopy.start_pos_y;
	this->height = tocopy.height;
	this->width = tocopy.width;
	this->is_reshapable = tocopy.is_reshapable;
}
