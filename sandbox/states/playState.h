#pragma once
#include <papaya.h>
#include "testState.h"


//State myState(statemachine, window, true);

class playState final : public State {
public:
	playState(StateMachine& machine, MyWindow::Window& window, bool replace = true);
	
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