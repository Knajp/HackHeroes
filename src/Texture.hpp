#include <iostream>
#include <glad/glad.h>
#include <spd/stb_image.h>
#include "Logger.hpp"

namespace sk
{
	namespace rutils
	{
#ifdef DEBUG
		sk::debug::Logger ruLogger = sk::debug::Logger("Render utils logger", spdlog::level::debug);
#endif
		class Texture
		{
		public:
			Texture() = default;
			Texture(std::string path);

			GLuint getID() const;
		private:
			GLuint mID;
			int mW, mH, mC;
		};
	}
}