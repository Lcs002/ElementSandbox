#ifndef AIR_H
#define AIR_H

#include "Element.hh"
#include "Elements.hh"

class Air : public Element
{
public:
	Air();

	unsigned char getId() override;
	void handle(unsigned x, unsigned y, Board* board) override;
};

#endif