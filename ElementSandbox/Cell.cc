#include "Cell.hh"
#include "TextureManager.hh"

Cell::Cell(float x, float y, unsigned char flags, Element* element) : sprite(TextureManager::get("null")), text()
{
	this->setPosition(x, y);
	this->element = element;
	this->flags = flags;
	this->updateSprite();
}

Cell::~Cell()
{
	delete this->element;
}

Element& Cell::getElement()
{
	return *this->element;
}

void Cell::setElement(Element* element)
{
	this->element = element;
	this->updateSprite();
}

bool Cell::isUsed()
{
	return this->flags & 1;
}

void Cell::setUsed(bool value)
{
	this->flags = (flags & ~((unsigned char) 1)) | (unsigned char) value;
}

void Cell::updateSprite() 
{
	this->sprite.setTexture(this->element->getTexture());
	this->sprite.setScale(2, 2);
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	states.transform *= getTransform();
	target.draw(this->sprite, states);
}