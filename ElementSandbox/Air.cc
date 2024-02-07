#include "Air.hh"
#include "TextureManager.hh"

Air::Air() : 
	Element(0, TextureManager::get("air"))
{

}

unsigned char Air::getId()
{
	return Elements::AIR;
}

void Air::handle(unsigned x, unsigned y, Board* board)
{

}