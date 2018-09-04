#pragma once

#include "FrameBufferInfo.h"
#include "WindowsInfo.h"
#include "ContextInfo.h"

#include "IListener.h"
namespace Core
{
	namespace Init
	{
		struct Argument
		{
			int argc; 
			char **argv;

			Argument(int argc, char** argv)
			{
				this->argc = argc;
				this->argv = argv;
			}
		};

		class GlutInit
		{


		public:
			
			static void init(
				Core::ContextInfo contextInfo,
				Core::WindowsInfo windowsInfo,
				Core::FrameBufferInfo frameBufferInfo);


			static void init(
				Core::ContextInfo contextInfo,
				Core::WindowsInfo windowsInfo,
				Core::FrameBufferInfo frameBufferInfo,Argument &argument);

			static void setListener(Core::IListener*& iListener);

			static void run();
			static void close();

			static void enterFullScreen();
			static void exitFullScreen();

			static void printOpenGLInfo(const Core::WindowsInfo& windowInfo,
				const Core::ContextInfo& context);
		private:
			static void idleCallback(void);
			static void displayCallback(void);
			static void reshapeCallback(int width, int height);
			static void closeCallback();

			static Core::IListener *listener;
			static Core::WindowsInfo windowInfo;

		};
	}
}

