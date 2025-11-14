#include "Window.hpp"

static void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0, width, height);

}
sk::Window::Window(uint16_t width, uint16_t height, const std::string name)
	:mWidth(width), mHeight(height), mTitle(name)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	#endif

	pWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(pWindow);
	glfwSetFramebufferSizeCallback(pWindow, framebufferSizeCallback);
}

bool sk::Window::shouldClose()
{
	return glfwWindowShouldClose(pWindow);
}

void sk::Window::pollEvents()
{
	glfwPollEvents();
	glfwSwapBuffers(pWindow);
}

sk::Window::~Window()
{
	glfwDestroyWindow(pWindow);

	glfwTerminate();
}
