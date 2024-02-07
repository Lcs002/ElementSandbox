#ifndef NONE_H
#define NONE_H

#include "Element.hh"
#include "Elements.hh"

class None : public Element
{
public:
	None();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif