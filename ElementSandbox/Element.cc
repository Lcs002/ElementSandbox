#include <SFML/Graphics/VertexArray.hpp>
#include "Element.hh"
#include "None.hh"

Element::Element(unsigned char flag, sf::Texture& texture) : 
	texture(texture)
{
	this->flag = flag;
}

Element::~Element()
{

}

sf::Texture& Element::getTexture()
{
	return this->texture;
}

unsigned char Element::getPression()
{
	return this->flag & (4 | 3 | 2 | 1);
}

void Element::setPression(unsigned char value)
{
	this->flag = (flag & ~(4 | 3 | 2 | 1)) | (value & (4 | 3 | 2 | 1));
}
