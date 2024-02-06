#ifndef NONE_H
#define NONE_H

#include "Element.hh"

class Board;
class None : public Element
{
public:
	static const unsigned char ID = 0;

	None();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif