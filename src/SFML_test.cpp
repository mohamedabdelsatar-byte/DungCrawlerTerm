#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/*void centerOrigin(sf::Shape& shape){
    auto bound = shape.getGlobalBounds();
    shape.setOrigin({bound.position.x + bound.size.x/2.f, bound.position.y + bound.size.y/2.f});
}*/

int main() {
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "DungCrawler");


    sf::Texture playerTexture;
    playerTexture.loadFromFile("Assets/Textures/Witch.png");
    sf::Sprite player(playerTexture);
    player.setScale(sf::Vector2f(10.f, 10.f));
    player.setPosition({960.f, 540.f});


    //MAIN LOOP
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {

            if (event ->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        //Player Movement
        sf::Vector2f vPlayerMovement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            vPlayerMovement += sf::Vector2f(0.0f, -1.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            vPlayerMovement += sf::Vector2f(-1.0f, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            vPlayerMovement += sf::Vector2f(0.0f, 1.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            vPlayerMovement += sf::Vector2f(1.0f, 0.0f);
        }

        player.move(vPlayerMovement);

        window.clear(sf::Color::Black);
        //DRAW

        sf::RectangleShape Door1({200.f, 200.f});
        Door1.setOrigin(sf::Vector2f(8, 8));
        Door1.setPosition({960.f, 540.f});


        Door1.setFillColor(sf::Color::Blue);



       // window.draw(Door1);
        window.draw(player);


        window.display();


    }




return 0;
}




/* DOORS
        sf::RectangleShape Door1({50.f, 120.f});
        centerOrigin(Door1);
        Door1.setPosition({100.f, 550.f});
        Door1.setFillColor(sf::Color::Blue);


        sf::RectangleShape Door2({50.f, 120.f});
        centerOrigin(Door2);
        Door2.setPosition({200.f, 550.f});
        Door2.setFillColor(sf::Color::Green);


        sf::RectangleShape Door3({50.f, 120.f});
        centerOrigin(Door3);
        Door3.setPosition({300.f, 550.f});
        Door3.setFillColor(sf::Color::Red);


        sf::RectangleShape Door4({50.f, 120.f});
        centerOrigin(Door4);
        Door4.setPosition({400.f, 550.f});
        Door4.setFillColor(sf::Color::Yellow);

        sf::RectangleShape Door5({50.f, 120.f});
        centerOrigin(Door5);
        Door5.setPosition({500.f, 550.f});
        Door5.setFillColor(sf::Color::White);



        window.draw(Door1);
        window.draw(Door2);
        window.draw(Door3);
        window.draw(Door4);
        window.draw(Door5);
        */