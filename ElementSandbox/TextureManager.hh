#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <map>

class TextureManager
{
public:
	static void load(std::string id, std::string file);
	static sf::Texture& get(std::string id);
	static void setNull(std::string file);

private:
	// Map stored in stack but its elements are still stored in heap
	static std::map<std::string, sf::Texture> textures;
};

#endif