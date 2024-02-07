#ifndef ELEMENT_HANDLER_H
#define ELEMENT_HANDLER_H

#include "Element.hh"

class Element;
class ElementHandler
{
public:
	static Element* createElement(unsigned char id);
};

#endif