#include "Application.h"

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
	textureTRI.loadFromFile("Images/TRI.png");
	textureOn.loadFromFile("Images/On.png");
	textureOff.loadFromFile("Images/Off.png");
	textureClockOff.loadFromFile("Images/ClockOff.png");
	textureClockOn.loadFromFile("Images/ClockOn.png");
	textureButtonOff.loadFromFile("Images/ButtonOff.png");
	textureButtonOn.loadFromFile("Images/ButtonOn.png");
	textureSwitchOff.loadFromFile("Images/SwitchOff.png");
	textureSwitchOn.loadFromFile("Images/SwitchOn.png");
	textureLightOff.loadFromFile("Images/LightOff.png");
	textureLightOn.loadFromFile("Images/LightOn.png");
	textureDisplay0.loadFromFile("Images/Display0.png");
	textureDisplay1.loadFromFile("Images/Display1.png");
	textureDisplay2.loadFromFile("Images/Display2.png");
	textureDisplay3.loadFromFile("Images/Display3.png");
	textureDisplay4.loadFromFile("Images/Display4.png");
	textureDisplay5.loadFromFile("Images/Display5.png");
	textureDisplay6.loadFromFile("Images/Display6.png");
	textureDisplay7.loadFromFile("Images/Display7.png");
	textureDisplay8.loadFromFile("Images/Display8.png");
	textureDisplay9.loadFromFile("Images/Display9.png");
	textureDisplay0.loadFromFile("Images/Display0.png");
	textureDisplayA.loadFromFile("Images/DisplayA.png");
	textureDisplayB.loadFromFile("Images/DisplayB.png");
	textureDisplayC.loadFromFile("Images/DisplayC.png");
	textureDisplayD.loadFromFile("Images/DisplayD.png");
	textureDisplayE.loadFromFile("Images/DisplayE.png");
	textureDisplayF.loadFromFile("Images/DisplayF.png");

	spriteNOT.setTexture(textureNOT);
	spriteAND.setTexture(textureAND);
	spriteNAND.setTexture(textureNAND);
	spriteOR.setTexture(textureOR);
	spriteNOR.setTexture(textureNOR);
	spriteXOR.setTexture(textureXOR);
	spriteXNOR.setTexture(textureXNOR);
	spriteTRI.setTexture(textureTRI);
	spriteOn.setTexture(textureOn);
	spriteOff.setTexture(textureOff);
	spriteClockOff.setTexture(textureClockOff);
	spriteClockOn.setTexture(textureClockOn);
	spriteButtonOff.setTexture(textureButtonOff);
	spriteButtonOn.setTexture(textureButtonOn);
	spriteSwitchOff.setTexture(textureSwitchOff);
	spriteSwitchOn.setTexture(textureSwitchOn);
	spriteLightOff.setTexture(textureLightOff);
	spriteLightOn.setTexture(textureLightOn);
	spriteDisplay0.setTexture(textureDisplay0);
	spriteDisplay1.setTexture(textureDisplay1);
	spriteDisplay2.setTexture(textureDisplay2);
	spriteDisplay3.setTexture(textureDisplay3);
	spriteDisplay4.setTexture(textureDisplay4);
	spriteDisplay5.setTexture(textureDisplay5);
	spriteDisplay6.setTexture(textureDisplay6);
	spriteDisplay7.setTexture(textureDisplay7);
	spriteDisplay8.setTexture(textureDisplay8);
	spriteDisplay9.setTexture(textureDisplay9);
	spriteDisplay0.setTexture(textureDisplay0);
	spriteDisplayA.setTexture(textureDisplayA);
	spriteDisplayB.setTexture(textureDisplayB);
	spriteDisplayC.setTexture(textureDisplayC);
	spriteDisplayD.setTexture(textureDisplayD);
	spriteDisplayE.setTexture(textureDisplayE);
	spriteDisplayF.setTexture(textureDisplayF);

	sprites[_NOT_] = &spriteNOT;
	sprites[_AND_] = &spriteAND;
	sprites[_NAND_] = &spriteNAND;
	sprites[_OR_] = &spriteOR;
	sprites[_NOR_] = &spriteNOR;
	sprites[_XOR_] = &spriteXOR;
	sprites[_XNOR_] = &spriteXNOR;
	sprites[_TRI_] = &spriteTRI;
	sprites[_On_] = &spriteOn;
	sprites[_Off_] = &spriteOff;
	sprites[_ClockOff_] = &spriteClockOff;
	sprites[_ClockOn_] = &spriteClockOn;
	sprites[_ButtonOff_] = &spriteButtonOff;
	sprites[_ButtonOn_] = &spriteButtonOn;
	sprites[_SwitchOff_] = &spriteSwitchOff;
	sprites[_SwitchOn_] = &spriteSwitchOn;
	sprites[_LightOff_] = &spriteLightOff;
	sprites[_LightOn_] = &spriteLightOn;
	sprites[_Display0_] = &spriteDisplay0;
	sprites[_Display1_] = &spriteDisplay1;
	sprites[_Display2_] = &spriteDisplay2;
	sprites[_Display3_] = &spriteDisplay3;
	sprites[_Display4_] = &spriteDisplay4;
	sprites[_Display5_] = &spriteDisplay5;
	sprites[_Display6_] = &spriteDisplay6;
	sprites[_Display7_] = &spriteDisplay7;
	sprites[_Display8_] = &spriteDisplay8;
	sprites[_Display9_] = &spriteDisplay9;
	sprites[_Display0_] = &spriteDisplay0;
	sprites[_DisplayA_] = &spriteDisplayA;
	sprites[_DisplayB_] = &spriteDisplayB;
	sprites[_DisplayC_] = &spriteDisplayC;
	sprites[_DisplayD_] = &spriteDisplayD;
	sprites[_DisplayE_] = &spriteDisplayE;
	sprites[_DisplayF_] = &spriteDisplayF;

	Load();
}

Application::~Application()
{
	Save();
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
			case sf::Event::LostFocus:
				/*valid = true;
				dragging = false;
				connecting = false;
				connection = false;
				selecting = false;*/
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
		input.getKeyPressed(sf::Keyboard::Equal) ||
		input.getKeyPressed(sf::Keyboard::BackSpace) ||
		input.getKeyPressed(sf::Keyboard::Home))
	{
		if (selectedGate)
		{
			if (!selectedGate->GetInstantiated())
			{
				delete selectedGate;
			}
		}
	}
	
	if (input.getKeyPressed(sf::Keyboard::Num1)) selectedGate = new On(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num2)) selectedGate = new Off(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num3)) selectedGate = new AND(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num4)) selectedGate = new OR(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num5)) selectedGate = new NAND(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num6)) selectedGate = new NOR(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num7)) selectedGate = new XOR(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num8)) selectedGate = new XNOR(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num9)) selectedGate = new NOT(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Num0)) selectedGate = new Clock(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Dash)) selectedGate = new Button(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Equal)) selectedGate = new Switch(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::BackSpace)) selectedGate = new Light(input.getMousePosition() / zoom, ID);
	if (input.getKeyPressed(sf::Keyboard::Home)) selectedGate = new Display(input.getMousePosition() / zoom, ID);


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
					ID++;
				}
			}
		}

		bool clickedOnGate = false;
		for (Gate* gate : gates)
		{
			if (gate->GetInstantiated())
			{
				if (gate->m_type == _ButtonOff_ || gate->m_type == _ButtonOn_)
				{
					sf::FloatRect rect = { gate->GetWorldPosition().x + gate->rectangle.left + 3, gate->GetWorldPosition().y + gate->rectangle.top + 2, 5, 7 };
					if (rect.contains(mouseWorldPosition))
					{
						gate->m_type = _ButtonOn_;
						break;
					}
				}
				if (gate->m_type == _SwitchOff_ || gate->m_type == _SwitchOn_)
				{
					sf::FloatRect rect = { gate->GetWorldPosition().x + gate->rectangle.left + 3, gate->GetWorldPosition().y + gate->rectangle.top + 2, 5, 7 };
					if (rect.contains(mouseWorldPosition))
					{
						gate->m_type == _SwitchOff_ ? gate->m_type = _SwitchOn_ : gate->m_type = _SwitchOff_;
						break;
					}
				}
			}

			// gate
			if (gate->Clicked(mouseWorldPosition))
			{
				clickedOnGate = true;
				selectedGate = gate;
				gateWorldSave = sf::Vector2f(selectedGate->GetWorldPosition());
				gateOffsetWorldSave = mouseWorldPosition - gateWorldSave - sf::Vector2f(gate->rectangle.width / 2, gate->rectangle.height / 2);
				for (int i = 0; i < gate->inputNodes.size(); i++)
				{
					if (gate->inputNodes[i].Clicked(mouseWorldPosition))
					{
						connecting = true;
						gateA = gate;
						gateANode = &gate->inputNodes[i];
						selectedGate = nullptr;
						wireAWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->inputNodes[i].position);
						break;
					}
				}
				for (int i = 0; i < gate->outputNodes.size(); i++)
				{
					if (gate->outputNodes[i].Clicked(mouseWorldPosition))
					{
						connecting = true;
						gateA = gate;
						gateANode = &gate->outputNodes[i];
						selectedGate = nullptr;
						wireAWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->outputNodes[i].position);
						break;
					}
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
		for (Gate* gate : gates)
		{
			if (gate->m_type == _ButtonOff_)
			{
				sf::FloatRect rect = { gate->GetWorldPosition().x + gate->rectangle.left + 3, gate->GetWorldPosition().y + gate->rectangle.top + 2, 5, 7 };
				if (rect.contains(mouseWorldPosition))
				{
					gate->m_type = _ButtonOn_;
					break;
				}
			}
		}

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
				if (gate == gateA) continue;

				bool clicked = false;
				for (int i = 0; i < gate->inputNodes.size(); i++)
				{
					if (gate->inputNodes[i].Clicked(mouseWorldPosition))
					{
						connection = true;
						gateB = gate;
						gateBNode = &gate->inputNodes[i];
						selectedGate = nullptr;
						wireBWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->inputNodes[i].position);
						clicked = true;
						break;
					}
				}
				if (clicked)
				{
					break;
				}
				for (int i = 0; i < gate->outputNodes.size(); i++)
				{
					if (gate->outputNodes[i].Clicked(mouseWorldPosition))
					{
						connection = true;
						gateB = gate;
						gateBNode = &gate->outputNodes[i];
						wireBWorldSave = sf::Vector2f(gate->GetWorldPosition() + gate->outputNodes[i].position);
						clicked = true;
						break;
					}
				}
				if (clicked)
				{
					break;
				}
			}
		}
	}

	if (input.getMouseLeftUp())
	{
		// only on released...
		for (Gate* gate : gates)
		{
			if (gate->m_type == _ButtonOn_)
			{
				gate->m_type = _ButtonOff_;
			}
		}

		if (connection)
		{
			if (gateANode->type == Gate::Node::OUTPUT && gateBNode->type == Gate::Node::INPUT)
			{
				gateA->ConnectOutputToInput(gateB, gateBNode);
			}
			else if (gateANode->type == Gate::Node::INPUT && gateBNode->type == Gate::Node::OUTPUT)
			{
				gateA->ConnectInputAToOutput(gateB, gateANode);
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
				for (int i = 0; i < selectedGate->inputNodes.size(); i++)
				{
					Gate::Node* selectedNode = &selectedGate->inputNodes[i];
					if (selectedNode->connections.size() > 0)
					{
						for (int j = 0; j < selectedGate->inputNodes[i].connections.size(); j++)
						{
							Gate::Node* connectedNode = selectedGate->inputNodes[i].connections[j];

							for (int k = 0; k < selectedGate->inputNodes[i].connections[j]->connections.size(); k++)
							{
								if (selectedNode == connectedNode->connections[k])
								{
									connectedNode->connections.erase(connectedNode->connections.begin() + k);
									break;
								}
							}
						}
					}
				}
				for (int i = 0; i < selectedGate->outputNodes.size(); i++)
				{
					Gate::Node* selectedNode = &selectedGate->outputNodes[i];
					if (selectedNode->connections.size() > 0)
					{
						for (int j = 0; j < selectedNode->connections.size(); j++)
						{
							Gate::Node* connectedNode = selectedNode->connections[j];

							for (int k = 0; k < connectedNode->connections.size(); k++)
							{
								if (selectedNode == connectedNode->connections[k])
								{
									connectedNode->connections.erase(connectedNode->connections.begin() + k);
									break;
								}
							}
						}
					}
				}
				for (int i = 0; i < gates.size(); i++)
				{
					if (gates[i] == selectedGate)
					{
						gates.erase(gates.begin() + i);
						UpdateGateIDs();
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

	// Need to loop through backwards recursively? to simulate gates taking small amount of time to process (clock pulses - d flipflop) overkill maybe
	for (Gate* gate : gates)
	{
		gate->Update(deltaTime);
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
		square.setFillColor(gateANode->type == Gate::Node::OUTPUT ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black);
		window->draw(square);

		sf::Vertex line[] =
		{
			sf::Vertex(wireAWorldSave + sf::Vector2f(0.5f, 0.5f), gateANode->type == Gate::Node::OUTPUT ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black),
			sf::Vertex(mouseWorldPosition + sf::Vector2f(0.5f, 0.5f), gateANode->type == Gate::Node::OUTPUT ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black)
			
		};

		if (connection)
		{
			line[1] = sf::Vertex(wireBWorldSave + sf::Vector2f(0.5f, 0.5f), gateANode->type == Gate::Node::OUTPUT ? gateA->output ? sf::Color::Red : sf::Color::Black : sf::Color::Black);
			square.setPosition(wireBWorldSave);
			window->draw(square);
		}

		window->draw(line, 2, sf::Lines);
	}

	for (Gate* gate : gates)
	{
		if (gate->outputNodes.size() == 0) continue;

		for (Gate::Node* connection : gate->outputNodes[0].connections)
		{
			if (connection)
			{
				sf::Vector2f connectorPosition = sf::Vector2f(gate->GetWorldPosition() + gate->outputNodes[0].position);
				sf::Vector2f otherConnectorPosition = sf::Vector2f(connection->parent->GetWorldPosition() + connection->position);

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
	}

	window->display();
}

void Application::Save()
{
	std::ofstream file;
	file.open("save.txt", std::ofstream::out | std::ofstream::trunc);
	
	for (Gate* gate : gates)
	{
		file << gate->m_type << "," << gate->GetWorldPosition().x << "," << gate->GetWorldPosition().y << ",";
	}
	file << ":";
	for (Gate* gate : gates)
	{
		if (gate->outputNodes.size() == 0) continue;

		for (const Gate::Node& node : gate->outputNodes)
		{
			for (Gate::Node* connection : node.connections)
			{
				file << gate->ID << "," << node.ID << "," << connection->parent->ID << "," << connection->ID << ",";
			}
		}
	}

	file.close();
}

void Application::Load()
{
	std::ifstream file;
	file.open("save.txt");
	std::string line;

	if (file.is_open())
	{
		getline(file, line);
		file.close();
	}

	std::cout << line;

	std::stringstream ss(line);

	for (int i; ss >> i;) {

		int x, y;
		if (ss.peek() == ',')
			ss.ignore();
		ss >> x;
		if (ss.peek() == ',')
			ss.ignore();
		ss >> y;
		if (ss.peek() == ',')
			ss.ignore();
		

		if (i == _NOT_) gates.push_back(new NOT(sf::Vector2i(x, y), ID++));
		else if (i == _AND_) gates.push_back(new AND(sf::Vector2i(x, y), ID++));
		else if (i == _OR_) gates.push_back(new OR(sf::Vector2i(x, y), ID++));
		else if (i == _NAND_) gates.push_back(new NAND(sf::Vector2i(x, y), ID++));
		else if (i == _NOR_) gates.push_back(new NOR(sf::Vector2i(x, y), ID++));
		else if (i == _XOR_) gates.push_back(new XOR(sf::Vector2i(x, y), ID++));
		else if (i == _XNOR_) gates.push_back(new XNOR(sf::Vector2i(x, y), ID++));
		else if (i == _On_) gates.push_back(new On(sf::Vector2i(x, y), ID++));
		else if (i == _Off_) gates.push_back(new Off(sf::Vector2i(x, y), ID++));
		else if (i == _ClockOff_) gates.push_back(new Clock(sf::Vector2i(x, y), ID++));
		else if (i == _ClockOn_) gates.push_back(new Clock(sf::Vector2i(x, y), ID++));
		else if (i == _ButtonOff_) gates.push_back(new Button(sf::Vector2i(x, y), ID++));
		else if (i == _ButtonOn_) gates.push_back(new Button(sf::Vector2i(x, y), ID++));
		else if (i == _SwitchOff_) gates.push_back(new Switch(sf::Vector2i(x, y), ID++));
		else if (i == _SwitchOn_) gates.push_back(new Switch(sf::Vector2i(x, y), ID++));
		else if (i == _LightOff_) gates.push_back(new Light(sf::Vector2i(x, y), ID++));
		else if (i == _LightOn_) gates.push_back(new Light(sf::Vector2i(x, y), ID++));
		else if (i == _Display0_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display1_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display2_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display3_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display4_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display5_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display6_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display7_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display8_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _Display9_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _DisplayA_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _DisplayB_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _DisplayC_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _DisplayD_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _DisplayE_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));
		else if (i == _DisplayF_) gates.push_back(new Display(sf::Vector2i(x, y), ID++));

		if (ss.peek() == ':')
		{
			ss.ignore();
			break;
		}
	}
	for (int i; ss >> i;)
	{
		int gateID = i;
		int nodeID;
		int otherGateID;
		int otherNodeID;
	
		if (ss.peek() == ',') ss.ignore();
		ss >> nodeID;
		if (ss.peek() == ',') ss.ignore();
		ss >> otherGateID;
		if (ss.peek() == ',') ss.ignore();
		ss >> otherNodeID;
		if (ss.peek() == ',') ss.ignore();
	
		gates[gateID]->ConnectOutputToInput(gates[otherGateID], &gates[otherGateID]->inputNodes[otherNodeID]);
	}

	for (Gate* gate : gates)
	{
		gate->SetInstantiated(true);
	}

}

void Application::UpdateGateIDs()
{
	for (int i = 0; i < gates.size(); i++)
	{
		gates[i]->ID = i;
	}
	ID = gates.size();
}


