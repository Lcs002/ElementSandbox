#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Element.hh"
#include <SFML/Graphics/Texture.hpp>

class Element;
class Cell : public sf::Drawable, public sf::Transformable
{
public:
	Cell(float x, float y, unsigned char flags, Element* element);
	~Cell();

	Element& getElement();
	void setElement(Element* element);

	bool isUsed();
	void setUsed(bool value);

private:
	sf::Sprite sprite;
	sf::Texture text;
	Element* element;
	
	/*
	*  - - - - - - - - 
	* |7 6 5 4 3 2 1 0|
	*  - - - - - - - - 
	*                +-> Used
	*/
	unsigned char flags;

	void updateSprite();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif