#pragma once
#include <SFML/Graphics/RectangleShape.hpp>


class Rectangle
{
	Rectangle();
	Rectangle(sf::Vector2f& l_size, sf::Vector2f& l_position, sf::Vector2f& l_origin);
	~Rectangle();



private:
	sf::RectangleShape m_rectangle;

};

