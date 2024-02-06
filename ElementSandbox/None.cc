#include "None.hh"
#include "TextureManager.hh"

None::None() : 
	Element(0, TextureManager::get("null"))
{

}

unsigned char None::getId()
{
	return ID;
}

void None::handle(unsigned x, unsigned y, Board* board)
{

}