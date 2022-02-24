#include <iostream>
//#include <SFML/Graphics.hpp>
#include <papaya.h>

#include "./states/testState.h"


int san() {
	
	AssetManager assetmanager;

	MyWindow::Window window(
		"Test window",
		sf::Vector2u(1500, 500),
		60
	);

	window.SetMouseCursorVisible(false);

	sf::Sprite mouseCursor = sf::Sprite((assetmanager.GetTexture(".\\res\\images\\cursor.png")));

	sf::RectangleShape rect(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(sf::Vector2f(500.0f, 200.0f));
	rect.setOrigin(sf::Vector2f(250.0f, 100.0f));

	

	while (!window.isDone()) {

		//Coords mousePos = getMousePos(window.GetWindow());
		//float newRectPosX = mousePos.x;
		//float newRectPosY = mousePos.y;
		//mouseCursor.setPosition(newRectPosX, newRectPosY);

		window.Update();
		window.BeginDraw();

		//window.Draw(rect);
		//window.Draw(mouseCursor);

		window.EndDraw();
	}

	return 0;
}