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
#ifdef DEBUG
		mLogger.critical("Failed to initialize GLAD!");
#endif
		throw std::runtime_error("Failed to load glad loader!");
	}

	glViewport(0,0,800,800);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
}


void sk::Renderer::clearFramebuffer()
{
#ifdef DEBUG
	mLogger.trace("Cleared framebuffer.");
#endif
	glClear(GL_COLOR_BUFFER_BIT);
}

void sk::Renderer::setClearColor(glm::vec3 rgb)
{
#ifdef DEBUG
	std::string rgbString = std::to_string(rgb.r) + " " + std::to_string(rgb.g) + " " + std::to_string(rgb.b);
	std::string fullString = "Clear color set to " + rgbString;
	mLogger.info(fullString.c_str());
#endif
	glClearColor(rgb.r, rgb.g, rgb.b, 1.0f);
}

void sk::Renderer::createBasicShaderProgram()
{
	std::string vertexShaderSource = sk::util::readFile("shader/shader.vert");
	std::string fragmentShaderSource = sk::util::readFile("shader/shader.frag");

	sk::rutils::Shader vertexShader(vertexShaderSource.c_str(), GL_VERTEX_SHADER);
	sk::rutils::Shader fragmentShader(fragmentShaderSource.c_str(), GL_FRAGMENT_SHADER);

	mBasicShaderProgram = std::make_unique<sk::rutils::ShaderProgram>(vertexShader.getID(), fragmentShader.getID());
#ifdef DEBUG
	mLogger.info("Created basic shader program.");
#endif
}

void sk::Renderer::bindProgram(sk::rutils::PROGRAM_TYPE type)
{
	switch (type)
	{
	case sk::rutils::BASIC:
		mBasicShaderProgram->bind();
		mLogger.info("Bound basic program.");
		break;
	default:
		mLogger.warn("Invalid program type passed to sk::Renderer::bindProgram!");
		break;
	}
}
