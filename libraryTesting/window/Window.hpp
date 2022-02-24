#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace MyWindow{

    class Window{
    public:

        Window();
        Window(const std::string &l_title, const sf::Vector2u &l_size, const int &l_frameratelimit);
        ~Window();

        sf::RenderWindow& GetWindow();

        void BeginDraw();
        void EndDraw();

        void SetFramerateLimit(const int& l_framerate);
        void SetMouseCursorVisible(bool l_isCursorVisible);
        void SetMouseCursorGrabbed(bool l_isCursorGrabbed);

        void Update();

        bool isDone();
        bool isFullScreen();
        sf::Vector2u GetWindowSize();

        void ToggleFullScreen();

        void Draw(sf::Drawable &l_drawable);
    private:
        void Setup(const std::string &l_title, const sf::Vector2u &l_size, const int &l_frameratelimit);
        void Destroy();
        void Create();

        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::string m_windowTitle;
        bool m_isDone;
        bool m_isFullscreen;
        bool m_cursorVisible, m_cursorGrabbed;
    };
}
