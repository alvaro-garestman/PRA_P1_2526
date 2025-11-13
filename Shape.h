#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
protected:
    std::string color;

public:
    // Constructores
    Shape();                    // Constructor por defecto, color rojo
    Shape(const std::string& c); // Constructor con color especificado

    // Getter y setter del color
    std::string get_color() const;
    void set_color(const std::string& c);

    // Métodos virtuales puros
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() const = 0;

    // Destructor virtual
    virtual ~Shape() = default;
};

#endif // SHAPE_H

