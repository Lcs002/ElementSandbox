#ifndef ELEMENT_H
#define ELEMENT_H

#include <memory>
#include <map>
#include "Board.hh"
#include "InteractionHandler.hh"

class Board;
class InteractionHandler;
class Interaction;
class Element
{
public:
	Element(unsigned char flag, sf::Texture& texture);
	virtual ~Element();

	// Texture
	sf::Texture& getTexture();
	// Pression
	unsigned char getPression();
	void setPression(unsigned char value);
	// Interactions
	Interaction* getInteraction(unsigned char id);


	virtual unsigned char getId() = 0;
	virtual void handle(unsigned x, unsigned y, Board* board) = 0;

protected:
	InteractionHandler interactionHandler;

private:
	/*
	*  - - - - - - - -
	* |7 6 5 4 3 2 1 0|
	*  - - - - - - - -
	*          |     |
	*          +--+--+
	*             |
	*             +-> Pression
	*/
	unsigned char flag;
	sf::Texture& texture;
};

#endif
