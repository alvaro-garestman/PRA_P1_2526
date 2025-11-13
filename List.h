#ifndef LIST_H
#define LIST_H

#include <stdexcept>   // para std::out_of_range

// Clase abstracta genérica para una lista
template <typename T>
class List {
public:
    // Destructor virtual para permitir herencia segura
    virtual ~List() {}

    // Inserta el elemento e en la posición pos.
    // Lanza std::out_of_range si la posición no es válida.
    virtual void insert(int pos, T e) = 0;

    // Inserta el elemento e al final de la lista.
    virtual void append(T e) = 0;

    // Inserta el elemento e al principio de la lista.
    virtual void prepend(T e) = 0;

    // Elimina y devuelve el elemento en la posición pos.
    // Lanza std::out_of_range si la posición no es válida.
    virtual T remove(int pos) = 0;

    // Devuelve el elemento situado en la posición pos.
    // Lanza std::out_of_range si la posición no es válida.
    virtual T get(int pos) = 0;

    // Devuelve la posición de la primera ocurrencia de e, o -1 si no está.
    virtual int search(T e) = 0;

    // Devuelve true si la lista está vacía.
    virtual bool empty() = 0;

    // Devuelve el número de elementos de la lista.
    virtual int size() = 0;
};

#endif // LIST_H

