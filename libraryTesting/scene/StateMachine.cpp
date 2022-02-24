#include "StateMachine.h"
#include "State.h"

#include <iostream>

StateMachine::StateMachine() : m_resume{ false }, m_running{ false }{
	std::cout << "StateMachine INIT\n";

}

void StateMachine::Run(std::unique_ptr<State> state) {
	m_running = true;
	m_states.push(std::move(state));
}

void StateMachine::NextState() {
	if (m_resume) {
		//Cleanup the current state
		if (!m_states.empty())
			m_states.pop();

		//Resume previous state
		if (!m_states.empty())
			m_states.top()->resume();

		m_resume = false;
	}

	//There needs to be a state
	if (!m_states.empty()) {
		auto temp = m_states.top()->next();

		//Only change states if there-s a next one existing
		if (temp != nullptr) {
			if (temp->isReplacing())
				m_states.pop();
			else
				//Pause the running state
				m_states.top()->pause();
			m_states.push(std::move(temp));
		}
	}
}

void StateMachine::LastState() {
	m_resume = true;
}

void StateMachine::Update() {
	//Let the state update the game
	m_states.top()->update();
}

void StateMachine::Draw() {
	//Let the state draw the screen
	m_states.top()->draw();
}

bool StateMachine::running() const {
	return m_running;
}

void StateMachine::Quit() {
	m_running = false;
}