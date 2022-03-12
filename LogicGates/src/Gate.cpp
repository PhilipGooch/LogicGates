#include "Gate.h"

Gate::Gate(const Gate& gate) :
	m_worldPosition(gate.m_worldPosition),
	m_type(gate.m_type),
	m_instantiated(false)
{
}

Gate::Gate(const sf::Vector2i& gridPosition, int id) :
	m_worldPosition(gridPosition),
	m_instantiated(false),
	ID(id)
{
	
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

void Gate::ConnectOutputToInput(Gate* gate, Node* input)
{
	Node* thisOutput = &outputNodes[0];
	Node* otherInput = input;

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

void Gate::ConnectInputAToOutput(Gate* gate, Node* input)
{
	Node* thisInput = input;
	Node* otherOutput = &gate->outputNodes[0];

	otherOutput->parent->ConnectOutputToInput(thisInput->parent, input);

}


