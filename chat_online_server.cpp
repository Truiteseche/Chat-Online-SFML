
/*
g++ src/Chat-Online-SFML/chat_online_server.cpp -o bin/server -I include -L lib -lmingw32 -lsfml-main -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window
*/

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Chat Online Server", sf::Style::Default);
    window.setFramerateLimit(60);

    // SFML INFORMATIONS //
    std::cout << "Antialiasing level : " << window.getSettings().antialiasingLevel << std::endl;
    std::cout << "Attribute flags : " << window.getSettings().attributeFlags << std::endl;
    std::cout << "Core : " << window.getSettings().Core << std::endl;
    std::cout << "Debug : " << window.getSettings().Debug << std::endl;
    std::cout << "Default : " << window.getSettings().Default << std::endl;
    std::cout << "Depth bits : " << window.getSettings().depthBits << std::endl;
    std::cout << "OpenGL Version : " << window.getSettings().majorVersion << "." << window.getSettings().minorVersion << std::endl;
    std::cout << "sRGB capable : " << window.getSettings().sRgbCapable << std::endl;
    std::cout << "Stencil bits : " << window.getSettings().stencilBits << std::endl;

    

    // TCP Initialisation //
    sf::TcpListener listener;
    const unsigned short port = 53000;

    //Listen port
    sf::Socket::Status status = listener.listen(port);
    if(status != sf::Socket::Done)
    {
        std::cout << "An unexpected error happened : " << status << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "TCP listening on port " << port << std::endl;
    
    //Accept new connection
    sf::TcpSocket client;
    status = listener.accept(client);
    if(status != sf::Socket::Done)
    {
        std::cout << "An unexpected error happened : " << status << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "New client connected (remote ip : " << client.getRemoteAddress() << ")" << std::endl;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::Resized)
                window.setView(sf::View(window.getView().getCenter(), sf::Vector2f(window.getSize().x, window.getSize().y)));
        }

        window.clear(sf::Color::Green);
        //window.draw();
        window.display();
    }

    return EXIT_SUCCESS;
}
