#include <iostream>
#include <Paradigm.h>

class Sandbox : public Paradigm::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Paradigm::Application* Paradigm::CreateApplication()
{
	return new Sandbox();
}