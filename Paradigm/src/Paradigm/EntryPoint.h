#pragma once


#ifdef PD_PLATFORM_WINDOWS

extern Paradigm::Application* Paradigm::CreateApplication();

int main(int argc, char** argv)
{
	
	Paradigm::Log::Init();
	PD_CORE_WARN("Initialized Core log");
	PD_CLIENT_INFO("Initialized Client log");
	int a = 5;
	PD_CORE_ERROR("TEST VARIABlE Var={0}", a);

	auto app = Paradigm::CreateApplication();
	app->Run();
	delete app;
	return 0;

}

#endif