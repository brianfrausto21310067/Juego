#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Texto");

    // Cargar la fuente de texto TTF
    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/LilyoftheValley.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }

       // Crear un objeto de texto
    sf::Text text;
    text.setFont(font);
    text.setString("Ejemplo texto Lily of the Valley!");
    text.setCharacterSize(29);
    text.setFillColor(sf::Color::White);

   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.draw(text2);
        window.display();
    }

    return 0;
}
