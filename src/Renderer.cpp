#include "Renderer.hpp"
#include "util.hpp"
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
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
}


void sk::Renderer::clearFramebuffer()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void sk::Renderer::setClearColor(glm::vec3 rgb)
{
	glClearColor(rgb.r, rgb.g, rgb.b, 1.0f);
}

void sk::Renderer::createBasicShaderProgram()
{
	std::string vertexShaderSource = sk::util::readFile("shader/shader.vert");
	std::string fragmentShaderSource = sk::util::readFile("shader/shader.frag");

	sk::rutils::Shader vertexShader(vertexShaderSource.c_str(), GL_VERTEX_SHADER);
	sk::rutils::Shader fragmentShader(fragmentShaderSource.c_str(), GL_FRAGMENT_SHADER);

	mBasicProgram = sk::rutils::ShaderProgram(vertexShader.getID(), fragmentShader.getID());
}

void sk::Renderer::bindProgram(sk::rutils::PROGRAM_TYPE type)
{
	switch (type)
	{
	case sk::rutils::BASIC:
		mBasicProgram.bind();
		break;
	default:
		break;
		// Logger error
	}
}
