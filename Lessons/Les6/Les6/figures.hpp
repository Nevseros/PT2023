#ifndef figures_hpp
#define figures_hpp

#include <SFML/Graphics.hpp>
#include <math.h>


// Описание Point
class Point{
protected:
    int x;
    int y;
    sf::Color color;
    sf::RenderWindow *window;
    
public:
    Point(sf::RenderWindow *w);
    Point(int x1, int y1, sf::RenderWindow *w);
    
    virtual void draw()=0;
    
    void move(int dxx, int dyy);
};


// Описание Tline
class Tline:public Point{
protected:
    int dx;
    int dy;
    
public:
    Tline(sf::RenderWindow *w);
    Tline(int x1, int y1, int dxx, int dyy, sf::RenderWindow *w);
    
    void draw();
    void rotate(long double fi);
};

// Описание Square
class Square:public Tline{
public:
    Square(sf::RenderWindow *w);
    Square(int x1, int y1, int dxx, int dyy, sf::RenderWindow *w);
    
    void draw();

};

#endif /* figures_hpp */
