#include "Rect.hpp"

sk::prim::Rect::Rect(glm::vec2 xy, glm::vec2 wh, glm::vec3 rgb)
	:origin(xy), extent(wh), colour(rgb)
{
	generateVertices();
}

void sk::prim::Rect::generateVertices()
{
	float r = colour.r, g = colour.g, b = colour.b;

	mVertices =
	{
		{origin.x, origin.y,					   r,g,b},
		{origin.x, origin.y + extent.y,			   r,g,b},
		{origin.x + extent.x, origin.y,		       r,g,b},
		{origin.x + extent.x, origin.y + extent.y, r,g,b}
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

void sk::prim::Rect::Draw()
{
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mIndices.size()), GL_UNSIGNED_SHORT, NULL);
	
}

bool sk::prim::Rect::contains(const glm::vec2& p) const
{
	return  p.x >= origin.x &&
		p.x <= origin.x + extent.x &&
		p.y >= origin.y &&
		p.y <= origin.y + extent.y;
}
