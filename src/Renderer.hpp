#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

namespace sk
{
	class Renderer
	{
	public:
		static sk::Renderer& getInstance();

		void initRenderer();

		void clearFramebuffer();
		void setClearColor(glm::vec3 rgb);

	private:
		Renderer() = default;
	};
}