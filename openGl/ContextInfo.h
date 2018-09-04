#pragma once

namespace Core
{
	struct ContextInfo
	{
		ContextInfo();
		ContextInfo(int major_version,int minor_version,bool core);
		ContextInfo(const ContextInfo &context);

		~ContextInfo();

		int major_version;
		int minor_version;
		bool core;

	};
}
