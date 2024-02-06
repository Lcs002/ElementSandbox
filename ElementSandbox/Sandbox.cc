#include <stdlib.h>
#include <time.h>   
#include <SFML/Graphics/Texture.hpp>
#include "Sandbox.hh"
#include "Air.hh"
#include "Sand.hh"
#include "Metal.hh"
#include "Liquid.hh"
#include "TextureManager.hh"


Sandbox::Sandbox()
{
	srand(time(NULL)); // In case we need to use it 
	// Context Settings
	this->contextSettings.depthBits = 8;
	this->contextSettings.stencilBits = 8;
	this->contextSettings.antialiasingLevel = 0;
	this->contextSettings.majorVersion = 3;
	this->contextSettings.minorVersion = 0;
	// Video Mode Settings
	this->videoMode.height = WINDOW_HEIGHT;
	this->videoMode.width = WINDOW_WIDTH;
	// Render Window config
	this->renderWindow = new sf::RenderWindow(
		this->videoMode,
		"ElementSandbox",
		sf::Style::Default,
		this->contextSettings
	);
	this->renderWindow->setFramerateLimit(30);
	this->renderWindow->setVerticalSyncEnabled(false);
	this->renderWindow->setActive(true);
}

Sandbox::~Sandbox()
{
	delete& contextSettings;
	delete renderWindow;
	delete& videoMode;
	delete& board;
}

void Sandbox::start()
{
	this->initialize();
	this->loop();
}

void Sandbox::initialize()
{
	// Load all Textures
	TextureManager::setNull("Null.png");
	TextureManager::load("sand", "Sand.png");
	TextureManager::load("water", "Water.png");
	TextureManager::load("air", "Air.png");
	TextureManager::load("metal", "Metal.png");
	TextureManager::load("smoke", "Smoke.png");

	this->board.initialize();
}

void Sandbox::loop()
{
	bool pressed = false;
	int mouseX = 0;
	int mouseY = 0;
	int element = 1;
	
	while (this->renderWindow->isOpen()) {
		sf::Event event;
		while (this->renderWindow->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: this->renderWindow->close(); break;
			case sf::Event::MouseButtonPressed: pressed = true; break;
			case sf::Event::MouseButtonReleased: pressed = false; break;
			case sf::Event::MouseMoved:
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
				break;
			case sf::Event::KeyPressed:
				switch (event.key.scancode)
				{
				case sf::Keyboard::Num0: element = Air::ID; break;
				case sf::Keyboard::Num1: element = Sand::ID; break;
				case sf::Keyboard::Num2: element = Metal::ID; break;
				case sf::Keyboard::Num3: element = Liquid::ID; break;
				default: break;
				}
			default: break;
			}
		}

		if (pressed) {
			Element* e = NULL;
			switch (element)
			{
			case Air::ID: e = new Air(); break;
			case Sand::ID: e = new Sand(); break;
			case Metal::ID: e = new Metal(); break;
			case Liquid::ID: e = new Liquid(); break;
			}
			this->board.set(mouseX / Board::U_SIZE, mouseY / Board::U_SIZE, e);
		}

		update();
		draw();
	}
}

void Sandbox::update()
{
	board.update();
}

void Sandbox::draw()
{
	renderWindow->clear();
	renderWindow->draw(board);
	renderWindow->display();
}