#include <iostream>
#include "graph.h"
#include <string>
#include "vertex.h"

using namespace std;

typedef Graph<string, int> TGraph;

int main (){

    TGraph graph;

    graph.addVertex("C1");
    graph.addVertex("C2");
    graph.addVertex("C3");
    graph.addVertex("C4");

    cout << "Busqueda de vertice C1: " << graph.searchVertex("C1") << endl;
    cout << "Busqueda de vertice C2: " << graph.searchVertex("C2") << endl;
    cout << "Busqueda de vertice C3: " << graph.searchVertex("C3") << endl;
    cout << "Busqueda de vertice C4: " << graph.searchVertex("C4") << endl;

    graph.addEdge("C1", "C2", 2);
    graph.addEdge("C1", "C4", 3);
    graph.addEdge("C2", "C1", 6);
    graph.addEdge("C2", "C4", 2);
    graph.addEdge("C2", "C3", 5);
    graph.addEdge("C3", "C1", 3);
    graph.addEdge("C4", "C3", 6);
    graph.addEdge("C4", "C2", 5);

    cout << "Busqueda de arista C1-C2: " << graph.searchEdge("C1", "C2") << endl;
    cout << "Busqueda de arista C2-C1: " << graph.searchEdge("C2", "C1") << endl;
    cout << "Busqueda de arista C3-C1: " << graph.searchEdge("C3", "C1") << endl;
    cout << "Busqueda de arista C4-C2: " << graph.searchEdge("C4", "C2") << endl;


    cout << "Numero de vertices: " << graph.numVertices() << endl;
    cout << "Numero de aristas: " << graph.numEdges() << endl;

    graph.addVertex("C5");
    graph.addEdge("C5", "C2", 10);


    cout << "Busqueda de vertice C5 despues de insercion: " << graph.searchVertex("C5") << endl;
    cout << "Busqueda de arista C5-C2 despues de insercion: " << graph.searchEdge("C5", "C2") << endl;

    graph.deleteEdge("C5", "C2");
    graph.deleteVertex("C5");    

    cout << "Busqueda de vertice C5 despues de eliminacion: " << graph.searchVertex("C5") << endl;
    cout << "Busqueda de arista C5-C2 despues de eliminacion: " << graph.searchEdge("C5", "C2") << endl;


    return 0; 
}
