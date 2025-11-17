#pragma once
#include <glm/glm.hpp>
#include "util.hpp"
#include <vector>
#include <glad/glad.h>

namespace sk
{
	namespace prim
	{
		class Rect
		{
		public:
			Rect() = default;
			Rect(glm::vec2 xy, glm::vec2 wh);

			void generateVertices();

			void Draw();
		private:
			glm::vec2 origin;
			glm::vec2 extent;

			std::vector<sk::util::Vertex> mVertices;
			std::vector<uint16_t> mIndices{0, 1, 2,	2, 3, 1};

			GLuint VAO, VBO, EBO;
		};
	}
}