#include <SFML/Graphics.hpp>
#include "figures.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Lab4 - Graphics");

    Line line1Parallelogram(0, 0, 50, 70, &window),
         line2Parallelogram(0, 0, 70, 50, &window),

         line1Rhombus(120, 60, 210, 180, &window),
         line2Rhombus(120, 60, 30, 180, &window),

         line1Rectangle(30, 30, 90, 30, &window),
         line2Rectangle(30, 30, 30, 60, &window),

         line1Square(0, 0, 0, 50, &window),
         line2Square(0, 0, 50, 0, &window);

    // Линия
    Line line(0, 100, 200, 150, &window);

    // Параллелограмм
    Parallelogram parallelogram(line1Parallelogram, line2Parallelogram, &window);

    // Ромб
    Rhombus rhombus(line1Rhombus, line2Rhombus, &window);

    // Прямоугольник
    Rectangle rectangle(line1Rectangle, line2Rectangle, &window);

    // Квадрат
    Square square(line1Square, line2Square, &window);

    Figure figure;

    // Точку обзора переместим на начало координат
    sf::Vector2u size = window.getSize();
    sf::View view(sf::Vector2f(0,0), sf::Vector2f(size.x, size.y));
    window.setView(view);

    // Константы для перемещения фигур
    const char moveBy = 50;
    const char rotateBy = 30;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {

                case sf::Event::Closed: {
                    window.close();
                    break;
                }

                case sf::Event::KeyPressed: {
                    switch (event.key.code) {

                        // Выбор фигуры
                        case sf::Keyboard::Num1: {
                            figure = &line;
                            break; 
                        }
                        case sf::Keyboard::Num2: {
                            figure = &parallelogram;
                            break; 
                        }
                        case sf::Keyboard::Num3: {
                            figure = &rhombus;
                            break;
                        }
                        case sf::Keyboard::Num4: {
                            figure = &rectangle;
                            break;
                        }
                        case sf::Keyboard::Num5: {
                            figure = &square;
                            break;
                        }

                        // Перемещение фигурой
                        case sf::Keyboard::C : {
                            figure.rotate(-rotateBy);
                            break;
                        }
                        case sf::Keyboard::A : {
                            figure.rotate(rotateBy);
                            break;
                        }
                        case sf::Keyboard::Up : {
                            figure.move(0, -moveBy);
                            break;
                        }
                        case sf::Keyboard::Down : {
                            figure.move(0, moveBy);
                            break;
                        }
                        case sf::Keyboard::Left : {
                            figure.move(-moveBy, 0);
                            break;
                        }
                        case sf::Keyboard::Right : {
                            figure.move(moveBy, 0);
                            break;
                        }
                        default: break;
                    }
                    break;
                }
                default: break;
            }
        }
        window.clear();
        figure.draw();
        window.display();
    }

    return 0;
}