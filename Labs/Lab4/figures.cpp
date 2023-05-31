#ifndef figures_cpp
#define figures_cpp

#include <cassert>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "figures.hpp"

Line::Line(double x0, double y0, double x1, double y1, sf::RenderWindow *window) {
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
    this->window = window;
    this->line[0] = sf::Vector2f(x0, y0);
    this->line[1] = sf::Vector2f(x1, y1);
}

void Line::draw() {
    window->draw(line, 2, sf::Lines);
}

void Line::rotate(long double angle) {
    angle *= PI/180;

    line[0].position.x = x0 * cos(angle) - y0 * sin(angle);
    line[0].position.y = x0 * sin(angle) + y0 * cos(angle);
    line[1].position.x = x1 * cos(angle) - y1 * sin(angle);
    line[1].position.y = x1 * sin(angle) + y1 * cos(angle);

    y0 = line[0].position.y;
    x0 = line[0].position.x;
    x1 = line[1].position.x;
    y1 = line[1].position.y;

}

void Line::move(double dxx, double dyy) {
    line[0].position.x += dxx;
    x0 += dxx;

    line[0].position.y += dyy;
    y0 += dyy;

    line[1].position.x += dxx;
    x1 += dxx;

    line[1].position.y += dyy;
    y1 += dyy;
}

double Line::length() const {
    return sqrt((x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0));
}

double Line::angleTo(const Line &line) const {
    float dx0 = this->x1 - this->x0,
          dx1 = line.x1 - line.x0,
          dy0 = this->y1 - this->y0,
          dy1 = line.y1 - line.y0;
    return acos((dx0*dx1 + dy0*dy1) / (sqrt(dx0*dx0 + dy0*dy0) * sqrt(dx1*dx1 + dy1*dy1))) * (180/PI);
}


Parallelogram::Parallelogram(const Line &line1, const Line &line2, sf::RenderWindow *window) {
    assert(line1.x0 == line2.x0 && line1.y0 == line2.y0);
    this->side1 = line1;
    this->side2 = line2;
    this->side3 = Line(line2.x1, line2.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->side4 = Line(line1.x1, line1.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->window = window;
}

void Parallelogram::draw() {
    side1.draw();
    side2.draw();
    side3.draw();
    side4.draw();
}

void Parallelogram::rotate(long double angle) {
    side1.rotate(angle);
    side2.rotate(angle);
    side3.rotate(angle);
    side4.rotate(angle);
}

void Parallelogram::move(double dxx, double dyy) {
    side1.move(dxx, dyy);
    side2.move(dxx, dyy);
    side3.move(dxx, dyy);
    side4.move(dxx, dyy);
}


Rhombus::Rhombus(const Line &line1, const Line &line2, sf::RenderWindow *window) {
    assert(line1.length() == line2.length() && line1.x0 == line2.x0);
    this->side1 = line1;
    this->side2 = line2;
    this->side3 = Line(line2.x1, line2.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->side4 = Line(line1.x1, line1.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->window = window;
}


Rectangle::Rectangle(const Line &line1, const Line &line2, sf::RenderWindow *window) {
    assert(line1.x0 == line2.x0 && line1.y0 == line2.y0 && line1.angleTo(line2) == 90);
    this->side1 = line1;
    this->side2 = line2;
    this->side3 = Line(line2.x1, line2.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->side4 = Line(line1.x1, line1.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->window = window;
}


Square::Square(const Line &line1, const Line &line2, sf::RenderWindow *window) {
    assert(line1.x0 == line2.x0 && line1.y0 == line2.y0 && line1.angleTo(line2) == 90 && line1.length() == line2.length());
    this->side1 = line1;
    this->side2 = line2;
    this->side3 = Line(line2.x1, line2.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->side4 = Line(line1.x1, line1.y1, line2.x1 + (line1.x1 - line2.x0), line2.y1 + (line1.y1 - line2.y0), window);
    this->window = window;
}


void Figure::draw() {
    switch (type) {
        case 1: {
            line->draw();
            break;
        }
        case 2: {
            parallelogram->draw();
            break;
        }
        case 3: {
            rhombus->draw();
            break;
        }
        case 4: {
            rectangle->draw();
            break;
        }
        case 5: {
            square->draw();
            break;
        }
    }
}

void Figure::rotate(long double angle) {
    switch (type) {
        case 1: {
            line->rotate(angle);
            break;
        }
        case 2: {
            parallelogram->rotate(angle);
            break;
        }
        case 3: {
            rhombus->rotate(angle);
            break;
        }
        case 4: {
            rectangle->rotate(angle);
            break;
        }
        case 5: {
            square->rotate(angle);
            break;
        }
    }
}

void Figure::move(double dxx, double dyy) {
    switch (type) {
        case 1: {
            line->move(dxx, dyy);
            break;}
        case 2: {
            parallelogram->move(dxx, dyy);
            break;
        }
        case 3: {
            rhombus->move(dxx, dyy);
            break;
        }
        case 4: {
            rectangle->move(dxx, dyy);
            break;
        }
        case 5: {
            square->move(dxx, dyy);
            break;
        }
    }
}

Figure Figure::operator=(Line *line) {
    this->line = line;
    this->type = 1;
    return *this;
}

Figure Figure::operator=(Parallelogram *parallelogram) {
    this->parallelogram = parallelogram;
    this->type = 2;
    return *this;
}

Figure Figure::operator=(Rhombus *rhombus) {
    this->rhombus = rhombus;
    this->type = 3;
    return *this;
}

Figure Figure::operator=(Rectangle *rectangle) {
    this->rectangle = rectangle;
    this->type = 4;
    return *this;
}

Figure Figure::operator=(Square *square) {
    this->square = square;
    this->type = 5;
    return *this;
}

#endif