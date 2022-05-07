#ifndef _VERTICEGRAFO_H_
#define _VERTICEGRAFO_H_

#include <iostream>
#include <list>
#include <string>

/*la arista grafo debe identificarse con su nombre, direccion de donde es, el valor de la coneccion , el destino final y el origen por don de empezo*/
class VerticeGrafo {
public:
    struct AristaGrafo 
    {
        std::string nombre; // Nombre de la arista
        std::string direccion; // A donde va la arista
        int peso; // Peso de la arista
        VerticeGrafo *destino; // destino de la arista
        std::string origen; //origen de la arista
    };

    std::string nombre; // Nombre del vertice
    std::list<AristaGrafo> aristas; // lista de aristas que tiene el vertice inicialmente
    bool visitado; // condicion donde diga si el vertice fue visitado o no

    VerticeGrafo(std::string nombre);

    void agregarArista(std::string nombre, int peso, VerticeGrafo *destino);

    void imprimir();

    std::string getNombre();

    void setVisitado(bool visitado);

    bool getVisitado();

};



#endif //_VERTICEGRAFO_H_
// eof verticeGrafo.h
    