//
// Created by yeusepe on 4/29/22.
//

#ifndef ESTRUCTURAS_7996_GRAFO_H
#define ESTRUCTURAS_7996_GRAFO_H

#include "verticeGrafo.h"

/*! La clase grafo representa un grafo, tiene una lista de vertices */
class grafo {
public:

    std::list<verticeGrafo> vertices; ///< lista de vertices que tiene el grafo

    grafo();

    void agregarVertice(verticeGrafo vertice);

    void eliminarArista(std::string nombre);

    void eliminarVertice(std::string nombre);

    std::list<verticeGrafo> getVertices();

    int getCantidadVertices();

    int getCantidadAristas();

    verticeGrafo *buscarVertice(std::string nombre);

    void agregarArista(std::string nombreVertice1, std::string nombreVertice2, int peso);

    void recorridoPlano();

    void recorridoProfundidad(std::string vertice, std::list<std::string> &visitados);

    verticeGrafo::aristaGrafo *buscarArista(std::string arista);

    void recorridoAnchura(std::string vertice, std::list<std::string> &visitadas, std::list<std::string> &visitadosVertices);

    void imprimirRecorridoAnchura(std::string vertice, std::list<std::string>& visitadosVertices);
};
#endif //ESTRUCTURAS_7996_GRAFO_H
