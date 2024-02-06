#include <iostream>
#include "TextureManager.hh"

std::map<std::string, sf::Texture> TextureManager::textures;

void TextureManager::load(std::string id, std::string file)
{
	std::pair<std::string, sf::Texture> entry(id, *new sf::Texture);
	if (entry.second.loadFromFile(file)) {
		textures.insert(entry);
		std::cout << "Info:: Loaded texture '" + file + "' and mapped to '" + id + "'\n";
	}
	else {
		std::cout << "Warning:: Cloud not load texture '" + file + "'\n";
	}
}

sf::Texture& TextureManager::get(std::string id)
{
	std::map<std::string, sf::Texture>::iterator i = textures.find(id);
	if (i == textures.end()) {
		return textures.at("null");
	}
	else {
		return i->second;
	}
}

void TextureManager::setNull(std::string file)
{
	sf::Texture texture;
	texture.loadFromFile(file);
	textures.insert(std::pair<std::string, sf::Texture>("null", texture));
}