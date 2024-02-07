#ifndef METAL_H
#define METAL_H

#include "Element.hh"
#include "Elements.hh"

class Metal : public Element
{
public:
	Metal();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif