
/*
g++ src/chat_online/chat_online_client.cpp -o bin/client -I include -L lib -lmingw32 -lsfml-main -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window
*/

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Chat Online Client", sf::Style::Default);
    window.setFramerateLimit(60);

    // SETTINGS INFORMATIONS //
    std::cout << "Antialiasing level : " << window.getSettings().antialiasingLevel << std::endl;
    std::cout << "Attribute flags : " << window.getSettings().attributeFlags << std::endl;
    std::cout << "Core : " << window.getSettings().Core << std::endl;
    std::cout << "Debug : " << window.getSettings().Debug << std::endl;
    std::cout << "Default : " << window.getSettings().Default << std::endl;
    std::cout << "Depth bits : " << window.getSettings().depthBits << std::endl;
    std::cout << "OpenGL Version : " << window.getSettings().majorVersion << "." << window.getSettings().minorVersion << std::endl;
    std::cout << "sRGB capable : " << window.getSettings().sRgbCapable << std::endl;
    std::cout << "Stencil bits : " << window.getSettings().stencilBits << std::endl;

    // Online TCP Initialisation //
    //Define remote
    const sf::IpAddress remoteAddress = "192.168.1.18";
    const unsigned short remotePort = 53000;
    //Connect TCP socket
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(remoteAddress, remotePort);
    if (status != sf::Socket::Done)
    {
        std::cout << "An unexpected error happened : " << status << std::endl;
        return EXIT_FAILURE;
    }

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
