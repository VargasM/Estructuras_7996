//
// Created by yeusepe on 4/29/22.
//

#ifndef ESTRUCTURAS_7996_VERTICEGRAFO_H
#define ESTRUCTURAS_7996_VERTICEGRAFO_H

#include <iostream>
#include <list>
#include <string>

/*! La clase verticeGrafo representa un vertice del grafo, tiene un direccion, una lista de aristas que tiene y una lista de visitados, tambien tiene una variable booleana visitado */
class verticeGrafo {
public:
    struct aristaGrafo {
        std::string nombre; ///< Nombre de la arista
        std::string direccion; ///< A donde va la arista
        int peso; ///< Peso de la arista
        verticeGrafo *destino; ///< Puntero al vertice destino de la arista
        std::string origen; ///< Puntero al vertice origen de la arista
    }; ///< Tipo de dato aristaGrafo, contiene un direccion, un peso y un puntero al vertice destino

    std::string nombre; ///< Nombre del vertice
    std::list<aristaGrafo> aristas; ///< lista de aristas que tiene el vertice
    bool visitado; ///< Booleano que indica si el vertice fue visitado

    verticeGrafo(std::string nombre);

    void agregarArista(std::string nombre, int peso, verticeGrafo *destino);

    void imprimir();

    std::string getNombre();

    aristaGrafo *buscarArista(std::string nombre);

    void setVisitado(bool visitado);

    bool getVisitado();

    std::list<aristaGrafo> ordenarAristas();
};



#endif //ESTRUCTURAS_7996_VERTICEGRAFO_H
