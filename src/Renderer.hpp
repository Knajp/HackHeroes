#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "Shader.hpp"
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
	private:
		Renderer() = default;
		
		sk::rutils::ShaderProgram mBasicProgram;
	};
}