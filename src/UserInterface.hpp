#pragma once
#include <glm/glm.hpp>
#include "Rect.hpp"

#include <functional>
namespace sk
{
	namespace ui
	{
		const glm::vec3 COLOUR_RED = { 1.0f, 0.0f, 0.0f };
		const glm::vec3 COLOUR_GREEN = { 0.0f, 1.0f, 0.0f };
		const glm::vec3 COLOUR_BLUE = { 0.0f, 0.0f, 1.0f };
		const glm::vec3 COLOUR_YELLOW = { 1.0f, 1.0f, 0.0f };
		const glm::vec3 COLOUR_CYAN = { 0.0f, 1.0f, 1.0f };
		const glm::vec3 COLOUR_PINK = { 1.0f, 0.0f, 1.0f };

		const glm::vec3 COLOUR_BACKGROUND = { 0.463f, 0.788f, 0.922f };
		const glm::vec3 COLOUR_TEAL = { 0.157f, 0.922f, 0.898f };
		const glm::vec3	COLOUR_DARKBLUE = { 0.157f, 0.459f, 0.922f };
		const glm::vec3	COLOUR_LIGHTBLUE = { 0.157f, 0.698f, 0.922f };
		const glm::vec3	COLOUR_LIGHTGREEN = { 0.518f, 0.922f, 0.773f };
		const glm::vec3	COLOUR_MIDBLUE= { 0.188f, 0.247f, 0.941f };

		class Shadow
		{
		public:
			Shadow() = default;
			Shadow(glm::vec3 topColor, glm::vec3 bottomColor, glm::vec2 origin, glm::vec2 extent);

			void createShadow() = delete;

			void Draw();

		private:
			std::vector<sk::util::Vertex> mVertices;
			std::vector<uint16_t> mIndices = { 0,1,2,2,3,1 };

			GLuint VAO, VBO, EBO;
		};

		class GUIelement
		{
		public:
			GUIelement() = default;
			GUIelement(glm::vec2 xy, glm::vec2 wh, glm::vec3 rgb);

			void Draw();

			void createShadow(glm::vec3 topColor, glm::vec3 bottomColor, float shadowHeight);

			std::vector<GUIelement> children;

			sk::ui::Shadow mShadow;
			bool hasShadow = false;
		protected:
			sk::prim::Rect mRect;
		};

		class Button : public GUIelement
		{
		public:
			Button() = default;
			Button(glm::vec2 xy, glm::vec2 wh, glm::vec3 rgb);

			bool isHovering(const glm::vec2& mousePos);
		private:
			std::function<void()> onClick;
		};
		
		
	}
}