#include "Rectangle.h"
#include <iostream>
#include <cmath>

// Constructor por defecto
Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES]{
        Point2D(-1,0.5),
        Point2D(1,0.5),
        Point2D(1,-0.5),
        Point2D(-1,-0.5)
    };
}

// Constructor con parámetros
Rectangle::Rectangle(const std::string& c, Point2D* vertices) : Shape(c) {
    if(!check(vertices))
        throw std::invalid_argument("Vertices no conforman un rectángulo");
    vs = new Point2D[N_VERTICES];
    for(int i=0; i<N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle& r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for(int i=0; i<N_VERTICES; ++i)
        vs[i] = r.vs[i];
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Método check estático
bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return std::abs(d01 - d23) < 1e-6 && std::abs(d12 - d30) < 1e-6;
}

// Getter de vértice
Point2D Rectangle::get_vertex(int ind) const {
    if(ind < 0 || ind >= N_VERTICES)
        throw std::out_of_range("Índice de vértice fuera de rango");
    return vs[ind];
}

// Setter de vértices
void Rectangle::set_vertices(Point2D* vertices) {
    if(!check(vertices))
        throw std::invalid_argument("Vertices no conforman un rectángulo");
    for(int i=0; i<N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// Sobrecarga del operador []
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Sobrecarga del operador =
Rectangle& Rectangle::operator=(const Rectangle& r) {
    if(this != &r) {
        Shape::set_color(r.get_color());
        for(int i=0; i<N_VERTICES; ++i)
            vs[i] = r.vs[i];
    }
    return *this;
}

// Métodos virtuales heredados de Shape
double Rectangle::area() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return width * height;
}

double Rectangle::perimeter() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2*(width + height);
}

void Rectangle::translate(double incX, double incY) {
    for(int i=0; i<N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() const {
    std::cout << "[Rectangle: color = " << color << "; vertices = ";
    for(int i=0; i<N_VERTICES; ++i) {
        std::cout << vs[i];
        if(i < N_VERTICES-1) std::cout << ", ";
    }
    std::cout << "]";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    r.print();
    return out;
}

