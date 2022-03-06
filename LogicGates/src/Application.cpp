#include "Application.h"

#include <iostream>

Application::Application()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "");
	window->setFramerateLimit(60);
	view.setCenter(sf::Vector2f(width / 2, height / 2));
	view.setSize(sf::Vector2f(width / zoom, height / zoom));
	window->setView(view);

	textureNOT.loadFromFile("Images/NOT.png");
	textureAND.loadFromFile("Images/AND.png");
	textureNAND.loadFromFile("Images/NAND.png");
	textureOR.loadFromFile("Images/OR.png");
	textureNOR.loadFromFile("Images/NOR.png");
	textureXOR.loadFromFile("Images/XOR.png");
	textureXNOR.loadFromFile("Images/XNOR.png");
	textureOn.loadFromFile("Images/On.png");
	textureOff.loadFromFile("Images/Off.png");
	textureClock.loadFromFile("Images/Clock.png");
	textureButton.loadFromFile("Images/Button.png");
	textureSwitch.loadFromFile("Images/Switch.png");

	spriteNOT.setTexture(textureNOT);
	spriteAND.setTexture(textureAND);
	spriteNAND.setTexture(textureNAND);
	spriteOR.setTexture(textureOR);
	spriteNOR.setTexture(textureNOR);
	spriteXOR.setTexture(textureXOR);
	spriteXNOR.setTexture(textureXNOR);
	spriteOn.setTexture(textureOn);
	spriteOff.setTexture(textureOff);
	spriteClock.setTexture(textureClock);
	spriteButton.setTexture(textureButton);
	spriteSwitch.setTexture(textureSwitch);

	sprites[_NOT_] = &spriteNOT;
	sprites[_AND_] = &spriteAND;
	sprites[_NAND_] = &spriteNAND;
	sprites[_OR_] = &spriteOR;
	sprites[_NOR_] = &spriteNOR;
	sprites[_XOR_] = &spriteXOR;
	sprites[_XNOR_] = &spriteXNOR;
	sprites[_On_] = &spriteOn;
	sprites[_Off_] = &spriteOff;
	sprites[_Clock_] = &spriteClock;
	sprites[_Button_] = &spriteButton;
	sprites[_Switch_] = &spriteSwitch;

	
}

Application::~Application()
{
	delete window;
}

void Application::Run()
{
	sf::Clock clock;
	bool running = true;
	while (running)
	{
		input.setLastKeys();
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				running = false;
				break;
			case sf::Event::KeyPressed:
				input.setKeyPressed(event.key.code);
				break;
			case sf::Event::KeyReleased:
				input.setKeyReleased(event.key.code);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
					input.setMouseLeftPressed(true);
				if (event.mouseButton.button == sf::Mouse::Right)
					input.setMouseRightPressed(true);
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
					input.setMouseLeftPressed(false);
				if (event.mouseButton.button == sf::Mouse::Right)
					input.setMouseRightPressed(false);
				break;
			case sf::Event::MouseMoved:
				input.setMousePosition(event.mouseMove.x, event.mouseMove.y);
				break;
			case sf::Event::MouseWheelMoved:
				input.setMouseWheelDelta(event.mouseWheel.delta);
				break;
			}
		}
		HandleInput();
		Update(clock.restart().asMilliseconds());
		Render();
	}
	window->close();
}

void Application::HandleInput()
{
	mouseWorldPosition = window->mapPixelToCoords((input.getMousePosition() / zoom) * zoom);

	if (input.getMouseLeftDown() || input.getMouseRightDown())
	{
		mouseWorldSave = mouseWorldPosition;
	}

	if (input.getMouseRightPressed())
	{
		view.setCenter(window->mapPixelToCoords(sf::Vector2i(width / 2, height / 2)) + mouseWorldSave - mouseWorldPosition);
		window->setView(view);
	}

	if (input.getMouseWheelDelta() != 0)
	{
		const sf::Vector2f before(window->mapPixelToCoords((sf::Vector2i(input.getMousePosition()) / zoom) * zoom));
		if (input.getMouseWheelDelta() > 0 && zoom < 16)
		{
			zoom *= 2;
			view.zoom(1.f / 2);
		}
		else if (input.getMouseWheelDelta() < 0 && zoom > 1)
		{
			zoom /= 2;
			view.zoom(2);
		}
		if (zoom < 1)
		{
			zoom = 1;
		}
		window->setView(view);
		const sf::Vector2f after(window->mapPixelToCoords((sf::Vector2i(input.getMousePosition()) / zoom) * zoom));
		const sf::Vector2f offset(before - after);
		view.move(offset);
		window->setView(view);
	}

	if (input.getKeyPressed(sf::Keyboard::Num1) ||
		input.getKeyPressed(sf::Keyboard::Num2) || 
		input.getKeyPressed(sf::Keyboard::Num3) || 
		input.getKeyPressed(sf::Keyboard::Num4) || 
		input.getKeyPressed(sf::Keyboard::Num5) || 
		input.getKeyPressed(sf::Keyboard::Num6) || 
		input.getKeyPressed(sf::Keyboard::Num7) ||
		input.getKeyPressed(sf::Keyboard::Num8) ||
		input.getKeyPressed(sf::Keyboard::Num9) ||
		input.getKeyPressed(sf::Keyboard::Num0) ||
		input.getKeyPressed(sf::Keyboard::Dash) ||
		input.getKeyPressed(sf::Keyboard::Equal))
	{
		if (selectedGate)
		{
			if (!selectedGate->GetInstantiated())
			{
				delete selectedGate;
			}
		}
	}
	
	if (input.getKeyPressed(sf::Keyboard::Num1)) selectedGate = new On(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num2)) selectedGate = new Off(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num3)) selectedGate = new AND(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num4)) selectedGate = new OR(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num5)) selectedGate = new NAND(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num6)) selectedGate = new NOR(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num7)) selectedGate = new XOR(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num8)) selectedGate = new XNOR(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num9)) selectedGate = new NOT(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Num0)) selectedGate = new Clock(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Dash)) selectedGate = new Button(input.getMousePosition() / zoom);
	if (input.getKeyPressed(sf::Keyboard::Equal)) selectedGate = new Switch(input.getMousePosition() / zoom);


	if (input.getMouseLeftDown())
	{
		// for initial placing of gates...
		if (selectedGate)
		{
			if (!selectedGate->GetInstantiated())
			{
				if (valid)
				{
					selectedGate->SetInstantiated(true);
					gates.push_back(selectedGate);
				}
			}
		}

		bool clickedOnGate = false;
		for (Gate* gate : gates)
		{
			// gate
			if (gate->Clicked(mouseWorldPosition))
			{
				clickedOnGate = true;
				selectedGate = gate;
				gateWorldSave = sf::Vector2f(selectedGate->GetWorldPosition());
				gateOffsetWorldSave = mouseWorldPosition - gateWorldSave - sf::Vector2f(gate->rectangle.width / 2, gate->rectangle.height / 2);
				// top input node
				if (gate->m_nodes[0].Clicked(mouseWorldPosition))
				{
					connecting = true;
					gateA = gate;
					gateANode = 0;
					selectedGate = nullptr;
					wireAWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->m_nodes[0].position);
				}
				// bottom input node
				else if (gate->m_nodes[1].Clicked(mouseWorldPosition))
				{
					connecting = true;
					gateA = gate;
					gateANode = 1;
					selectedGate = nullptr;
					wireAWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->m_nodes[1].position);
				}
				// output node
				else if (gate->m_nodes[2].Clicked(mouseWorldPosition))
				{
					connecting = true;
					gateA = gate;
					gateANode = 2;
					selectedGate = nullptr;
					wireAWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->m_nodes[2].position);
				}
				break;
			}
			
		}
		if (!clickedOnGate)
		{
			selectedGate = nullptr;
		}
	} 

	if (input.getMouseLeftPressed())
	{
		if (selectedGate)
		{
			if (selectedGate->GetInstantiated())
			{
				if (!connecting)
				{
					selectedGate->SetWorldPosition(sf::Vector2i(mouseWorldPosition - gateOffsetWorldSave));
					dragging = true;
				}
			}
		}
		else 
		{
			if (!connecting)
			{
				selecting = true;
			}
		}
		if (connecting)
		{
			connection = false;
			for (Gate* gate : gates)
			{
				// top input node
				if (gate->m_nodes[0].Clicked(mouseWorldPosition))
				{
					connection = true;
					gateB = gate;
					gateBNode = 0;
					wireBWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->m_nodes[0].position);
					break;
				}
				// bottom input node
				else if (gate->m_nodes[1].Clicked(mouseWorldPosition))
				{
					connection = true;
					gateB = gate;
					gateBNode = 1;
					wireBWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->m_nodes[1].position);
					break;
				}
				// output node
				else if (gate->m_nodes[2].Clicked(mouseWorldPosition))
				{
					connection = true;
					gateB = gate;
					gateBNode = 2;
					wireBWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->m_nodes[2].position);
					break;
				}
			}
		}
	}

	if (input.getMouseLeftUp())
	{
		if (connection)
		{
			//if (!gateA->m_nodes[gateANode].connection && !gateB->m_nodes[gateBNode].connection)
			{
				if (gateANode == 2 && (gateBNode == 0 || gateBNode == 1))
				{
					gateA->ConnectOutputToInput(gateB, gateBNode);
				}
				if ((gateANode == 0 || gateANode == 1) && gateBNode == 2)
				{
					gateA->ConnectInputAToOutput(gateB, gateANode);
				}
			}
		}

		if (selecting)
		{
			for (Gate* gate : gates)
			{
				if (gate->GetWorldPosition().x < mouseWorldPosition.x &&
					gate->GetWorldPosition().x + gate->rectangle.width > mouseWorldSave.x &&
					gate->GetWorldPosition().y < mouseWorldPosition.y &&
					gate->GetWorldPosition().y + gate->rectangle.height > mouseWorldSave.y)
				{
					// multi selection...
				}
			}
		}

		dragging = false;
		connecting = false;
		connection = false;
		selecting = false;

		if (selectedGate)
		{
			if (!valid)
			{
				selectedGate->SetWorldPosition(sf::Vector2i(gateWorldSave) + sf::Vector2i(selectedGate->rectangle.width / 2, selectedGate->rectangle.height / 2));
			}
		}
	}

	if (input.getKeyPressed(sf::Keyboard::Escape))
	{
		if (selectedGate)
		{
			if (!selectedGate->GetInstantiated())
			{
				delete selectedGate;
				selectedGate = nullptr;
			}
		}
	}

	if (input.getKeyPressed(sf::Keyboard::Delete))
	{
		if (selectedGate)
		{
			if (selectedGate->GetInstantiated())
			{
				for (int i = 0; i < 3; i++)
				{
					if (selectedGate->m_nodes[i].connection)
					{
						selectedGate->m_nodes[i].connection->connection = nullptr;
						selectedGate->m_nodes[i].connection = nullptr;
					}
				}
				for (int i = 0; i < gates.size(); i++)
				{
					if (gates[i] == selectedGate)
					{
						gates.erase(gates.begin() + i);
						break;
					}
				}
				delete selectedGate;
				selectedGate = nullptr;
			}
		}
	}


	input.setLastMouse();
	input.setMouseWheelDelta(0);
	input.setLastKeys();
}

void Application::Update(float deltaTime)
{
	for (Gate* gate : gates)
	{
		gate->Update();
	}

	if (selectedGate)
	{
		if (!selectedGate->GetInstantiated())
		{
			selectedGate->SetWorldPosition(sf::Vector2i(mouseWorldPosition));
		}

		highlight.setPosition(selectedGate->GetWorldPosition().x, selectedGate->GetWorldPosition().y);

		valid = true;
		for (Gate* gate : gates)
		{
			if (gate == selectedGate) continue;
		
			if (selectedGate->GetWorldPosition().x < gate->GetWorldPosition().x + gate->rectangle.width &&
				selectedGate->GetWorldPosition().x + selectedGate->rectangle.width > gate->GetWorldPosition().x &&
				selectedGate->GetWorldPosition().y < gate->GetWorldPosition().y + gate->rectangle.height &&
				selectedGate->GetWorldPosition().y + selectedGate->rectangle.height > gate->GetWorldPosition().y)
			{
				valid = false;
				break;
			}
		}
		
		if (!selectedGate->GetInstantiated() || dragging)
		{
			if (valid)
			{
				highlight.setFillColor(sf::Color(0, 255, 0, 150));
			}
			else
			{
				highlight.setFillColor(sf::Color(255, 0, 0, 150));
			}
		}
		else
		{
			highlight.setFillColor(sf::Color(255, 255, 0, 150));
		}
	}
}

void Application::Render()
{
	window->clear(sf::Color(200, 200, 200));

	if (selecting)
	{
		sf::RectangleShape rectangle;
		rectangle.setPosition(mouseWorldSave);
		rectangle.setSize(mouseWorldPosition - mouseWorldSave);
		rectangle.setFillColor(sf::Color(0, 0, 255, 150));
		window->draw(rectangle);
	}

	for (Gate* gate : gates)
	{
		sf::Sprite* sprite = sprites[gate->GetType()];
		sprite->setPosition(gate->GetWorldPosition().x, gate->GetWorldPosition().y);
		window->draw(*sprite);
	}

	if(selectedGate)
	{
		highlight.setSize(sf::Vector2f(selectedGate->rectangle.width, selectedGate->rectangle.height));
		window->draw(highlight);
		sf::Sprite* sprite = sprites[selectedGate->GetType()];
		sprite->setPosition(selectedGate->GetWorldPosition().x, selectedGate->GetWorldPosition().y);
		window->draw(*sprite);
	}

	if (connecting)
	{
		sf::RectangleShape square;
		square.setSize(sf::Vector2f(1, 1));
		square.setPosition(wireAWorldSave);
		square.setFillColor(gateANode == 2 ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black);
		window->draw(square);

		sf::Vertex line[] =
		{
			sf::Vertex(wireAWorldSave + sf::Vector2f(0.5f, 0.5f), gateANode == 2 ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black),
			sf::Vertex(mouseWorldPosition + sf::Vector2f(0.5f, 0.5f), gateANode == 2 ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black)
			
		};

		if (connection)
		{
			line[1] = sf::Vertex(wireBWorldSave + sf::Vector2f(0.5f, 0.5f), gateANode == 2 ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black);
			square.setPosition(wireBWorldSave);
			window->draw(square);
		}

		window->draw(line, 2, sf::Lines);
	}

	for (Gate* gate : gates)
	{
		// loop through input nodes instead to allow for many to 1 connections from output...
			if (gate->m_nodes[2].connection)
			{
				sf::Vector2f connectorPosition = sf::Vector2f(gate->GetWorldPosition() + gate->m_nodes[2].position);
				sf::Vector2f otherConnectorPosition = sf::Vector2f(gate->m_nodes[2].connection->parent->GetWorldPosition() + gate->m_nodes[2].connection->position);

				sf::RectangleShape square;
				square.setSize(sf::Vector2f(1, 1));
				square.setFillColor(gate->output ? sf::Color::Red : sf::Color::Black);
				square.setPosition(connectorPosition);
				window->draw(square);
				square.setPosition(otherConnectorPosition);
				window->draw(square);
				

				sf::Vertex line[] =
				{
					sf::Vertex(connectorPosition + sf::Vector2f(0.5f, 0.5f), gate->output ? sf::Color::Red : sf::Color::Black),
					sf::Vertex(otherConnectorPosition + sf::Vector2f(0.5f, 0.5f), gate->output ? sf::Color::Red : sf::Color::Black)
				};
				
				window->draw(line, 2, sf::Lines);
			}
			
			
		
	}

	window->display();
}


