#pragma once
#include <papaya.h>
#include "playState.h"


//State myState(statemachine, window, true);

class testState final : public State {
public:
	testState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
	
	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;
	sf::RectangleShape m_fader;
	sf::Color m_alpha;
};