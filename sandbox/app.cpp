#include "app.h"
#include "states/testState.h"


void Application::run(){
	// Create render window
	m_window.create({ 640, 480 }, "Engine Test v3.0", sf::Style::Titlebar | sf::Style::Close);
	m_window.setFramerateLimit(30);

	// Initialize the engine
	m_machine.Run(StateMachine::build<testState>(m_machine, m_window, true));

	// Main loop
	while (m_machine.running())
	{
		m_machine.NextState();
		m_machine.Update();
		m_machine.Draw();
	}

	// Leaving the scope of 'Application' will cleanup the engine
}