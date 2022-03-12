#pragma once
#include "SFML/Graphics.hpp"

#define _NOT_		0
#define _AND_		1
#define _OR_		2
#define _NAND_		3
#define _NOR_		4
#define _XOR_		5
#define _XNOR_		6
#define _TRI_		7
#define _On_		8
#define _Off_		9
#define _ClockOff_	10
#define _ClockOn_	11
#define _ButtonOff_	12
#define _ButtonOn_	13
#define _SwitchOff_	14
#define _SwitchOn_	15
#define _LightOff_	16
#define _LightOn_	17
#define _Display0_	18
#define _Display1_	19
#define _Display2_	20
#define _Display3_	21
#define _Display4_	22
#define _Display5_	23
#define _Display6_	24
#define _Display7_	25
#define _Display8_	26
#define _Display9_	27
#define _DisplayA_	28
#define _DisplayB_	29
#define _DisplayC_	30
#define _DisplayD_	31
#define _DisplayE_	32
#define _DisplayF_	33

class Gate
{
public:

	struct Node
	{
		enum TYPE
		{
			INPUT,
			OUTPUT
		};
		Gate* parent;
		std::vector<Node*> connections;
		sf::Vector2i position;
		sf::FloatRect rectangle;
		TYPE type;
		int ID;

		bool Clicked(sf::Vector2f mouse) 
		{ 
			sf::FloatRect worldRectangle = rectangle;
			worldRectangle.left += parent->m_worldPosition.x;
			worldRectangle.top += parent->m_worldPosition.y;
			return worldRectangle.contains(mouse);
		}
	};

	Gate(const Gate& gate);
	Gate(const sf::Vector2i& worldPosition, int id);
	~Gate();

	void SetWorldPosition(const sf::Vector2i& worldPosition); 
	inline const sf::Vector2i& GetWorldPosition() { return m_worldPosition; }
	inline void SetInstantiated(bool instantiated) { m_instantiated = instantiated; }
	inline bool GetInstantiated() { return m_instantiated; }
	inline int GetType() { return m_type; }

	void ConnectOutputToInput(Gate* gate, Node* input);
	void ConnectInputAToOutput(Gate* gate, Node* input);

	bool Clicked(sf::Vector2f mouse);

	virtual void Update(float deltaTime) {}

	//Node m_nodes[3];

	std::vector<Node> inputNodes;
	std::vector<Node> outputNodes;

	bool output = false;

	sf::FloatRect rectangle;

	int m_type;

	int ID;

	int nodeID = 0;

private:
	sf::Vector2i m_worldPosition;
	bool m_instantiated;

protected:
	

	
};




class NOT : public Gate
{
public:
	NOT(const Gate& gate) :
		Gate(gate)
	{
	}

	NOT(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _NOT_;

		rectangle = { 0, 0, 25, 9 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 4);
		node.rectangle = { 0, 2, 4, 4 };
		inputNodes.push_back(node);

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(23, 4);
		node.rectangle = { 21, 2, 5, 5 };
		outputNodes.push_back(node);

	}

	~NOT()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				output = false;
				return;
			}
		}

		bool a = inputNodes[0].connections[0]->parent->output;
		output = !a;
	}
};

class AND : public Gate
{
public:
	AND(const Gate& gate) :
		Gate(gate)
	{
	}

	AND(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _AND_;

		rectangle = { 0, 0, 25, 9 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 2);
		node.rectangle = { 0, 0, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 1;
		node.position = sf::Vector2i(1, 6);
		node.rectangle = { 0, 5, 4, 4 };
		inputNodes.push_back(node);

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(23, 4);
		node.rectangle = { 21, 2, 5, 5 };
		outputNodes.push_back(node);
	}

	~AND()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				output = false;
				return;
			}
		}
		
		bool a = inputNodes[0].connections[0]->parent->output;
		bool b = inputNodes[1].connections[0]->parent->output;
		output = a && b;
		
	}
};

class OR : public Gate
{
public:
	OR(const Gate& gate) :
		Gate(gate)
	{
	}

	OR(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _OR_;

		rectangle = { 0, 0, 25, 9 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 2);
		node.rectangle = { 0, 0, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 1;
		node.position = sf::Vector2i(1, 6);
		node.rectangle = { 0, 5, 4, 4 };
		inputNodes.push_back(node);

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(23, 4);
		node.rectangle = { 21, 2, 5, 5 };
		outputNodes.push_back(node);
	}

	~OR()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				output = false;
				return;
			}
		}
		bool a = inputNodes[0].connections[0]->parent->output;
		bool b = inputNodes[1].connections[0]->parent->output;
		output = a || b;
	}
};

class NAND : public Gate
{
public:
	NAND(const Gate& gate) :
		Gate(gate)
	{
	}

	NAND(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _NAND_;

		rectangle = { 0, 0, 25, 9 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 2);
		node.rectangle = { 0, 0, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 1;
		node.position = sf::Vector2i(1, 6);
		node.rectangle = { 0, 5, 4, 4 };
		inputNodes.push_back(node);

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(23, 4);
		node.rectangle = { 21, 2, 5, 5 };
		outputNodes.push_back(node);
	}

	~NAND()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				output = false;
				return;
			}
		}

		bool a = inputNodes[0].connections[0]->parent->output;
		bool b = inputNodes[1].connections[0]->parent->output;
		output = !(a && b);
	}
};

class NOR : public Gate
{
public:
	NOR(const Gate& gate) :
		Gate(gate)
	{
	}
	NOR(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _NOR_;

		rectangle = { 0, 0, 25, 9 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 2);
		node.rectangle = { 0, 0, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 1;
		node.position = sf::Vector2i(1, 6);
		node.rectangle = { 0, 5, 4, 4 };
		inputNodes.push_back(node);

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(23, 4);
		node.rectangle = { 21, 2, 5, 5 };
		outputNodes.push_back(node);
	}

	~NOR()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				output = false;
				return;
			}
		}

		bool a = inputNodes[0].connections[0]->parent->output;
		bool b = inputNodes[1].connections[0]->parent->output;
		output = !(a || b);
	}
};

class XOR : public Gate
{
public:
	XOR(const Gate& gate) :
		Gate(gate)
	{
	}

	XOR(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _XOR_;

		rectangle = { 0, 0, 25, 9 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 2);
		node.rectangle = { 0, 0, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 1;
		node.position = sf::Vector2i(1, 6);
		node.rectangle = { 0, 5, 4, 4 };
		inputNodes.push_back(node);

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(23, 4);
		node.rectangle = { 21, 2, 5, 5 };
		outputNodes.push_back(node);
	}

	~XOR()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				output = false;
				return;
			}
		}

		bool a = inputNodes[0].connections[0]->parent->output;
		bool b = inputNodes[1].connections[0]->parent->output;
		output = (a && !b) || (b && !a);
	}
};

class XNOR : public Gate
{
public:
	XNOR(const Gate& gate) :
		Gate(gate)
	{
	}

	XNOR(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _XNOR_;

		rectangle = { 0, 0, 25, 9 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 2);
		node.rectangle = { 0, 0, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 1;
		node.position = sf::Vector2i(1, 6);
		node.rectangle = { 0, 5, 4, 4 };
		inputNodes.push_back(node);

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(23, 4);
		node.rectangle = { 21, 2, 5, 5 };
		outputNodes.push_back(node);
	}

	~XNOR()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				output = false;
				return;
			}
		}

		bool a = inputNodes[0].connections[0]->parent->output;
		bool b = inputNodes[1].connections[0]->parent->output;
		output = !((a && !b) || (b && !a));
	}
};

class On : public Gate
{
public:
	On(const Gate& gate) :
		Gate(gate)
	{

	}

	On(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _On_;

		rectangle = { 0, 0, 19, 11 };

		Node node;
		node.parent = this;

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(17, 5);
		node.rectangle = { 17, 3, 5, 5 };
		outputNodes.push_back(node);
	}

	~On()
	{
	}

	void Update(float deltaTime) override
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

	Off(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _Off_;

		rectangle = { 0, 0, 19, 11 };

		Node node;
		node.parent = this;

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(17, 5);
		node.rectangle = { 17, 3, 5, 5 };
		outputNodes.push_back(node);
	}

	~Off()
	{
	}

	void Update(float deltaTime) override
	{
		output = false;
	}
};
#include <iostream>
class Clock : public Gate
{
public:
	Clock(const Gate& gate) :
		Gate(gate)
	{

	}

	Clock(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _ClockOff_;

		rectangle = { 0, 0, 19, 11 };

		Node node;
		node.parent = this;

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(17, 5);
		node.rectangle = { 17, 3, 5, 5 };
		outputNodes.push_back(node);
	}

	~Clock()
	{
	}

	void Update(float deltaTime) override
	{
		timer += deltaTime;
		
		if (pulsing)
		{
			if (timer > onTime)
			{
				output = !output;
				timer -= onTime;
				pulsing = !pulsing;
			}
		}
		else
		{
			if (timer > offTime)
			{
				output = !output;
				timer -= offTime;
				pulsing = !pulsing;
			}
		}

		if (output == true)
		{
			m_type = _ClockOn_;
		}
		else
		{
			m_type = _ClockOff_;
		}


		/*if (timer > pulseTime)
		{
			output = !output;
			timer -= pulseTime;

			if (output == true)
			{
				m_type = _ClockOn_;
			}
			else
			{
				m_type = _ClockOff_;
			}
		}*/

	}

private:
	float timer = 0.0f;
	float pulseTime = 500.0f;
	bool pulse = false;
	bool pulsing = false;
	float onTime = 50.0f;
	float offTime = 450.0f;
};

class Button : public Gate
{
public:
	Button(const Gate& gate) :
		Gate(gate)
	{

	}

	Button(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _ButtonOff_;

		rectangle = { 0, 0, 19, 11 };

		Node node;
		node.parent = this;

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(17, 5);
		node.rectangle = { 17, 3, 5, 5 };
		outputNodes.push_back(node);
	}

	~Button()
	{
	}

	void Update(float deltaTime) override
	{
		if (m_type == _ButtonOff_)
		{
			output = false;
		}
		else if (m_type == _ButtonOn_)
		{
			output = true;
		}
	}
};

class Switch : public Gate
{
public:
	Switch(const Gate& gate) :
		Gate(gate)
	{

	}

	Switch(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _SwitchOff_;

		rectangle = { 0, 0, 19, 11 };

		Node node;
		node.parent = this;

		node.type = Node::OUTPUT;

		node.ID = 0;
		node.position = sf::Vector2i(17, 5);
		node.rectangle = { 17, 3, 5, 5 };
		outputNodes.push_back(node);
	}

	~Switch()
	{
	}

	void Update(float deltaTime) override
	{
		if (m_type == _SwitchOff_)
		{
			output = false;
		}
		else if (m_type == _SwitchOn_)
		{
			output = true;
		}
		
	}
};

class Light : public Gate
{
public:
	Light(const Gate& gate) :
		Gate(gate)
	{

	}

	Light(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _LightOff_;

		rectangle = { 0, 0, 7, 11 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(3, 9);
		node.rectangle = { 1, 7, 4, 4 };
		inputNodes.push_back(node);
	}

	~Light()
	{
	}

	void Update(float deltaTime) override
	{
		if (inputNodes[0].connections.empty())
		{
			output = false;
		}
		else
		{
			bool a = inputNodes[0].connections[0]->parent->output;
			output = a;
		}


		if (output == true)
		{
			m_type = _LightOn_;
		}
		else
		{
			m_type = _LightOff_;
		}

	}
};

class Display : public Gate
{
public:
	Display(const Gate& gate) :
		Gate(gate)
	{

	}

	Display(const sf::Vector2i& gridPosition, int id) :
		Gate(gridPosition, id)
	{
		m_type = _Display0_;

		rectangle = { 0, 0, 18, 15 };

		Node node;
		node.parent = this;

		node.type = Node::INPUT;

		node.ID = 0;
		node.position = sf::Vector2i(1, 1);
		node.rectangle = { 0, 0, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 1;
		node.position = sf::Vector2i(1, 5);
		node.rectangle = { 0, 4, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 2;
		node.position = sf::Vector2i(1, 9);
		node.rectangle = { 0, 8, 4, 4 };
		inputNodes.push_back(node);

		node.ID = 3;
		node.position = sf::Vector2i(1, 13);
		node.rectangle = { 0, 12, 4, 3 };
		inputNodes.push_back(node);
	}

	~Display()
	{
	}

	void Update(float deltaTime) override
	{
		for (const Node& node : inputNodes)
		{
			if (node.connections.empty())
			{
				return;
			}
		}

		bool a = inputNodes[0].connections[0]->parent->output;
		bool b = inputNodes[1].connections[0]->parent->output;
		bool c = inputNodes[2].connections[0]->parent->output;
		bool d = inputNodes[3].connections[0]->parent->output;

		int A = 0b0001; // 1
		int B = 0b0010; // 2
		int C = 0b0100; // 4
		int D = 0b1000; // 8

		int sum = 0b0000; // 0

		if (a) sum |= A;
		if (b) sum |= B;
		if (c) sum |= C;
		if (d) sum |= D;

		m_type = _Display0_ + sum;

	}
};


