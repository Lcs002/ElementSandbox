#include "Board.hh"
#include "ElementHandler.hh"
#include "Elements.hh"
#include <algorithm>

Board::Board()
{
	
}

Board::~Board()
{
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			delete cells[y * WIDTH + x];
		}
	}
}

void Board::initialize()
{
	// Populate cells
	this->none = ElementHandler::createElement(Elements::NONE);
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			cells[y * WIDTH + x] = new Cell(x * U_SIZE, y * U_SIZE, 0, ElementHandler::createElement(Elements::AIR));
		}
	}
}

Element& Board::get(unsigned x, unsigned y)
{
	if (!this->isValid(x, y)) return *this->none;
	return cells[y * WIDTH + x]->getElement();
}

void Board::set(unsigned x, unsigned y, Element* element)
{
	cells[y * WIDTH + x]->setElement(element);
	cells[y * WIDTH + x]->setUsed(true);
}

bool Board::isUsed(unsigned x, unsigned y)
{
	if (!this->isValid(x, y)) return true;
	return cells[y * WIDTH + x]->isUsed();
}

bool Board::isValid(unsigned x, unsigned y)
{
	return x < WIDTH&& x >= 0 && y < HEIGHT&& y >= 0;
}

void Board::update() 
{
	// Set each cell to NOT Used
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			cells[y * WIDTH + x]->setUsed(false);
		}
	}

	// Shuffle Columns for more Random Behaviour
	unsigned randplace[WIDTH];
	for (int i = 0; i < WIDTH; i++) randplace[i] = i;
	std::random_shuffle(randplace, randplace + WIDTH);

	// Update rows -> cols
	for (int y = HEIGHT - 1; y >= 0 ; y--) {
		for (int w = 0; w < WIDTH; w++) {
			int x = randplace[w];
			Cell* cell = cells[y * WIDTH + x];
			if (!cell->isUsed()) {
				cell->getElement().handle(x, y, this);
			} 
		}
	}
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			target.draw(*cells[y * WIDTH + x]);
		}
	}
}