#include "Application.hpp"

sk::Application& sk::Application::getInstance()
{
    static sk::Application instance;
    return instance;
}

void sk::Application::Run()
{
    initApplication();
    mRenderer.setClearColor({ 0.463f, 0.788f, 0.922f });

    while (!mWindow->shouldClose())
    {
        mRenderer.clearFramebuffer();

        mWindow->pollEvents();
    }
}

void sk::Application::initApplication()
{
    mWindow = std::make_unique<sk::Window>(800, 800, "ScrollKiller v0.1");
    mRenderer.initRenderer();
}
