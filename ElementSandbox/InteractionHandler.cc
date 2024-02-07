#include "InteractionHandler.hh"

void InteractionHandler::addInteraction(unsigned char id, sf::Texture& texture)
{

}

Interaction* InteractionHandler::getInteraction(unsigned char id)
{
	std::map<unsigned char, Interaction*>::iterator i = interactions.find(id);
	if (i == interactions.end()) {
		return NULL;
	}
	else {
		return i->second;
	}
}