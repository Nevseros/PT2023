#ifndef figures_hpp
#define figures_hpp

#include <SFML/Graphics.hpp>

const long double PI = 3.14159265358979323846;

class Point {
    protected:
        double x0, y0;
        sf::RenderWindow *window;

    public:
        Point() { };
        ~Point() { };

        virtual void draw() = 0;
        virtual void move(double dxx, double dyy) = 0;
};

class Line : public Point {
    private:
        sf::Vertex line[2];

    protected:
        double x1, y1;

    public:
        Line(double x0, double y0, double x1, double y1, sf::RenderWindow *window);
        Line() { };
        ~Line() { };

        void draw();
        void rotate(long double angle);
        void move(double dxx, double dyy);

        double length() const;
        double angleTo(const Line &line) const;

        friend class Parallelogram;
        friend class Rectangle;
        friend class Rhombus;
        friend class Square;
};

class Parallelogram : public Line {
    protected:
        Line side1, side2, side3, side4;

    public:
        Parallelogram(const Line &line1, const Line &line2, sf::RenderWindow *window);
        Parallelogram() { };
        ~Parallelogram() { };

        void draw();
        void rotate(long double angle);
        void move(double dxx, double dy);
};

class Rhombus : public Parallelogram {
    public:
        Rhombus(const Line &line1, const Line &line2, sf::RenderWindow *window);
        Rhombus() { };
        ~Rhombus() { };
};

class Rectangle : public Parallelogram {
    public:
        Rectangle(const Line &line1, const Line &line2, sf::RenderWindow *window);
        Rectangle() { };
        ~Rectangle() { };

};

class Square : public Rectangle {
    public:
        Square(const Line &line1, const Line &line2, sf::RenderWindow *window);
        Square() { };
        ~Square() { };
};

class Figure {
    private:
        char type;
        Line *line; // 1
        Parallelogram *parallelogram; // 2
        Rhombus *rhombus; // 3
        Rectangle *rectangle; // 4
        Square *square; // 5

    public:
        Figure() { };
        ~Figure() { };

        void move(double dxx, double dyy);
        void rotate(long double angle);
        void draw();

        Figure operator=(Line *line);
        Figure operator=(Parallelogram *parallelogram);
        Figure operator=(Rhombus *rhombus);
        Figure operator=(Rectangle *rectangle);
        Figure operator=(Square *square);
};

#endif