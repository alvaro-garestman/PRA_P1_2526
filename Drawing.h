#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "Shape.h"
#include "List.h"
#include "ListArray.h"   // o ListLinked.h si prefieres esa implementación

class Drawing {
private:
    List<Shape*>* shapes;

public:
    Drawing();                // Constructor
    ~Drawing();               // Destructor

    void add_front(Shape* shape);
    void add_back(Shape* shape);
    void print_all() const;
    double get_area_all_circles() const;
    void move_squares(double incX, double incY);
};

#endif // DRAWING_H

