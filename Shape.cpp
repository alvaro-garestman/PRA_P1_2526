#include "Shape.h"

// Constructor por defecto
Shape::Shape() : color("red") {}

// Constructor con color especificado
Shape::Shape(const std::string& c) {
    set_color(c); // valida internamente el color
}

// Getter del color
std::string Shape::get_color() const {
    return color;
}

// Setter del color con validación
void Shape::set_color(const std::string& c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color inválido. Solo se permiten: red, green, blue");
    }
    color = c;
}

