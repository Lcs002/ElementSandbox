#include "Metal.hh"
#include "TextureManager.hh"

Metal::Metal() : 
	Element(0, TextureManager::get("metal"))
{

}

unsigned char Metal::getId()
{
	return ID;
}

void Metal::handle(unsigned x, unsigned y, Board* board)
{

}