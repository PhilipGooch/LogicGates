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
	sf::Texture textureOn;
	sf::Texture textureOff;
	sf::Texture textureClock;
	sf::Texture textureButton;
	sf::Texture textureSwitch;

	sf::Sprite spriteNOT;
	sf::Sprite spriteAND;
	sf::Sprite spriteNAND;
	sf::Sprite spriteOR;
	sf::Sprite spriteNOR;
	sf::Sprite spriteXOR;
	sf::Sprite spriteXNOR;
	sf::Sprite spriteOn;
	sf::Sprite spriteOff;
	sf::Sprite spriteClock;
	sf::Sprite spriteButton;
	sf::Sprite spriteSwitch;

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

