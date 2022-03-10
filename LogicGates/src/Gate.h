#pragma once
#include "SFML/Graphics.hpp"

#define _NOT_		0
#define _AND_		1
#define _OR_		2
#define _NAND_		3
#define _NOR_		4
#define _XOR_		5
#define _XNOR_		6
#define _On_		7
#define _Off_		8
#define _Clock_		9
#define _Button_	10
#define _Switch_	11

class Gate
{
public:

	struct Node
	{
		Gate* parent;
		std::vector<Node*> connections;

		//Node* connection = nullptr;
		sf::Vector2i position;
		sf::FloatRect rectangle;
		bool on = false;

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

	virtual void Update() {}

	Node m_nodes[3];

	bool output = false;

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

		m_nodes[0].position = sf::Vector2i(1, 4);
		m_nodes[1].position = sf::Vector2i(0, 0);

		m_nodes[0].rectangle = { 0, 2, 4, 4 };
		m_nodes[1].rectangle = { 0, 0, 0, 0 };
	}

	~NOT()
	{
	}

	void Update() override
	{
		if (m_nodes[0].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = m_nodes[0].connections[0]->parent->output;
			output = !a;
		}
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

	void Update() override
	{
		if (m_nodes[0].connections.empty() || m_nodes[1].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = m_nodes[0].connections[0]->parent->output;
			bool b = m_nodes[1].connections[0]->parent->output;
			output = a && b;
		}
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

	void Update() override
	{
		if (m_nodes[0].connections.empty() || m_nodes[1].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = m_nodes[0].connections[0]->parent->output;
			bool b = m_nodes[1].connections[0]->parent->output;
			output = a || b;
		}
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

	void Update() override
	{
		if (m_nodes[0].connections.empty() || m_nodes[1].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = m_nodes[0].connections[0]->parent->output;
			bool b = m_nodes[1].connections[0]->parent->output;
			output = !(a && b);
		}
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

	void Update() override
	{
		if (m_nodes[0].connections.empty() || m_nodes[1].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = m_nodes[0].connections[0]->parent->output;
			bool b = m_nodes[1].connections[0]->parent->output;
			output = !(a || b);
		}
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

	void Update() override
	{
		if (m_nodes[0].connections.empty() || m_nodes[1].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = m_nodes[0].connections[0]->parent->output;
			bool b = m_nodes[1].connections[0]->parent->output;
			output = (a && !b) || (b && !a);
		}
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

	void Update() override
	{
		output = false;

		if (m_nodes[0].connections.empty() || m_nodes[1].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = m_nodes[0].connections[0]->parent->output;
			bool b = m_nodes[1].connections[0]->parent->output;
			output = !((a && !b) || (b && !a));
		}
	}
};

class On : public Gate
{
public:
	On(const Gate& gate) :
		Gate(gate)
	{

	}

	On(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _On_;

		rectangle = { 0, 0, 19, 11 };

		m_nodes[0].position = sf::Vector2i(0, 0);
		m_nodes[1].position = sf::Vector2i(0, 0);
		m_nodes[2].position = sf::Vector2i(17, 5);

		m_nodes[0].rectangle = { 0, 0, 0, 0 };
		m_nodes[1].rectangle = { 0, 0, 0, 0 };
		m_nodes[2].rectangle = { 17, 3, 5, 5 };
	}

	~On()
	{
	}

	void Update() override
	{
		output = true;
	}
};

class Off : public Gate
{
public:
	Off(const Gate& gate) :
		Gate(gate)
	{

	}

	Off(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _Off_;

		rectangle = { 0, 0, 19, 11 };

		m_nodes[0].position = sf::Vector2i(0, 0);
		m_nodes[1].position = sf::Vector2i(0, 0);
		m_nodes[2].position = sf::Vector2i(17, 5);

		m_nodes[0].rectangle = { 0, 0, 0, 0 };
		m_nodes[1].rectangle = { 0, 0, 0, 0 };
		m_nodes[2].rectangle = { 17, 3, 5, 5 };
	}

	~Off()
	{
	}

	void Update() override
	{
		output = false;
	}
};

class Clock : public Gate
{
public:
	Clock(const Gate& gate) :
		Gate(gate)
	{

	}

	Clock(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _Clock_;

		rectangle = { 0, 0, 19, 11 };

		m_nodes[0].position = sf::Vector2i(0, 0);
		m_nodes[1].position = sf::Vector2i(0, 0);
		m_nodes[2].position = sf::Vector2i(17, 5);

		m_nodes[0].rectangle = { 0, 0, 0, 0 };
		m_nodes[1].rectangle = { 0, 0, 0, 0 };
		m_nodes[2].rectangle = { 17, 3, 5, 5 };
	}

	~Clock()
	{
	}

	void Update() override
	{
		output = false;
	}
};

class Button : public Gate
{
public:
	Button(const Gate& gate) :
		Gate(gate)
	{

	}

	Button(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _Button_;

		rectangle = { 0, 0, 19, 11 };

		m_nodes[0].position = sf::Vector2i(0, 0);
		m_nodes[1].position = sf::Vector2i(0, 0);
		m_nodes[2].position = sf::Vector2i(17, 5);

		m_nodes[0].rectangle = { 0, 0, 0, 0 };
		m_nodes[1].rectangle = { 0, 0, 0, 0 };
		m_nodes[2].rectangle = { 17, 3, 5, 5 };
	}

	~Button()
	{
	}

	void Update() override
	{
		output = false;
	}
};

class Switch : public Gate
{
public:
	Switch(const Gate& gate) :
		Gate(gate)
	{

	}

	Switch(const sf::Vector2i& gridPosition) :
		Gate(gridPosition)
	{
		m_type = _Switch_;

		rectangle = { 0, 0, 19, 11 };

		m_nodes[0].position = sf::Vector2i(0, 0);
		m_nodes[1].position = sf::Vector2i(0, 0);
		m_nodes[2].position = sf::Vector2i(17, 5);

		m_nodes[0].rectangle = { 0, 0, 0, 0 };
		m_nodes[1].rectangle = { 0, 0, 0, 0 };
		m_nodes[2].rectangle = { 17, 3, 5, 5 };
	}

	~Switch()
	{
	}

	void Update() override
	{
		output = false;
	}
};



