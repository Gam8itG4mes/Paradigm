#include "Application.h"

#include "Paradigm/Events/ApplicationEvent.h"
#include "Paradigm/Log.h"


namespace Paradigm {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{

		WindowResizeEvent e(1280, 720);
		PD_CLIENT_TRACE(e.ToString());
		PD_CORE_TRACE(e.ToString());

		while (true);
	}
}