#include <SFML/Graphics.hpp>

class Personaje
{
public:
    Personaje(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("assets/images/pikachu.png"))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 64)+17, 133, 64, 36));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 32;
    int frameHeight = 32;
};

double velocidad = 0.1;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DinoChrome");

    Personaje mario(sf::Vector2f(400, 300), sf::Color::Red);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mario.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mario.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            mario.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            mario.move(0, velocidad);
        }

        // Actualizar animacion mario
        mario.update();

        window.clear();
        mario.draw(window);
        window.display();
    }

    return 0;
}
