#include <SFML/Graphics.hpp>
 
using namespace sf; // подключаем пространство имен sf
 
int main()
{
    
    // Есть возможность установить сглаживание
//    ContextSettings settings;
//    settings.antialiasingLevel = 8;
    
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(1200, 800), "SFML Works!");
 
    // Главный цикл приложения: выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                window.close(); // тогда закрываем его
        }
        // Установка цвета фона
        window.clear(Color(250, 220, 100, 0));
 
        // Создаем фигуру - круг радиусом 150
        CircleShape circle(150.f);
        
        // Закрашиваем наш круг
        circle.setFillColor(Color(230, 0, 0));
        
        // Создаем рамку круга
        circle.setOutlineThickness(20.f);
        
        // Задаем цвет рамки
        circle.setOutlineColor(Color(0, 50, 0, 100));
        
        circle.move(20, 20);
 
        // Отрисовка круга
        window.draw(circle);
        
        // Создадим треугольник
        CircleShape triangle(150.f, 3);
        triangle.setPosition(350, 0);
        triangle.setFillColor(Color::Blue);
        window.draw(triangle);
        
        // Создадим квадрат
        CircleShape square(150.f, 4);
        square.setPosition(600, 0);
        square.setFillColor(Color::Black);
        window.draw(square);
        
        // Создадим многоугольник
        CircleShape multiangle(100.f, 10);
        multiangle.setPosition(900, 0);
        multiangle.setFillColor(Color::Green);
        window.draw(multiangle);
        
        
        //Заготовка многоугольника
        ConvexShape convex;
        
        // Устанавливаем 4 вершины
        convex.setPointCount(4);
        
        // Устанавливаем координаты вершин
        convex.setPoint(0, Vector2f(15.f, 500.f));
        convex.setPoint(1, Vector2f(200.f, 500.f));
        convex.setPoint(2, Vector2f(300.f, 700.f));
        convex.setPoint(3, Vector2f(15.f, 700.f));
        
        
        convex.setOutlineThickness(15.f);
        convex.setOutlineColor(Color::Black);
        
        window.draw(convex);
        
        
        // Заготовка прямоугольника
        RectangleShape rectangle(Vector2f(150.f, 300.f));
        
        rectangle.move(500, 300);
        
        rectangle.setFillColor(Color::White);
        
        window.draw(rectangle);
        
        
        // Заготовка линии (первый способ)
        RectangleShape line1(Vector2f(300.f, 5.f));
        
        // Поворот нашей линии на 45 градусов
        line1.rotate(45.f);
        
        line1.setFillColor(Color(100, 100, 100));
        
        line1.move(670,400);
        
        window.draw(line1);
        
        // Загатовка линии (второй способ)
        
        Vertex line2[] = {
            Vertex(Vector2f(670.f, 400.f)),
            Vertex(Vector2f(900.f, 400.f))
        };
        
        line2->color = Color::Black;
        
        window.draw(line2, 2, Lines);

        
        // Отрисовка окна
        window.display();
    }
 
    return 0;
}
