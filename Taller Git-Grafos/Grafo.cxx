#ifndef __GRAFO__cxx__
#define __GRAFO__cxx__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <cstring>
#include "Grafo.h"

//---------------------------------------------------------------------------------------------------------
Grafo::Grafo()
{
}
//---------------------------------------------------------------------------------------------------------
void Grafo::agregarVertice(VerticeGrafo vertice)
{
    vertices.push_back(vertice);
}
//---------------------------------------------------------------------------------------------------------
void Grafo::eliminarArista(std::string nombre)
{
    std::list<VerticeGrafo>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        std::list<VerticeGrafo::AristaGrafo>::iterator itArista;
        for (itArista = it->aristas.begin(); itArista != it->aristas.end(); itArista++)
        {
            if (itArista->nombre == nombre)
            {
                it->aristas.erase(itArista);
                return;
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------
void Grafo::eliminarVertice(std::string nombre)
{
    std::list<VerticeGrafo>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        if (it->nombre == nombre)
        {
            vertices.erase(it);
            return;
        }
    }
}
//---------------------------------------------------------------------------------------------------------
std::list<VerticeGrafo> Grafo::getVertices()
{
    return vertices;
}
//---------------------------------------------------------------------------------------------------------
int Grafo::getCantidadVertices()
{
    return vertices.size();
}
//---------------------------------------------------------------------------------------------------------
int Grafo::getCantidadAristas()
{
    int cantidad = 0;
    std::list<VerticeGrafo>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        cantidad += it->aristas.size();
    }
    return cantidad;
}
//---------------------------------------------------------------------------------------------------------
VerticeGrafo *Grafo::buscarVertice(std::string nombre)
{
    std::list<VerticeGrafo>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        if (it->nombre == nombre)
        {
            return &(*it);
        }
    }
    return NULL;
}
//---------------------------------------------------------------------------------------------------------
void Grafo::agregarArista( std::string nombre, int peso, VerticeGrafo *destino)
{
    std::list<VerticeGrafo>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        if (it->nombre == nombre)
        {
            it->agregarArista(nombre, peso, destino);
            return;
        }
    }

}
//---------------------------------------------------------------------------------------------------------
void Grafo::recorridoPlano()
{
    std::list<VerticeGrafo>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        std::cout << it->nombre << " ";
    }
    std::cout << std::endl;
}
//---------------------------------------------------------------------------------------------------------
void Grafo::recorridoProfundidad(std::string vertice, std::list<std::string> &visitados)
{
    VerticeGrafo *verticeActual = buscarVertice(vertice);
    if (verticeActual == NULL)
    {
        return;
    }
    visitados.push_back(verticeActual->nombre);
    std::list<VerticeGrafo::AristaGrafo>::iterator it;
    for (it = verticeActual->aristas.begin(); it != verticeActual->aristas.end(); it++)
    {
        if (std::find(visitados.begin(), visitados.end(), it->nombre) == visitados.end())
        {
            recorridoProfundidad(it->nombre, visitados);
        }
    }
}

//---------------------------------------------------------------------------------------------------------
void Grafo::recorridoAnchura(std::string vertice, std::list<std::string> &visitados)
{
    VerticeGrafo *verticeActual = buscarVertice(vertice);
    if (verticeActual == NULL)
    {
        return;
    }
    visitados.push_back(verticeActual->nombre);
    std::list<VerticeGrafo::AristaGrafo>::iterator it;
    std::list<std::string>::iterator it2;
    std::list<std::string> visitadosAux;
    for (it = verticeActual->aristas.begin(); it != verticeActual->aristas.end(); it++)
    {
        if (std::find(visitados.begin(), visitados.end(), it->nombre) == visitados.end())
        {
            visitadosAux.push_back(it->nombre);
        }
    }
    visitados.insert(visitados.end(), visitadosAux.begin(), visitadosAux.end());
}
//---------------------------------------------------------------------------------------------------------
void imprimirRecorridoAnchura(std::string vertice, std::list<std::string>& visitadosVertices)
{
    std::list<std::string>::iterator it;
    for (it = visitadosVertices.begin(); it != visitadosVertices.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}


#endif // __GRAFO__cxx__