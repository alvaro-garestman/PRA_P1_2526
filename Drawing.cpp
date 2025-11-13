#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include <typeinfo>
#include <iostream>

Drawing::Drawing() {
    // Escoge la implementación que quieras:
    shapes = new ListArray<Shape*>();  // o new ListLinked<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;  // Solo borramos la lista; no borramos los Shape* individuales
}

void Drawing::add_front(Shape* shape) {
    shapes->insert(0, shape);  // Inserta al inicio
}

void Drawing::add_back(Shape* shape) {
    shapes->insert(shapes->size(), shape);  // Inserta al final
}

void Drawing::print_all() const {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        s->print();
        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles() const {
    double total = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (dynamic_cast<Circle*>(s)) {
            total += s->area();
        }
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        Square* sq = dynamic_cast<Square*>(s);
        if (sq) {
            sq->translate(incX, incY);
        }
    }
}

