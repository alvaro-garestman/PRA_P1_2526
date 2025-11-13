#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices);

public:
    // Constructores
    Square();
    Square(const std::string& color, Point2D* vertices);

    // Sobrescribir set_vertices
    void set_vertices(Point2D* vertices) override;

    // Sobrescribir print
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Square& s);
};

#endif // SQUARE_H

