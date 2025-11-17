#include "Window.hpp"

static void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0, width, height);
}
sk::Window::Window(uint16_t width, uint16_t height, const std::string name)
	:mWidth(width), mHeight(height), mTitle(name)
{
#ifdef DEBUG
	if (glfwInit() == GLFW_TRUE)
		mLogger.info("Initialized GLFW!");
	else
	{
		mLogger.critical("Failed to initalize GLFW!");
		throw std::runtime_error("Failed to init GLFW!");
	}
#else
	glfwInit();
#endif
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		#ifdef DEBUG
		mLogger.debug("Target platform is Apple.");
		#endif
	#endif

	pWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
#ifdef DEBUG
	mLogger.info("Created GLFW window.");
#endif
	glfwMakeContextCurrent(pWindow);
	glfwSetFramebufferSizeCallback(pWindow, framebufferSizeCallback);
#ifdef DEBUG
	mLogger.trace("Finished window creation.");
#endif
}

bool sk::Window::shouldClose()
{
	return glfwWindowShouldClose(pWindow);
}

void sk::Window::pollEvents()
{
#ifdef DEBUG
	mLogger.trace("Polled GLFW events and swapped buffers.");
#endif
	glfwPollEvents();
	glfwSwapBuffers(pWindow);
}

sk::Window::~Window()
{
#ifdef DEBUG
	mLogger.info("Called window RAII destructor.");
#endif
	glfwDestroyWindow(pWindow);
	glfwTerminate();
}
