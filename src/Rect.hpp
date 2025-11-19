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
			Rect(glm::vec2 xy, glm::vec2 wh, glm::vec3 rgb);

			void generateVertices();

			void Draw();
			bool contains(const glm::vec2& p) const;

			glm::vec2 origin;
			glm::vec2 extent;
		private:
			
			glm::vec3 colour;

			std::vector<sk::util::Vertex> mVertices;
			std::vector<uint16_t> mIndices{0, 1, 2,	2, 3, 1};

			GLuint VAO, VBO, EBO;
		};
	}
}