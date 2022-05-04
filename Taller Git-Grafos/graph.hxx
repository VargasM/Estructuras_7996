#include "graph.h"
#include "vertex.h"
#include <vector>
#include <utility>


using namespace std;

template <class T, class U>
vector<Vertex<T>> Graph<T,U>::getVertices(){

    return this->vertices;
}

// --------------------------------------------------------------

template <class T, class U>
void Graph<T, U>::setVertices(vector<Vertex<T>> newVertices){

    this->vertices = newVertices;
}

// --------------------------------------------------------------


template <class T, class U>
bool Graph<T, U>::addVertex(T vertex){

    bool inserted = false;

    if (searchVertex() == -1){  // if the vertex, ISNT found, we add it to the vector.
        Vertex newVertex (vertex);  // create new vertex with value
        vertices.push_back(newVertex);  // insert new vertex into vector
        vector<pair<int, U>>* nvector = new vector <pair<int, u>>;   // create the vector of edges of the new node
        edges.push_back(nvector);       // insert the new edges vector into main edges vector
        inserted = true;
    }
    return inserted;
}   

// --------------------------------------------------------------

template <class T, class U>
int Graph<T, U>::searchVertex(T value){


    if (this->vertices.empty() == false){   // si el grafo NO esta vacio, se busca el nodo
        int index = -1;

        for(int i = 0 ; i < (); i++){   
            if(vertices[i] == vert)
             ind= i;
        }
        return ind;           // if the vertex isn't found, return -1. If it is found,
                            // return the index of the position in the vertices vector
                            // where the node is located.
    }
    

}

// --------------------------------------------------------------

template <class T, class U>
bool Graph<T, U>::deleteVertex(T vertex){

    bool eliminated = false;
    int i_vertex = searchVertex(vertex);

    if (i_vertex != 1){
        vector <vector<pair<int, U>>>::iterator itA, posE;
        int index = 0;

        for (itA = edges.begin(); itA != edges.end(); itA++, index++){
            if (index == i_vertex){
                posE = itA;
            } else {
                vector<pair<int, U>>::iterator it, posEE;
                for (it = itA->begin(); it != itA -> end(); it++){
                    if (it -> first == i_vertex)
                        posEE = it;
                }
                itA->erase(posEE);
            }
        }
        edges.erase(posEE);
    }

    return eliminated;

}

// --------------------------------------------------------------

template <class T, class U>
bool Graph<T, U>::addEdge(T origin, T destiny, U weight){

    bool inserted = false;
    bool i_origin = searchVertex(origin);
    bool i_destiny = searchVertex (destiny);

    if (i_origin != 1 && i_destiny != -1){
        bool exists = false;

        vector<pair<int, U>>::iterator it = edges[i_origin].begin();
        for (; it != edges[i_destiny].end(); it++){
            if (it->first == i_destiny)
                exists = true;
        }
    
        if (exists = false){
            pair<int, U>* new_pair = new pair <int, U>;
            new_pair -> first = i_destiny;
            new_pair -> second = weight;
            edges[i_origin].push_back(*new_pair);
            inserted = true;
        }


    }
    return inserted;
}


// --------------------------------------------------------------
template <class T, class U>
U Graph<T, U>::searchEdge(T origin, T destiny){

    U res = -1;
    bool i_origin = searchVertex(origin);
    bool i_destiny = searchVertex (destiny);

    if (i_origin != -1 && i_destiny != -1){
        vector<pair<int, U>>::iterator it = edges[i_origin].begin();
        for (; it != edges[i_origin].end(); it++){
            if (it-> first == i_destiny)
                res = it->second;
        }
    }
    return res;
   
}

// --------------------------------------------------------------

template <class T, class U>
bool Graph<T, U>::deleteEdge(T origin, T destiny){

    bool eliminated = false;
    bool i_origin = searchVertex(origin);
    bool i_destiny = searchVertex (destiny);

    if (i_origin != -1 && i_destiny != -1){
        vector<pair<int,U>>::iterator it, posE;

        for (it = edges[i_origin].begin(); it != edges[i_origin].end(); it++){
            if (it->first == i_destiny)
                posE = it;
        }
        edges[i_origin].erase(posE);
    }
    
    return eliminated;

}

// --------------------------------------------------------------

template<class T, class U>
int Graph<T, U>::numVertices(){

    return this ->vertices.size();

}

// --------------------------------------------------------------

template<class T, class U>
int Graph<T, U>::numEdges(){

    int sum = 0;

      for (int i=0; i< (this->numVertices()); i++){
        sum += edges[i].size()
      }
      return sum;
}

// --------------------------------------------------------------




// eof - graph.hxx