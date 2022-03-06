#pragma once
#include <SFML/Graphics.hpp>

class Input
{
public:

	Input();

	bool getKeyPressed(int);
	void setKeyPressed(int);
	void setKeyReleased(int);
	bool getKeyDown(int);
	void setLastKeys();
	inline sf::Vector2i getMousePosition() { return mouse_position; }
	inline bool getMouseLeftPressed() { return mouse_left_pressed; }
	inline bool getMouseRightPressed() { return mouse_right_pressed; }
	bool getMouseLeftDown();
	bool getMouseRightDown();
	bool getMouseLeftUp();
	bool getMouseRightUp();
	void setLastMouse();

	inline void setMouseLeftPressed(bool mouseLeftDown) { mouse_left_pressed = mouseLeftDown; }
	inline void setMouseRightPressed(bool mouseRightDown) { mouse_right_pressed = mouseRightDown; }
	inline void setMousePosition(int x, int y) { mouse_position.x = x; mouse_position.y = y; }
	inline void setMouseWheelDelta(int delta) { mouse_wheel_delta = delta; }
	inline int getMouseWheelDelta() { return mouse_wheel_delta; }

private:
	
	sf::Vector2i mouse_position;
	bool mouse_left_pressed;
	bool mouse_right_pressed;
	int mouse_wheel_delta;
	bool keys[256]{ false };		
	bool last_keys[256]{ false };
	bool last_mouse_left_pressed;
	bool last_mouse_right_pressed;
};


