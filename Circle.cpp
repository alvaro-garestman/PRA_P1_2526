#include "Circle.h"
#include <iostream>
#include <cmath>

const double PI = 3.141592;

// Constructores
Circle::Circle() : Shape(), center(0,0), radius(1) {}

Circle::Circle(const std::string& c, const Point2D& cent, double r) : Shape(c), center(cent), radius(r) {}

// Getters y setters
Point2D Circle::get_center() const { return center; }
void Circle::set_center(const Point2D& p) { center = p; }

double Circle::get_radius() const { return radius; }
void Circle::set_radius(double r) { radius = r; }

// Métodos virtuales
double Circle::area() const { return PI * std::pow(radius, 2); }

double Circle::perimeter() const { return 2 * PI * radius; }

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() const {
    std::cout << "[Circle: color = " << color
              << "; center = " << center
              << "; radius = " << radius << "]";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Circle& c) {
    c.print();
    return out;
}

