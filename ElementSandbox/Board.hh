#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Cell.hh"
#include "Board.hh"

class Element;
class Cell;
class Board : public sf::Drawable
{
public:
	static const unsigned WIDTH = 100;   // Number of units in X
	static const unsigned HEIGHT = 100; // Number of units in Y
	static const unsigned U_SIZE = 8;  // Unit size in pixels

	Board();
	~Board();

	void initialize();
	Element& get(unsigned x, unsigned y);
	void set(unsigned x, unsigned y, Element* element);

	bool isUsed(unsigned x, unsigned y);
	bool isValid(unsigned x, unsigned y);

	void update();

private:
	Cell* cells[WIDTH * HEIGHT];
	Element* none;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif