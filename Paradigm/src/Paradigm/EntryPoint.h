#pragma once


#ifdef PD_PLATFORM_WINDOWS

extern Paradigm::Application* Paradigm::CreateApplication();

int main(int argc, char** argv)
{
	printf("PARADIGM ENGINE\n");
	auto app = Paradigm::CreateApplication();
	app->Run();
	delete app;
	return 0;

}

#endif