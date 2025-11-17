#include "Application.hpp"
#include "Renderer.hpp"
#include "Rect.hpp"

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

    sk::prim::Rect rect({ -0.5f, -0.5f }, { 1.0f, 1.0f });

    mRenderer.bindProgram(sk::rutils::PROGRAM_TYPE::BASIC);
    while (!mWindow->shouldClose())
    {
        mRenderer.clearFramebuffer();

        rect.Draw();

        mWindow->pollEvents();
    }
}

void sk::Application::initApplication()
{
    mWindow = std::make_unique<sk::Window>(800, 800, "ScrollKiller v0.1");
    mRenderer.initRenderer();
}
