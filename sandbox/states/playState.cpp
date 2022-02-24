#include "playState.h"
#include "testState.h"
#include <memory>
#include <iostream>

playState::playState(StateMachine& machine, MyWindow::Window& window, const bool replace)
	: State{ machine, window, replace }
	, m_alpha{ 255, 0, 0, 255 } // Start off opaque
{

	// Fill the fader surface with black
	m_fader.setFillColor(m_alpha);
	m_fader.setSize(sf::Vector2f(400.0f, 400.0f));

	std::cout << "playState Init\n";
}

void playState::pause() {
	std::cout << "Play State Paused \n";
}

void playState::resume() {
	std::cout << "Play State resumed \n";
}

void playState::update() {
	sf::Event ev;
	//for (auto event = sf::Event{}; m_window.GetWindow().pollEvent(event);)
	while(m_window.GetWindow().pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			m_machine.Quit();
			break;

		case sf::Event::Resized:
			
			m_window.SetView(sf::View(sf::FloatRect(0, 0, ev.size.width, ev.size.height)));
			std::cout << "ev.size.width: " << ev.size.width << " ev.size.height: " << ev.size.height << '\n';
			break;

		case sf::Event::KeyPressed:
		{
			switch (ev.key.code)
			{
			case sf::Keyboard::Space:
				m_next = StateMachine::build<testState>(m_machine, m_window, true);
				break;

			case sf::Keyboard::Escape:
				m_machine.Quit();
				break;
			default:
				break;
			}
			break;
		}

		default:
			break;
		}
	}

	if (m_alpha.a != 0)
	{
		m_alpha.a--;
	}

	m_fader.setFillColor(m_alpha);
}

void playState::draw() {

	//m_window.Update();

	if (m_alpha.a != 0)
		m_window.Draw(m_fader);

	m_window.EndDraw();
}
