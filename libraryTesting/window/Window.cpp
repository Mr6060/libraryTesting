#include "Window.hpp"

namespace MyWindow{

    Window::Window(){
        Setup("Window", sf::Vector2u(640, 480), 60);
    }

    Window::Window(const std::string &l_title, const sf::Vector2u &l_size, const int &l_frameratelimit){
        Setup(l_title, l_size, l_frameratelimit);
    }

    Window::~Window(){
        Destroy();
    }

    sf::RenderWindow& Window::GetWindow()
    {
        return m_window;
    }

    void Window::Setup(const std::string &l_title, const sf::Vector2u &l_size, const int &l_frameratelimit){
        m_windowTitle = l_title;
        m_windowSize = l_size;
        m_isFullscreen = false;
        m_isDone = false;
        m_window.setFramerateLimit(l_frameratelimit);
        m_cursorVisible = true;
        m_cursorGrabbed = false;
        m_window.setMouseCursorVisible(m_cursorVisible);
        m_window.setMouseCursorGrabbed(m_cursorGrabbed);
        Create();
    }

    void Window::Create(){
        auto style = m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
        m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
    }

    void Window::Destroy(){
        m_window.close();
    }

    /*void Window::Update(){
        sf::Event event;
        while(m_window.pollEvent(event)){
            switch (event.type)
            {
            case sf::Event::Resized:
                m_window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                break;
            case sf::Event::Closed:
                m_isDone = true;
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::F5:
                    ToggleFullScreen();
                    break;
                }
            #ifndef NDEBUG
            case sf::Keyboard::Q:
                m_isDone = true;
            break;
            #endif
            }
        }
    }*/

    void Window::ToggleFullScreen(){
        m_isFullscreen = !m_isFullscreen;
        Destroy();
        Create();
    }

    void Window::BeginDraw(){
        m_window.clear();
    }

    void Window::EndDraw(){
        m_window.display();
    }

    void Window::SetFramerateLimit(const int& l_framerate)
    {
        m_window.setFramerateLimit(l_framerate);
    }

    void Window::SetMouseCursorVisible(bool l_isCursorVisible)
    {
        m_window.setMouseCursorVisible(l_isCursorVisible);
    }

    void Window::SetMouseCursorGrabbed(bool l_isCursorGrabbed)
    {
        m_window.setMouseCursorGrabbed(l_isCursorGrabbed);
    }

    void Window::SetTitle(const std::string& l_title)
    {
        m_window.setTitle(l_title);
    }

    void Window::SetSize(const sf::Vector2u& l_size)
    {
        m_window.setSize(l_size);
    }

    void Window::SetView(const sf::View& l_view)
    {
        m_window.setView(l_view);
    }

    bool Window::isDone() { return m_isDone; }
    bool Window::isFullScreen() { return m_isFullscreen; }
    sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

    void Window::Draw(sf::Drawable &l_drawable){
        m_window.draw(l_drawable);
    }

}