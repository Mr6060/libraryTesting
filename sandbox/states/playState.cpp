#include "playState.h"
#include <memory>
#include <iostream>

#include "testState.h"

playState::playState(StateMachine& machine, sf::RenderWindow& window, const bool replace)
	: State{ machine, window, replace }
	, m_alpha{ 0, 0, 0, 255 } // Start off opaque
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
	for (auto event = sf::Event{}; m_window.pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_machine.Quit();
			break;

		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
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
	m_window.clear();

	if (m_alpha.a != 0)
		m_window.draw(m_fader);

	m_window.display();
}
