#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>
#include "Shape.h"
#include "Point2D.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    // Constructores
    Circle(); // por defecto
    Circle(const std::string& color, const Point2D& center, double radius);

    // Getters y setters
    Point2D get_center() const;
    void set_center(const Point2D& p);

    double get_radius() const;
    void set_radius(double r);

    // Métodos virtuales de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Circle& c);
};

#endif // CIRCLE_H

