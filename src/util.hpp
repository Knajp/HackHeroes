#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

namespace sk
{
	namespace util
	{
		struct Vertex
		{
			float x, y;
			float r, g, b;
		};

		inline std::string readFile(const char* path)
		{
			std::ifstream file(path, std::ios::in);
			if (!file.is_open())
				//Logger throw error
				return "";

			std::stringstream buffer;
			buffer << file.rdbuf();
			return buffer.str();
		}
	}
}