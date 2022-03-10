#include "Gate.h"

Gate::Gate(const Gate& gate) :
	m_worldPosition(gate.m_worldPosition),
	m_type(gate.m_type),
	m_instantiated(false)
{
}

Gate::Gate(const sf::Vector2i& gridPosition) :
	m_worldPosition(gridPosition),
	m_instantiated(false)//,
	//gateRect(0, 0, 25, 9)
{
	rectangle = { 0, 0, 25, 9 };
	
	m_nodes[0].parent = this;
	m_nodes[1].parent = this;
	m_nodes[2].parent = this;

	m_nodes[0].position = sf::Vector2i(1, 2);
	m_nodes[1].position = sf::Vector2i(1, 6);
	m_nodes[2].position = sf::Vector2i(23, 4);

	m_nodes[0].rectangle = { 0, 0, 4, 4 };
	m_nodes[1].rectangle = { 0, 5, 4, 4 };
	m_nodes[2].rectangle = { 21, 2, 5, 5 };


	//nodePositions[0] = sf::Vector2i(1, 2);
	//nodePositions[1] = sf::Vector2i(1, 6);
	//nodePositions[2] = sf::Vector2i(23, 4);

	//nodeRects[0] = { 0, 0, 4, 4};
	//nodeRects[1] = { 0, 5, 4, 4 };
	//nodeRects[2] = { 21, 2, 5, 5 };
}

Gate::~Gate()
{
}

void Gate::SetWorldPosition(const sf::Vector2i& worldPosition)
{
	m_worldPosition = worldPosition - sf::Vector2i(rectangle.width / 2, rectangle.height / 2);
}

bool Gate::Clicked(sf::Vector2f mouse)
{
	sf::FloatRect worldRectangle = rectangle;
	worldRectangle.left += m_worldPosition.x;
	worldRectangle.top += m_worldPosition.y;
	return worldRectangle.contains(mouse);
}

void Gate::ConnectOutputToInput(Gate* gate, int input)
{
	Node* thisOutput = &m_nodes[2];
	Node* otherInput = &gate->m_nodes[input];

	bool found = false;
	for (Node* connection : thisOutput->connections)
	{
		if (connection == otherInput)
		{
			found = true;
			break;
		}
	}
	// If output does not allready exist
	if (!found)
	{
		// add connection
		thisOutput->connections.push_back(otherInput);
		if (otherInput->connections.size() > 0)
		{
			Node* previousOutputNode = otherInput->connections[0];
			for (int i = 0; i < previousOutputNode->connections.size(); i++)
			{
				if (previousOutputNode->connections[i] == otherInput)
				{
					previousOutputNode->connections.erase(previousOutputNode->connections.begin() + i);
					break;
				}
			}
		}
		
		otherInput->connections.clear();
		otherInput->connections.push_back(thisOutput);
		thisOutput->parent = this;
		otherInput->parent = gate;
	}
}

void Gate::ConnectInputAToOutput(Gate* gate, int input)
{
	Node* thisInput = &m_nodes[input];
	Node* otherOutput = &gate->m_nodes[2];

	otherOutput->parent->ConnectOutputToInput(thisInput->parent, input);

	//bool found = false;
	//for (Node* connection : otherOutput->connections)
	//{
	//	if (connection == thisInput)
	//	{
	//		found = true;
	//		break;
	//	}
	//}
	//if (!found)
	//{
	//	thisInput->connections.clear();
	//	thisInput->connections.push_back(otherOutput);
	//
	//	otherOutput->connections.push_back(thisInput);
	//	thisInput->parent = this;
	//	otherOutput->parent = gate;
	//}




	/*Node* thisInput = &m_nodes[input];
	Node* otherOutput = &gate->m_nodes[2];

	bool found = false;
	for (Node* connection : otherOutput->connections)
	{
		if (connection == thisInput)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		thisInput->connections.clear();
		thisInput->connections.push_back(otherOutput);

		otherOutput->connections.push_back(thisInput);
		thisInput->parent = this;
		otherOutput->parent = gate;
	}*/
}


