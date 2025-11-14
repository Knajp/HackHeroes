#pragma once
#include "Window.hpp"
#include "Renderer.hpp"
#include <memory>
#include "Rect.hpp"

namespace sk
{
	class Application
	{
	public:
		static Application& getInstance();

		void Run();
	private:
		Application() = default;
		
		void initApplication();
	private:
		std::unique_ptr<sk::Window> mWindow;
		sk::Renderer& mRenderer = sk::Renderer::getInstance();
	};
}