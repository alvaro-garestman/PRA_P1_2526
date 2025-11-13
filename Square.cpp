#include "Square.h"
#include <cmath>
#include <stdexcept>

// Constructor por defecto
Square::Square() : Rectangle() {
    delete[] vs; // liberar vertices de Rectangle
    vs = new Point2D[N_VERTICES]{
        Point2D(-1,1),
        Point2D(1,1),
        Point2D(1,-1),
        Point2D(-1,-1)
    };
}

// Constructor con parámetros
Square::Square(const std::string& color, Point2D* vertices) : Rectangle(color, vertices) {
    if(!check(vertices))
        throw std::invalid_argument("Vertices no conforman un cuadrado");
    for(int i=0; i<N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// Método check estático
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return std::abs(d01 - d12) < 1e-6 &&
           std::abs(d12 - d23) < 1e-6 &&
           std::abs(d23 - d30) < 1e-6;
}

// Sobrescribir set_vertices
void Square::set_vertices(Point2D* vertices) {
    if(!check(vertices))
        throw std::invalid_argument("Vertices no conforman un cuadrado");
    for(int i=0; i<N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// Sobrescribir print
void Square::print() const {
    std::cout << "[Square: color = " << color << "; vertices = ";
    for(int i=0; i<N_VERTICES; ++i) {
        std::cout << vs[i];
        if(i < N_VERTICES-1) std::cout << ", ";
    }
    std::cout << "]";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Square& s) {
    s.print();
    return out;
}

