#include "ElementHandler.hh"
#include "Elements.hh"
#include "Air.hh"
#include "Liquid.hh"
#include "Metal.hh"
#include "None.hh"
#include "Sand.hh"

Element* ElementHandler::createElement(unsigned char id)
{
	Element* element = NULL;
	
	switch (id)
	{
	case Elements::AIR: element = new Air(); break;
	case Elements::SAND: element = new Sand(); break;
	case Elements::LIQUID: element = new Liquid(); break;
	case Elements::METAL: element = new Metal(); break;
	case Elements::NONE: element = new None(); break;
	}

	return element;
}