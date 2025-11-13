#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <stdexcept>
#include <ostream>

// Implementación de la lista mediante nodos enlazados
template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;   // puntero al primer nodo
    int n;            // número de elementos

public:
    // Constructor: lista vacía
    ListLinked() : first(nullptr), n(0) {}

    // Destructor: libera todos los nodos
    ~ListLinked() override {
        // Recorremos y borramos nodo a nodo
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
        n = 0;
    }

    // Inserta elemento en la posición pos (0..n)
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición fuera de rango en insert()");
        if (pos == 0) {
            // insertar al frente
            Node<T>* nuevo = new Node<T>(e, first);
            first = nuevo;
        } else {
            // buscar nodo en pos-1
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next; // prev no será nullptr porque pos <= n
            Node<T>* nuevo = new Node<T>(e, prev->next);
            prev->next = nuevo;
        }
        ++n;
    }

    // Inserta al final
    void append(T e) override {
        insert(n, e);
    }

    // Inserta al principio
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento en pos (0..n-1)
    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en remove()");
        T removedValue;
        if (pos == 0) {
            Node<T>* toDelete = first;
            removedValue = toDelete->data;
            first = first->next;
            delete toDelete;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i)
                prev = prev->next;
            Node<T>* toDelete = prev->next;
            removedValue = toDelete->data;
            prev->next = toDelete->next;
            delete toDelete;
        }
        --n;
        return removedValue;
    }

    // Devuelve el elemento en pos (por valor)
    T get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en get()");
        Node<T>* cur = first;
        for (int i = 0; i < pos; ++i)
            cur = cur->next;
        return cur->data;
    }

    // Busca la primera ocurrencia y devuelve su posición o -1
    int search(T e) override {
        Node<T>* cur = first;
        int idx = 0;
        while (cur != nullptr) {
            if (cur->data == e) return idx;
            cur = cur->next;
            ++idx;
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

    // Operador [] (lectura/escritura)
    T& operator[](int pos) {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en operator[]");
        Node<T>* cur = first;
        for (int i = 0; i < pos; ++i)
            cur = cur->next;
        return cur->data;
    }

    // Versión const del operador []
    const T& operator[](int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango en operator[] const");
        Node<T>* cur = first;
        for (int i = 0; i < pos; ++i)
            cur = cur->next;
        return cur->data;
    }

    // Sobrecarga del operador << definida como friend inline
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "[";
        Node<T>* cur = list.first;
        while (cur != nullptr) {
            out << cur->data;
            if (cur->next != nullptr) out << ", ";
            cur = cur->next;
        }
        out << "]";
        return out;
    }
};

#endif // LISTLINKED_H

