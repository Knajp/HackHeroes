#include "Renderer.hpp"

sk::Renderer& sk::Renderer::getInstance()
{
	static sk::Renderer instance;
	return instance;
}

void sk::Renderer::initRenderer()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to load glad loader!");
	}

	glViewport(0,0,800,800);
}

void sk::Renderer::clearFramebuffer()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void sk::Renderer::setClearColor(glm::vec3 rgb)
{
	glClearColor(rgb.r, rgb.g, rgb.b, 1.0f);
}
