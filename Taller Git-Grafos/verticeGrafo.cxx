#ifndef __VERTICE__CXX__
#define __VERTICE__CXX__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <cstring>
#include "VerticeGrafo.h"


//---------------------------------------------------------------------------------------------------------
VerticeGrafo::VerticeGrafo(std::string nombre)
{
    this->nombre = nombre;
}
//---------------------------------------------------------------------------------------------------------
void VerticeGrafo::agregarArista(std::string nombre, int peso, VerticeGrafo *destino)
{
    AristaGrafo arista;
    arista.nombre = nombre;
    arista.peso = peso;
    arista.destino = destino;
    aristas.push_back(arista);
}
//---------------------------------------------------------------------------------------------------------
void VerticeGrafo::imprimir()
{
    std::cout << "Vertice: " << nombre << std::endl;
    std::cout << "Aristas: " << std::endl;
    std::list<AristaGrafo>::iterator it;
    for (it = aristas.begin(); it != aristas.end(); it++)
    {
        std::cout << "Nombre: " << it->nombre << std::endl;
        std::cout << "Direccion: " << it->direccion << std::endl;
        std::cout << "Peso: " << it->peso << std::endl;
        std::cout << "Destino: " << it->destino->nombre << std::endl;
        std::cout << std::endl;
    }
}
//---------------------------------------------------------------------------------------------------------
std::string VerticeGrafo::getNombre()
{
    return nombre;
}
//---------------------------------------------------------------------------------------------------------
void VerticeGrafo::setVisitado(bool visitado)
{
    this->visitado = visitado;
}
//---------------------------------------------------------------------------------------------------------
bool VerticeGrafo::getVisitado()
{
    return visitado;
}
//---------------------------------------------------------------------------------------------------------
#endif //__VERTICE__CXX__