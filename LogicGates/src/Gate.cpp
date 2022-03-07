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
	if(thisOutput->connection) 
		thisOutput->connection->connection = nullptr;
	if(otherInput->connection)
		otherInput->connection->connection = nullptr;
	thisOutput->connection = otherInput;
	otherInput->connection = thisOutput;
	thisOutput->parent = this;
	otherInput->parent = gate;
}

void Gate::ConnectInputAToOutput(Gate* gate, int input)
{
	Node* thisInput = &m_nodes[input];
	Node* otherOutput= &gate->m_nodes[2];
	if(thisInput->connection)
		thisInput->connection->connection = nullptr;
	if(otherOutput->connection)
		otherOutput->connection->connection = nullptr;
	thisInput->connection = otherOutput;
	otherOutput->connection = thisInput;
	thisInput->parent = this;
	otherOutput->parent = gate;
}


