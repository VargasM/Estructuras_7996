#include "vertex.h"
#include <vector>

using namespace std;

template <class T>
Vertex<T>::Vertex (){

    this->traversed = false;

}


// --------------------------------------------------------------

template <class T>
Vertex<T>::Vertex (T newValue){

    this->traversed = false;
    this->value = newValue;
}


// --------------------------------------------------------------

template <class T>
T Vertex<T>::getValue (){

    return this->value;
    
}


// --------------------------------------------------------------

template <class T>
void Vertex<T>::setValue (T newValue){

    this->value = newValue; 
}



// --------------------------------------------------------------

template <class T>
bool Vertex<T>::getTraversed (){

    return this->traversed;
    
}



// --------------------------------------------------------------

template <class T>
void Vertex<T>::setTraversed (bool newTraversed){

    this->traversed = newTraversed;
}
