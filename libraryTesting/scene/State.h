#pragma once
#include "../window/Window.hpp"
#include <memory>

class StateMachine;

namespace sf {
	class RenderWindow;
}

class State
{
public:
	State(StateMachine& machine, MyWindow::Window& window, bool replace = true);
	virtual ~State() = default;

	State(const State&) = delete;
	State& operator=(const State&) = delete;

	virtual void pause() = 0;
	virtual void resume() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	std::unique_ptr<State> next();

	[[nodiscard]] bool isReplacing() const;

protected:
	StateMachine& m_machine;
	MyWindow::Window& m_window;

	bool m_replacing;
	std::unique_ptr<State> m_next;
};

