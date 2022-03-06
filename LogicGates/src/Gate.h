#pragma once
#include "SFML/Graphics.hpp"


#define _NOT_		0
#define _AND_		1
#define _OR_		2
#define _NAND_		3
#define _NOR_		4
#define _XOR_		5
#define _XNOR_		6

class Gate
{
public:

	struct Node
	{
		Gate* parent;
		Node* connection = nullptr;
		sf::Vector2i position;
		sf::FloatRect rectangle;

		bool Clicked(sf::Vector2f mouse) 
		{ 
			sf::FloatRect worldRectangle = rectangle;
			worldRectangle.left += parent->m_worldPosition.x;
			worldRectangle.top += parent->m_worldPosition.y;
			return worldRectangle.contains(mouse);
		}
	};

	Gate(const Gate& gate);
	Gate(const sf::Vector2i& worldPosition);
	~Gate();

	void SetWorldPosition(const sf::Vector2i& worldPosition); 
	inline const sf::Vector2i& GetWorldPosition() { return m_worldPosition; }
	inline void SetInstantiated(bool instantiated) { m_instantiated = instantiated; }
	inline bool GetInstantiated() { return m_instantiated; }
	inline int GetType() { return m_type; }

	void ConnectOutputToInput(Gate* gate, int input);
	void ConnectInputAToOutput(Gate* gate, int input);

	bool Clicked(sf::Vector2f mouse);

	//bool AABB(sf::Fl);

	Node m_nodes[3];

	sf::FloatRect rectangle;

private:
	sf::Vector2i m_worldPosition;
	bool m_instantiated;

protected:
	int m_type;

	
};




class NOT : public Gate
{
public:
	NOT(const Gate& gate) :
		Gate(gate)
	{
	}

	NOT(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _NOT_;
	}

	~NOT()
	{
	}
};

class AND : public Gate
{
public:
	AND(const Gate& gate) :
		Gate(gate)
	{
	}

	AND(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _AND_;
	}

	~AND()
	{
	}
};

class OR : public Gate
{
public:
	OR(const Gate& gate) :
		Gate(gate)
	{
	}

	OR(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _OR_;
	}

	~OR()
	{
	}
};

class NAND : public Gate
{
public:
	NAND(const Gate& gate) :
		Gate(gate)
	{
	}

	NAND(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _NAND_;
	}

	~NAND()
	{
	}
};

class NOR : public Gate
{
public:
	NOR(const Gate& gate) :
		Gate(gate)
	{
	}
	NOR(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _NOR_;
	}

	~NOR()
	{
	}
};

class XOR : public Gate
{
public:
	XOR(const Gate& gate) :
		Gate(gate)
	{
	}

	XOR(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _XOR_;
	}

	~XOR()
	{
	}
};

class XNOR : public Gate
{
public:
	XNOR(const Gate& gate) :
		Gate(gate)
	{
	}

	XNOR(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _XNOR_;
	}

	~XNOR()
	{
	}
};


