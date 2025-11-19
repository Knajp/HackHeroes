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

	mShadow.Draw();
}


void sk::ui::GUIelement::createShadow(glm::vec3 topColor, glm::vec3 bottomColor, float shadowHeight)
{
	glm::vec2 shadowOrigin = { mRect.origin.x, mRect.origin.y - shadowHeight };
	glm::vec2 shadowExtent = { mRect.extent.x, shadowHeight };
	
	mShadow = sk::ui::Shadow(topColor, bottomColor, shadowOrigin, shadowExtent);
	hasShadow = true;
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

sk::ui::Shadow::Shadow(glm::vec3 topColor, glm::vec3 bottomColor, glm::vec2 origin, glm::vec2 extent)
{
	mVertices =
	{
		{origin.x, origin.y, bottomColor.x, bottomColor.y, bottomColor.z},
		{origin.x + extent.x, origin.y, bottomColor.x, bottomColor.y, bottomColor.z},
		{origin.x, origin.y + extent.y, topColor.x, topColor.y, topColor.z},
		{origin.x + extent.x, origin.y + extent.y, topColor.x, topColor.y, topColor.z}
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(sk::util::Vertex), mVertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(uint16_t), mIndices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void sk::ui::Shadow::Draw()
{
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mIndices.size()), GL_UNSIGNED_SHORT, NULL);
}
