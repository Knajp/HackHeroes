#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spd/stb_image.h>
#include <glm/glm.hpp>
#include "Logger.hpp"
namespace sk
{
	class Window
	{
	public:
		Window() = default;
		Window(uint16_t width, uint16_t height, const std::string name);

		bool shouldClose();

		void pollEvents();

		static bool init();

		static glm::ivec2 getScreenExtent();

		~Window(); //RAII destructor
	private:
		uint16_t mWidth;
		uint16_t mHeight;

		std::string mTitle;

		GLFWwindow* pWindow;

		sk::debug::Logger mLogger = sk::debug::Logger("Window logger", spdlog::level::debug);
	};
}