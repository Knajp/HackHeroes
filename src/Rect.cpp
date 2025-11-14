#include "Rect.hpp"

sk::prim::Rect::Rect(glm::vec2 xy, glm::vec2 wh)
	:origin(xy), extent(wh)
{

}

void sk::prim::Rect::generateVertices()
{
	mVertices =
	{
		{{origin.x, origin.y}, {1.0f, 0.0f, 0.0f}},
		{{origin.x, origin.y + 0.5f}, {1.0f, 0.0f, 0.0f}},
		{{origin.x + 0.5f, origin.y}, {1.0f, 0.0f, 0.0f}}
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(sk::util::Vertex), mVertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void sk::prim::Rect::Draw()
{
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
