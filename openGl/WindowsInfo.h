#pragma once

#include <string>

namespace Core
{ 
	struct WindowsInfo
	{
	public:
		WindowsInfo();
		WindowsInfo(std::string name,
			int start_position_x, int start_position_y,
			int width, int height,
			bool is_reshapable);
		WindowsInfo(const WindowsInfo &tocopy);
		~WindowsInfo();

		void operator=(const WindowsInfo &tocopy);

		std::string name;
		int start_pos_x;
		int start_pos_y;
		int width;
		int height;
		bool is_reshapable;

	};
}
