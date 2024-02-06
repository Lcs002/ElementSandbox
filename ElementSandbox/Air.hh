#ifndef AIR_H
#define AIR_H

#include "Element.hh"

class Air : public Element
{
public:
	static const unsigned char ID = 1;

	Air();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif