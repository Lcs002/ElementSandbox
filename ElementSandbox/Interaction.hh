#ifndef INTERACTION_H
#define INTERACTION_H

#include "Elements.hh"

enum Elements;
class Interaction
{
public:
	Interaction(Elements elementId);

	virtual unsigned char getId() = 0;

private:
	Elements elementId;
};

#endif