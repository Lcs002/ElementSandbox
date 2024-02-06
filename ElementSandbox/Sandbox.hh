#ifndef SANDBOX_H
#define SANDBOX_H

#include <SFML/Graphics.hpp>
#include <string.h>

#include <random>
#include "Board.hh"	

class Sandbox
{
public:
	static const unsigned WINDOW_WIDTH = 800;
	static const unsigned WINDOW_HEIGHT = 800;

	Sandbox();
	~Sandbox();

	void start();
		
private:
	sf::ContextSettings contextSettings;
	sf::RenderWindow* renderWindow;
	sf::VideoMode videoMode;
	Board board;

	void initialize();
	void loop();
	void update();
	void draw();
};

#endif
