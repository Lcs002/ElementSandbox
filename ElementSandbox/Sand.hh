#ifndef SAND_H
#define SAND_H

#include "Element.hh"

class Sand : public Element
{
public:
	static const unsigned char ID = 2;

	Sand();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif