#include "app.h"
#include "states/playState.h"


void Application::run(){
	// Create render window
	//m_window.create({ 640, 480 }, "Engine Test v3.0", sf::Style::Titlebar | sf::Style::Close);
	//m_window.setFramerateLimit(30);

	const int WIDTH = 1280;
	const int HEIGHT = 720;

	sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
	m_window.create({ 1280, 720 }, "Test", sf::Style::Titlebar | sf::Style::Close );
	m_window.setView(view);
	m_window.setFramerateLimit(60);

	//MyWindow::Window window = MyWindow::Window("Test", sf::Vector2u(400, 400), 60);
	// Initialize the engine
	m_machine.Run(StateMachine::build<playState>(m_machine, m_window, true));

	// Main loop
	while (m_machine.running())
	{
		m_machine.NextState();
		m_machine.Update();
		m_machine.Draw();
	}

	// Leaving the scope of 'Application' will cleanup the engine
}