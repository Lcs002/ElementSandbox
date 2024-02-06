#ifndef LIQUID_H
#define LIQUID_H

#include "Element.hh"

class Liquid : public Element
{
public:
	static const unsigned char ID = 4;

	Liquid();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif