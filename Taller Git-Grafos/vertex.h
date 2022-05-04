#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <vector>
//#include "edge.h"


template <class T>
class Vertex {

    protected:
        T value;
        //std::vector <Edge*> edges;
        bool traversed;
    public:
    //constructors, destructors
        Vertex();
        Vertex(T value);
    // gets, sets
        T getValue();
        void setValue(T newValue);
        bool getTraversed();
        void setTraversed(bool newTraversed);


    // vertex operations 
        bool addEdge(int weight, Vertex<T>* destination);
        Vertex* searchNode();
};


#endif 

// eof - vertex.h