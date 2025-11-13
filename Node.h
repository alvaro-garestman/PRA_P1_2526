#ifndef NODE_H
#define NODE_H

#include <ostream>  // Para std::ostream

// Clase genérica Node<T>
template <typename T>
class Node {
public:
    T data;          // Dato almacenado
    Node<T>* next;   // Puntero al siguiente nodo

    // Constructor: inicializa data y next (por defecto nullptr)
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Sobrecarga del operador << (amigo)
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }
};

#endif // NODE_H

