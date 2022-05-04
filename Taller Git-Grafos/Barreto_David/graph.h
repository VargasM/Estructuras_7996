#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "vertex.h"
//#include "edge.h"
#include <vector>
#include <utility>


using namespace std;

template <class T, class U>
class Graph {

    protected:
        vector <Vertex<T>> vertices;                    // vector that contains all vertices in the graph.
        vector < vector< pair< int, U > > > edges;      // vector of vectors where each pair contais and index (int) and an edge weight(template)
    public:
        //gets
            vector<Vertex<T>> getVertices ();

        // sets 
            void setVertices (vector <Vertex<T>> newVertices); 
    
        // insertion, search and deletion
            bool addVertex(T value);
            int searchVertex(T value);
            bool deleteVertex(T vertex);
            bool addEdge(T origin, T destiny, U weight ); 
            U searchEdge(T origin, T destiny);
            bool deleteEdge(T origin, T destiny);

        // graph information
            int numVertices ();
            int numEdges();



};


#endif 

// eof - graph.h
