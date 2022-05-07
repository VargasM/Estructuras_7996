//archivo .h para la lectura de un grafo
// Language: cpp
// Path: Grafo.h

#ifndef __GRAFO__H__
#define __GRAFO__H__
#include <iostream>
#include "VerticeGrafo.h"

//---------------------------------------------------------------------------------------------------------
// lista de vertices
class Grafo {
public:

    std::list<VerticeGrafo> vertices; ///< lista de vertices que tiene el grafo

    Grafo();

    void agregarVertice(VerticeGrafo vertice);

    void eliminarArista(std::string nombre);

    void eliminarVertice(std::string nombre);

    std::list<VerticeGrafo> getVertices();

    int getCantidadVertices();

    int getCantidadAristas();

    VerticeGrafo *buscarVertice(std::string nombre);

    void agregarArista(std::string nombre, int peso, VerticeGrafo *destino);

    void recorridoPlano(); //recorrido en plano

    void recorridoProfundidad(std::string vertice, std::list<std::string> &visitados); //recorrido por profundidad

    void recorridoAnchura(std::string vertice, std::list<std::string> &visitados); //recorre el grafo en anchura

    void imprimirRecorridoAnchura(std::string vertice, std::list<std::string>& visitadosVertices); //imprime el recorrido en anchura
};

#endif //ESTRUCTURAS_7996_GRAFO_H
