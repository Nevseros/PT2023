#include "figures.hpp"

static const long double pi=3.14159265358979323846;

// class Point
Point::Point(sf::RenderWindow *w){
    x=200;
    y=200;
    color = sf::Color::White;
    window = w;
}

Point::Point(int x1, int y1, sf::RenderWindow *w){
    x=x1;
    y=y1;
    color = sf::Color::White;
    window = w;
}

void Point::move(int dxx, int dyy){
    x += dxx;
    y += dyy;
}

//------------------------
// class Tline

Tline::Tline(sf::RenderWindow *w):Point(w){
    dx=100;
    dy=100;
}

Tline::Tline(int x1, int y1, int dxx, int dyy, sf::RenderWindow *w):Point(x1, y1, w){
    dx=dxx;
    dy=dyy;
}

//пример реализации отрисовки (можно свой)
void Tline::draw(){
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x,y)),
        sf::Vertex(sf::Vector2f(x+dx,y+dy))
    };
    line->color = color;
    window->draw(line, 2, sf::Lines);
}

void Tline::rotate(long double fi){
    int dxx=dx, dyy=dy;
    dx = dxx*cos(fi)-dyy*sin(fi);
    dy = dxx*sin(fi)+dyy*cos(fi);
}


//-----------------------
// class Square

Square::Square(sf::RenderWindow *w):Tline(w){
    
}

Square::Square(int x1, int y1, int dxx, int dyy, sf::RenderWindow *w):Tline(x1, y1, dxx, dyy, w){
    
}

void Square::draw(){
    Tline tmp(x, y, dx, dy, window);
    tmp.draw();
    
    tmp.rotate(pi/2);
    tmp.draw();
    
    tmp.move(dx, dy);
    tmp.draw();
    
    tmp.move(dx*cos(pi/2)-dy*sin(pi/2), dx*sin(pi/2)+dy*cos(pi/2));
    tmp.rotate(pi/2);
    tmp.draw();
}
