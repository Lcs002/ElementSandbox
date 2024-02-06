#include "Smoke.hh"
#include "TextureManager.hh"

Smoke::Smoke() : 
	Element(0, TextureManager::get("smoke"))
{

}

unsigned char Smoke::getId()
{
	return ID;
}

void Smoke::handle(unsigned x, unsigned y, Board* board) 
{

}