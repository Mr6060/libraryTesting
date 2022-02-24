#pragma once
#include <papaya.h>
#include <SFML/Graphics/RenderWindow.hpp>

class Application
{
public:
	void run();

private:
	StateMachine m_machine;
	MyWindow::Window m_window;
};