#include "Texture.hpp"

sk::rutils::Texture::Texture(std::string path)
{
	glGenTextures(1, &mID);
	glBindTexture(GL_TEXTURE_2D, mID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	unsigned char* data = stbi_load(path.c_str(), &mW, &mH, &mC, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mW, mH, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
#ifdef DEBUG
		ruLogger.error("Failed to load texture data!");
#endif
		throw std::runtime_error("Failed to load texture!");
	}
	stbi_image_free(data);
	
}

GLuint sk::rutils::Texture::getID() const
{
	return mID;
}
