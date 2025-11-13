#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;  // puntero a array de 4 vértices
public:
    static const int N_VERTICES = 4;

private:
    static bool check(Point2D* vertices);

public:
    // Constructores y destructor
    Rectangle();  // por defecto
    Rectangle(const std::string& color, Point2D* vertices);
    Rectangle(const Rectangle& r);
    ~Rectangle();

    // Getters y setters
    Point2D get_vertex(int ind) const;
    virtual void set_vertices(Point2D* vertices);

    // Sobrecarga del operador []
    Point2D operator[](int ind) const;

    // Sobrecarga del operador =
    Rectangle& operator=(const Rectangle& r);

    // Métodos virtuales heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    virtual void print() const override;

    // Sobrecarga global del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
};

#endif // RECTANGLE_H

