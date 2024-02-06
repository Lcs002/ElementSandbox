#ifndef SMOKE_H
#define SMOKE_H

#include "Element.hh"

class Smoke : public Element
{
public:
	static const unsigned char ID = 5;

	Smoke();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif