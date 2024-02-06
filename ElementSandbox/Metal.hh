#ifndef METAL_H
#define METAL_H

#include "Element.hh"

class Metal : public Element
{
public:
	static const unsigned char ID = 3;

	Metal();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif