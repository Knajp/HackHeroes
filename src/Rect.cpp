#include "Rect.hpp"

sk::prim::Rect::Rect(glm::vec2 xy, glm::vec2 wh)
	:origin(xy), extent(wh)
{
	generateVertices();
}

void sk::prim::Rect::generateVertices()
{
	mVertices =
	{
		{origin.x, origin.y,					   1.0f, 0.0f, 0.0f},
		{origin.x, origin.y + extent.y,			   1.0f, 0.0f, 0.0f},
		{origin.x + extent.x, origin.y,		       1.0f, 0.0f, 0.0f},
		{origin.x + extent.x, origin.y + extent.y, 1.0f, 0.0f, 0.0f}
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

	glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_SHORT, NULL);
}
