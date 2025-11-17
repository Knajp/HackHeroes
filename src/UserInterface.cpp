#include "UserInterface.hpp"

sk::ui::GUIelement::GUIelement(glm::vec2 xy, glm::vec2 wh, glm::vec3 rgb)
	:mRect(xy, wh, rgb)
{

}

void sk::ui::GUIelement::Draw()
{
	mRect.Draw();

	for (auto& child : children)
		child.Draw();
}

sk::ui::Button::Button(glm::vec2 xy, glm::vec2 wh, glm::vec3 rgb)
	: GUIelement(xy, wh, rgb)
{
}

bool sk::ui::Button::isHovering(const glm::vec2& mousePos)
{
	if (mRect.contains(mousePos)) return true;
	else return false;
}
