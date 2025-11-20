#include "Application.hpp"
#include "Renderer.hpp"
#include "UserInterface.hpp"
#include "Connection.hpp"

sk::Application& sk::Application::getInstance()
{
    static sk::Application instance;
    return instance;
}

void sk::Application::Run()
{
    initApplication();
    mRenderer.setClearColor({ 0.463f, 0.788f, 0.922f });
    mRenderer.createBasicShaderProgram();

    sk::server::Connection& serverCon = sk::server::Connection::getInstance();

    sk::ui::GUIelement topBar({ -1.0f, 0.7f }, { 2.0f, 0.3f }, sk::ui::COLOUR_LIGHTBLUE);
    topBar.createShadow(sk::ui::COLOUR_LIGHTBLUE, sk::ui::COLOUR_BACKGROUND, 0.05f);

    mRenderer.bindProgram(sk::rutils::PROGRAM_TYPE::BASIC);
    while (!mWindow->shouldClose())
    {
        mRenderer.clearFramebuffer();

        topBar.Draw();

        mWindow->pollEvents();
    }

    mLogger.debug("Farewell.");
}

void sk::Application::initApplication()
{
#ifdef DEBUG
    if (sk::Window::init() == GLFW_TRUE)
        mLogger.info("Initialized GLFW!");
    else
    {
        mLogger.critical("Failed to initalize GLFW!");
        throw std::runtime_error("Failed to init GLFW!");
    }
#else
    sk::Window::init();
#endif
    std::string windowName;
#ifdef DEBUG
    mLogger.debug("Hello, World!");
    windowName = "EduScroll v0.2 DEBUG";
#else
    windowName = "EduScroll v0.2";
#endif
    mWindow = std::make_unique<sk::Window>(sk::Window::getScreenExtent().x / 3, sk::Window::getScreenExtent().y, windowName);
    mRenderer.initRenderer();
    mRenderer.setViewport(0, 0, sk::Window::getScreenExtent().x / 3, sk::Window::getScreenExtent().y);
}
