#include "Point2D.h"
#include <cmath>
#include <ostream>

// Constructor
Point2D::Point2D(double x, double y) : x(x), y(y) {}

// Función estática de distancia euclidiana
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Sobrecarga de ==
bool operator==(const Point2D &a, const Point2D &b) {
    return a.x == b.x && a.y == b.y;
}

// Sobrecarga de !=
bool operator!=(const Point2D &a, const Point2D &b) {
    return !(a == b);
}

// Sobrecarga de <<
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

