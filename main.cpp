#include "Grafo.h"
#include <iostream>
//g++ -std=c++11 -o exe main.cpp

int main() {
  Grafo<std::string,int> nuevo;
  //Insercion de vertices
  nuevo.insertarVertice("C1");
  nuevo.insertarVertice("C2");
  nuevo.insertarVertice("C3");
  nuevo.insertarVertice("C4");
  
  //Insercion de aristas
  nuevo.insertarArista("C1","C2",2);
  nuevo.insertarArista("C2","C1",6);
  nuevo.insertarArista("C2","C4",2);
  nuevo.insertarArista("C4","C2",5);
  nuevo.insertarArista("C4","C3",6);
  nuevo.insertarArista("C3","C1",3);
  nuevo.insertarArista("C1","C4",3);
  nuevo.insertarArista("C2","C3",5);
  
  std::cout <<"Cantidad de vertices: "<< nuevo.cantVertices()<<std::endl;
  std::cout <<"Cantidad de aristas: "<<nuevo.cantAristas()<<std::endl;

  std::cout<<"Buscar arista conexion C1 a C2"<<std::endl;
  std::cout<<"El peso de la arista buscada es: "<<nuevo.buscarArista("C1","C2")<<std::endl;

  std::cout<<"Eliminar arista conexion C1 a C2"<<std::endl;
  nuevo.eliminarArista("C1","C2");
  std::cout <<"Cantidad de vertices luego de la eliminacion: "<< nuevo.cantVertices()<<", cantidad de aristas: "<<nuevo.cantAristas()<<std::endl;

  std::cout<<"Eliminar vertice C3"<<std::endl;
  nuevo.eliminarVertice("C3");
  std::cout <<"Cantidad de vertices luego de la eliminacion: "<< nuevo.cantVertices()<<", Cantidad de aristas luego de la eliminacion: "<<nuevo.cantAristas()<<std::endl;
}