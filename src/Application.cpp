#include "Application.hpp"
#include "Renderer.hpp"
#include "UserInterface.hpp"

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

    sk::ui::GUIelement topBar({ -1.0f, 0.8f }, { 2.0f, 0.2f }, sk::ui::COLOUR_LIGHTBLUE);

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
    mLogger.debug("Hello, World!");
    mWindow = std::make_unique<sk::Window>(800, 800, "ScrollKiller v0.1");
    mRenderer.initRenderer();
}
