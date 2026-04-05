#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "DungCrawler");

    //MAIN LOOP
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {

            if (event ->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        //DRAW
        //rectangle
        sf::RectangleShape rectangle({120.f, 50.f});
        rectangle.setPosition({100.f, 50.f});
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setSize({100.f, 100.f});

        window.draw(rectangle);

        sf::CircleShape circle(50.f);
        circle.setPosition({50.f, 100});
        circle.setFillColor(sf::Color::Green);
        circle.setRadius(50.f);

        window.draw(circle);

        sf::CircleShape triangle(70.f, 3);
        triangle.setPosition({120.f, 90.f});
        triangle.setFillColor(sf::Color::Yellow);

        window.draw(triangle);



        window.display();


    }




return 0;
}

