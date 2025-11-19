#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "Shader.hpp"
#include <memory>
#include "Logger.hpp"

namespace sk
{
	namespace rutils
	{
		enum PROGRAM_TYPE
		{
			BASIC
		};
	}
	class Renderer
	{
	public:
		static sk::Renderer& getInstance();

		void initRenderer();

		void clearFramebuffer();
		void setClearColor(glm::vec3 rgb);

		void createBasicShaderProgram();

		void bindProgram(sk::rutils::PROGRAM_TYPE type);
		void setViewport(int x, int y, int w, int h);
	private:
		Renderer() = default;
		
		std::unique_ptr<sk::rutils::ShaderProgram> mBasicShaderProgram;
#ifdef DEBUG
		sk::debug::Logger mLogger = sk::debug::Logger("Render logger", spdlog::level::debug);
#endif
	};
}