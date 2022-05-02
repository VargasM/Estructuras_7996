//archivo .h para la lectura de un grafo
// Language: cpp
// Path: Grafo.h

#ifndef __GRAFO__H__
#define __GRAFO__H__

class Grafo
{

public:
    Grafo();
    ~Grafo();
    int cantVertices();
    int cantAristas ();
    int buscarVertices(char *nombreVertice);
    int buscarArista(int vertice1, int vertice2);
    bool insertarVertice(char *nombreVertice);
    bool insertarArista(int vertice1, int vertice2, int peso);
    bool eliminarVertice(int vertice);
    bool eliminarArista(int vertice1, int vertice2);

private:
    int cantidadVertices;
    int cantidadAristas;
    int **matrizAdyacencia;
    char **nombreVertices;
};
    
#endif // __GRAFO__H__
// eof Grafo.h