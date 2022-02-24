
#include "papaya.h"




namespace myPapaya {
    int papayaInt() {
        int x = 50;
        return x;
    }


	int main() {
        sf::RenderWindow window(sf::VideoMode(700, 350), "SFML works!");
        sf::CircleShape shape(100.f);

        
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }

        return 0;
    }
}