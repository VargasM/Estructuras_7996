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
    cantidadVertices = 0;
    cantidadAristas = 0;
    matrizAdyacencia = NULL;
    nombreVertices = NULL;
}
//---------------------------------------------------------------------------------------------------------
Grafo::~Grafo()
{
    if (matrizAdyacencia != NULL)
    {
        for (int i = 0; i < cantidadVertices; i++)
        {
            delete[] matrizAdyacencia[i];
        }
        delete[] matrizAdyacencia;
    }
    if (nombreVertices != NULL)
    {
        for (int i = 0; i < cantidadVertices; i++)
        {
            delete[] nombreVertices[i];
        }
        delete[] nombreVertices;
    }
}

//---------------------------------------------------------------------------------------------------------
int Grafo::cantVertices()
{
    return cantidadVertices;
}
//---------------------------------------------------------------------------------------------------------
int Grafo::cantAristas()
{
    return cantidadAristas;
}
//---------------------------------------------------------------------------------------------------------
int Grafo::buscarVertices(char *nombreVertice)
{
    for (int i = 0; i < cantidadVertices; i++)
    {
        if (strcmp(nombreVertice, nombreVertices[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}
//---------------------------------------------------------------------------------------------------------
int Grafo::buscarArista(int vertice1, int vertice2)
{
    return matrizAdyacencia[vertice1][vertice2];
}
//---------------------------------------------------------------------------------------------------------
bool Grafo::insertarVertice(char *nombreVertice)
{
    if (buscarVertices(nombreVertice) == -1)
    {
        char **nuevoNombreVertices = new char *[cantidadVertices + 1];
        for (int i = 0; i < cantidadVertices; i++)
        {
            nuevoNombreVertices[i] = new char[20];
            strcpy(nuevoNombreVertices[i], nombreVertices[i]);
        }
        nuevoNombreVertices[cantidadVertices] = new char[20];
        strcpy(nuevoNombreVertices[cantidadVertices], nombreVertice);
        cantidadVertices++;
        for (int i = 0; i < cantidadVertices; i++)
        {
            delete[] nombreVertices[i];
        }
        delete[] nombreVertices;
        nombreVertices = nuevoNombreVertices;
        int **nuevaMatrizAdyacencia = new int *[cantidadVertices];
        for (int i = 0; i < cantidadVertices; i++)
        {
            nuevaMatrizAdyacencia[i] = new int[cantidadVertices];
            for (int j = 0; j < cantidadVertices; j++)
            {
                nuevaMatrizAdyacencia[i][j] = matrizAdyacencia[i][j];
            }
        }
        for (int i = 0; i < cantidadVertices; i++)
        {
            delete[] matrizAdyacencia[i];
        }
        delete[] matrizAdyacencia;
        matrizAdyacencia = nuevaMatrizAdyacencia;
        for (int i = 0; i < cantidadVertices; i++)
        {
            matrizAdyacencia[i][cantidadVertices - 1] = 0;
            matrizAdyacencia[cantidadVertices - 1][i] = 0;
        }
        return true;
    }
}
//---------------------------------------------------------------------------------------------------------
bool Grafo::insertarArista(int vertice1, int vertice2, int peso)
{
    if (vertice1 >= 0 && vertice1 < cantidadVertices && vertice2 >= 0 && vertice2 < cantidadVertices)
    {
        if (matrizAdyacencia[vertice1][vertice2] == 0)
        {
            matrizAdyacencia[vertice1][vertice2] = peso;
            matrizAdyacencia[vertice2][vertice1] = peso;
            cantidadAristas++;
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------------------------------------
bool Grafo::eliminarVertice(int vertice)
{
    if (vertice >= 0 && vertice < cantidadVertices)
    {
        for (int i = 0; i < cantidadVertices; i++)
        {
            matrizAdyacencia[vertice][i] = 0;
            matrizAdyacencia[i][vertice] = 0;
        }
        for (int i = vertice; i < cantidadVertices - 1; i++)
        {
            for (int j = 0; j < cantidadVertices; j++)
            {
                matrizAdyacencia[i][j] = matrizAdyacencia[i + 1][j];
            }
        }
        for (int i = vertice; i < cantidadVertices - 1; i++)
        {
            for (int j = 0; j < cantidadVertices; j++)
            {
                matrizAdyacencia[j][i] = matrizAdyacencia[j][i + 1];
            }
        }
        cantidadVertices--;
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------------------------------------
bool Grafo::eliminarArista(int vertice1, int vertice2)
{
    if (vertice1 >= 0 && vertice1 < cantidadVertices && vertice2 >= 0 && vertice2 < cantidadVertices)
    {
        matrizAdyacencia[vertice1][vertice2] = 0;
        matrizAdyacencia[vertice2][vertice1] = 0;
        cantidadAristas--;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------------

#endif // __GRAFO__cxx__