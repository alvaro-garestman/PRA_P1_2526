#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <stdexcept>   // para std::out_of_range
#include <iostream>    // para std::ostream

// Implementación de una lista usando arrays dinámicos
template <typename T>
class ListArray : public List<T> {
private:
    T* arr;          // puntero al array dinámico
    int capacity;    // capacidad máxima actual
    int n;           // número de elementos en la lista

    // Método auxiliar para redimensionar el array cuando se llena
    void resize(int new_capacity) {
        T* new_arr = new T[new_capacity];
        for (int i = 0; i < n; ++i)
            new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

public:
    // Constructor por defecto
    ListArray(int init_capacity = 10) {
        capacity = init_capacity;
        n = 0;
        arr = new T[capacity];
    }

    // Destructor
    ~ListArray() override {
        delete[] arr;
    }

    // Inserta elemento en posición pos
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición fuera de rango en insert()");
        if (n == capacity)
            resize(2 * capacity);  // duplicamos capacidad si está lleno

        for (int i = n; i > pos; --i)
            arr[i] = arr[i - 1];

        arr[pos] = e;
        ++n;
    }

    // Inserta al final → reutiliza insert()
    void append(T e) override {
        insert(n, e);
    }

    // Inserta al principio → reutiliza insert()
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento en pos
    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en remove()");

        T removed = arr[pos];
        for (int i = pos; i < n - 1; ++i)
            arr[i] = arr[i + 1];

        --n;
        return removed;
    }

    // Devuelve el elemento en pos
    T get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en get()");
        return arr[pos];
    }

    // Busca el primer elemento igual a e
    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e)
                return i;
        }
        return -1;
    }

    // ¿Lista vacía?
    bool empty() override {
        return n == 0;
    }

    // Número de elementos
    int size() override {
        return n;
    }
       // Operador [] para acceder a los elementos
    T& operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en operator[]");
        return arr[pos];
    }

    // Versión const del operador []
    const T& operator[](int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en operator[] const");
        return arr[pos];
    }

};

// ---------------------------------------------------------------
// Sobrecarga del operador << para imprimir ListArray<T>
// ---------------------------------------------------------------
template <typename T>
std::ostream& operator<<(std::ostream& os, ListArray<T>& list) {
    os << "[";
    for (int i = 0; i < list.size(); ++i) {
        os << list.get(i);
        if (i < list.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

#endif // LISTARRAY_H


































