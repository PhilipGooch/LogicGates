#pragma once
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Gate.h"

#include <vector>
#include <map>

class Application
{
public:
	Application();
	~Application();

	void Run();

protected:
	void HandleInput();
	void Update(float deltaTime);
	void Render();

private:
	sf::RenderWindow* window;
	sf::View view;
	Input input;

	sf::Texture textureNOT;
	sf::Texture textureAND;
	sf::Texture textureNAND;
	sf::Texture textureOR;
	sf::Texture textureNOR;
	sf::Texture textureXOR;
	sf::Texture textureXNOR;
	sf::Texture textureTRI;
	sf::Texture textureOn;
	sf::Texture textureOff;
	sf::Texture textureClockOff;
	sf::Texture textureClockOn;
	sf::Texture textureButtonOff;
	sf::Texture textureButtonOn;
	sf::Texture textureSwitchOff;
	sf::Texture textureSwitchOn;
	sf::Texture textureLightOn;
	sf::Texture textureLightOff;
	sf::Texture textureDisplay0;
	sf::Texture textureDisplay1;
	sf::Texture textureDisplay2;
	sf::Texture textureDisplay3;
	sf::Texture textureDisplay4;
	sf::Texture textureDisplay5;
	sf::Texture textureDisplay6;
	sf::Texture textureDisplay7;
	sf::Texture textureDisplay8;
	sf::Texture textureDisplay9;
	sf::Texture textureDisplayA;
	sf::Texture textureDisplayB;
	sf::Texture textureDisplayC;
	sf::Texture textureDisplayD;
	sf::Texture textureDisplayE;
	sf::Texture textureDisplayF;

	sf::Sprite spriteNOT;
	sf::Sprite spriteAND;
	sf::Sprite spriteNAND;
	sf::Sprite spriteOR;
	sf::Sprite spriteNOR;
	sf::Sprite spriteXOR;
	sf::Sprite spriteXNOR;
	sf::Sprite spriteTRI;
	sf::Sprite spriteOff;
	sf::Sprite spriteOn;
	sf::Sprite spriteClockOff;
	sf::Sprite spriteClockOn;
	sf::Sprite spriteButtonOff;
	sf::Sprite spriteButtonOn;
	sf::Sprite spriteSwitchOff;
	sf::Sprite spriteSwitchOn;
	sf::Sprite spriteLightOn;
	sf::Sprite spriteLightOff;
	sf::Sprite spriteDisplay0;
	sf::Sprite spriteDisplay1;
	sf::Sprite spriteDisplay2;
	sf::Sprite spriteDisplay3;
	sf::Sprite spriteDisplay4;
	sf::Sprite spriteDisplay5;
	sf::Sprite spriteDisplay6;
	sf::Sprite spriteDisplay7;
	sf::Sprite spriteDisplay8;
	sf::Sprite spriteDisplay9;
	sf::Sprite spriteDisplayA;
	sf::Sprite spriteDisplayB;
	sf::Sprite spriteDisplayC;
	sf::Sprite spriteDisplayD;
	sf::Sprite spriteDisplayE;
	sf::Sprite spriteDisplayF;

	sf::RectangleShape highlight;

	int zoom = 4;
	
	Gate* selectedGate = nullptr;
	Gate* gateA = nullptr;
	Gate* gateB = nullptr;
	int gateANode = -1;
	int gateBNode = -1;

	std::vector<Gate*> gates;

	sf::Vector2f mouseWorldPosition;
	sf::Vector2f mouseWorldSave;
	sf::Vector2f gateWorldSave;
	sf::Vector2f gateOffsetWorldSave;
	sf::Vector2f wireAWorldSave;
	sf::Vector2f wireBWorldSave;

	std::map<int, sf::Sprite*> sprites;

	bool valid = true;
	bool dragging = false;
	bool connecting = false;
	bool connection = false;
	bool selecting = false;

	int width = 1024;
	int height = 1024 - 256;
};

