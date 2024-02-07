#ifndef SAND_H
#define SAND_H

#include "Element.hh"
#include "Elements.hh"

class Sand : public Element
{
public:

	Sand();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif