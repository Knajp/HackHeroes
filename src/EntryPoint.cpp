#include "Application.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	sk::Application& app = sk::Application::getInstance();
	try
	{
		app.Run();
	}catch(std::runtime_error e) {std::cout << "Exception thrown: " << e.what() << std::endl; return -1;}

	return 0;
}
