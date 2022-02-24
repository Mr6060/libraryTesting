#include "Game.hpp"

namespace MyGame{

    void start(){
        const int WIDTH = 1600;
        const int HEIGHT = 800;
        const float rectWIDHT = 20.f;
        const float rectHEIGHT = 20.f;

        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My Game!", sf::Style::Titlebar | sf::Style::Close);

        window.setFramerateLimit(60);
        window.setMouseCursorVisible(false);
        window.setMouseCursorGrabbed(true);

        sf::Vector2u windowSize = window.getSize();

        sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));

        AssetManager manager;

        FPS fps;

        sf::Font font = AssetManager::GetFont("C:\\dev\\SFML-DEV\\libraryTesting\\libraryTesting\\res\\fonts\\RandyGG_Code.ttf");
        
        //font.loadFromFile("C:\\dev\\SFML-DEV\\libraryTesting\\libraryTesting\\res\\fonts\\RandyGG_Code.ttf");
        sf::Text fpsText(std::to_string(fps.getFPS()), font, 20);

        sf::Texture mouseCursor;
        mouseCursor.loadFromFile("C:\\dev\\SFML-DEV\\libraryTesting\\libraryTesting\\res\\images\\cursor.png");

        sf::Sprite mouse;// = sf::Sprite(AssetManager::GetTexture("C:\\dev\\SFML-DEV\\libraryTesting\\libraryTesting\\res\\images\\cursor.png

        sf::RectangleShape rect(sf::Vector2f(100.f,100.f));
        rect.setFillColor(sf::Color::Blue);
        rect.setPosition(500.f, 500.f);
        rect.setOrigin(sf::Vector2f(250.f, 250.f));


        sf::Clock clock;

        float deltaTime = clock.restart().asSeconds();

        sf::Drawable *toDraw[] = {&rect, &fpsText, &mouse};

        while (window.isOpen())
        {
            std::string fpsTextString = "FPS: " + std::to_string(fps.getFPS());
            
            
            fpsTextString += "\nWindow Size: w" + std::to_string(windowSize.x) + ", h" + std::to_string(windowSize.y);

            int diffWIDTH = windowSize.x - (int) rectWIDHT;
            int diffHEIGHT = windowSize.y - (int) rectHEIGHT;
            
            fps.update();
        
            sf::Event event;
            while (window.pollEvent(event))
            {

                if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                    window.close();

                if (event.type == sf::Event::LostFocus){
                    window.setTitle("I'll be back.");
                }
                if (event.type == sf::Event::GainedFocus){
                    window.setTitle("Bitch I'm back.");
                }
                // if (event.type == sf::Event::LostFocus)
                // if (event.type == sf::Event::GainedFocus)
            }

            Coords mousePos = getMousePos(window);
            float newRectPosX = mousePos.x;
            float newRectPosY = mousePos.y;
            mouse.setPosition(newRectPosX, newRectPosY);
            fpsTextString += "\nMouse pos: x" + std::to_string(mousePos.x) + ", y" + std::to_string(mousePos.y);
            

            fpsText.setString(fpsTextString);

            if(mouse.getGlobalBounds().intersects(rect.getGlobalBounds()))
                mouse.setColor(sf::Color::Red);
            else
                mouse.setColor(sf::Color::Blue);

        // view.setCenter(mouse.getPosition());
        // window.setView(view);
            window.clear();
            
            for(auto& elem: toDraw)
                window.draw(*elem);

            window.display();
        }
    }
}