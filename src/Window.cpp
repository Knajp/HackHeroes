#include "Window.hpp"
#include <spd/stb_image.h>

static void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0, width, height);
}
sk::Window::Window(uint16_t width, uint16_t height, const std::string name)
	:mWidth(width), mHeight(height), mTitle(name)
{
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

	int iwidth, iheight, ichannels;
	unsigned char* pixels = stbi_load("txt/logo.png", &iwidth, &iheight, &ichannels, 4);

#ifdef DEBUG
	if (!pixels)
		mLogger.error("Failed to load app logo!");
	else mLogger.info("Loaded app logo.");
#endif
	GLFWimage image;
	image.width = iwidth;
	image.height = iheight;
	image.pixels = pixels;

	glfwSetWindowIcon(pWindow, 1, &image);

	stbi_image_free(pixels);
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

bool sk::Window::init()
{
	return glfwInit();
}

glm::ivec2 sk::Window::getScreenExtent()
{
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);

	return { videoMode->width, videoMode->height };
}



sk::Window::~Window()
{
#ifdef DEBUG
	mLogger.info("Called window RAII destructor.");
#endif
	glfwDestroyWindow(pWindow);
	glfwTerminate();
}
