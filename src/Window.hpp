#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sk
{
	class Window
	{
	public:
		Window() = default;
		Window(uint16_t width, uint16_t height, const std::string name);

		bool shouldClose();

		void pollEvents();


		~Window(); //RAII destructor
	private:
		uint16_t mWidth;
		uint16_t mHeight;

		std::string mTitle;

		GLFWwindow* pWindow;
	};
}