#include "Input.h"

Input::Input() :
	mouse_position(sf::Vector2i(0, 0)),
	mouse_left_pressed(false)
{
}

bool Input::getKeyPressed(int key)
{
	return keys[key];
}

void Input::setKeyPressed(int key)
{
	if (key >= 0)
	{
		keys[key] = true;
	}
}

void Input::setKeyReleased(int key)
{
	if (key >= 0)
	{
		keys[key] = false;
	}
}

bool Input::getKeyDown(int key)
{
	return keys[key] && !last_keys[key];
}

void Input::setLastKeys()
{
	memcpy(last_keys, keys, sizeof(bool) * 256);
}

bool Input::getMouseLeftDown()
{
	return mouse_left_pressed && !last_mouse_left_pressed;
}

bool Input::getMouseRightDown()
{
	return mouse_right_pressed && !last_mouse_right_pressed;
}

bool Input::getMouseLeftUp()
{
	return !mouse_left_pressed && last_mouse_left_pressed;;
}

bool Input::getMouseRightUp()
{
	return !mouse_right_pressed && last_mouse_right_pressed;;
}

void Input::setLastMouse()
{
	last_mouse_left_pressed = mouse_left_pressed;
	last_mouse_right_pressed = mouse_right_pressed;
}




