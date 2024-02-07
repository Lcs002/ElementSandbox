#ifndef INTERACTION_HANDLER_H
#define INTERACTION_HANDLER_H

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "Interaction.hh"

class Interaction;
class InteractionHandler
{
public:
	void addInteraction(unsigned char id, sf::Texture& texture);
	Interaction* getInteraction(unsigned char id);

private:
	std::map<unsigned char, Interaction*> interactions;
};

#endif