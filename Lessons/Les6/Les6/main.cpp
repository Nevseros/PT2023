#include <SFML/Graphics.hpp>
#include "figures.hpp"

using namespace sf; // подключаем пространство имен sf
 
int main()
{
    
    static const long double pi=3.14159265358979323846;
    
    // Объект, является главным окном приложения
    RenderWindow window(VideoMode(800, 800), "SFML Works!");
     
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
        window.clear(Color(0, 0, 0, 0));
        
        Tline l1(&window);
        l1.draw();
        
        Square s1(350, 200, 100, 0, &window);
        s1.draw();
        
        s1.rotate(pi/8);
        s1.draw();
        s1.rotate(pi/8);
        s1.draw();
        s1.rotate(pi/8);
        s1.draw();
        s1.rotate(pi/8);
        s1.draw();
        s1.rotate(pi/8);
        s1.draw();
        s1.move(0,300);
        s1.draw();
        s1.rotate(pi/8);
        s1.draw();
        s1.rotate(pi/8);
        s1.draw();
        s1.rotate(pi/8);
        s1.draw();
        
        // Отрисовка окна
        window.display();
    }
 
    return 0;
}
