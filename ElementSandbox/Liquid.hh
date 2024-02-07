#ifndef LIQUID_H
#define LIQUID_H

#include "Element.hh"
#include "Elements.hh"

class Liquid : public Element
{
public:
	Liquid();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif