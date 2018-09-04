#include "ContextInfo.h"

using namespace Core;

ContextInfo::ContextInfo()
{
	this->core = true;
	this->major_version = 3;
	this->minor_version = 3;
}

ContextInfo::ContextInfo(int major_version, int minor_version, bool core)
{
	this->core = core;
	this->major_version = major_version;
	this->minor_version = minor_version;
}

ContextInfo::ContextInfo(const ContextInfo & context)
{
	this->core = context.core;
	this->major_version = context.major_version;
	this->minor_version = context.minor_version;
}


ContextInfo::~ContextInfo()
{
}
