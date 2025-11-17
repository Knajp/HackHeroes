#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace sk
{
	namespace rutils
	{
		class Shader
		{
		public:
			Shader() = default;
			~Shader(); // RAII destructor

			Shader(const char* shaderSource, GLenum type);
			GLuint getID() const;

			void destroy();
		private:
			GLuint mID;
		};

		class ShaderProgram
		{
		public:
			ShaderProgram() = default;
			~ShaderProgram(); // RAII destructor

			ShaderProgram(GLuint vertexShader, GLuint fragmentShader);

			GLuint getID() const;

			void bind() const;
			static void unbind();
		private:
			GLuint mID;
		};
	}
}