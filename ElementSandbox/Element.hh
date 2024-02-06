#ifndef ELEMENT_H
#define ELEMENT_H

#include "Board.hh"

class Board;
class Element
{
public:
	Element(unsigned char flag, sf::Texture& texture);
	virtual ~Element();

	sf::Texture& getTexture();
	unsigned char getPression();
	void setPression(unsigned char value);

	virtual unsigned char getId() = 0;
	virtual void handle(unsigned x, unsigned y, Board* board) = 0;	

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
