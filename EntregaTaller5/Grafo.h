#ifndef __GRAFO__H__
#define __GRAFO__H__

#include "Dijk.h"
#include <vector>

template< class T, class U>
class Grafo {
private:
  std::vector<T> vertices ;
  //Aristas: lista de listas de pares, donde cada par contiene un índice de vértice (entero) y un costo de conexión (plantilla).
  std::vector < std::vector< std::pair< int, U > > > aristas;
 std::vector<AlgoritmoD> Recorrido;

public:
  Grafo();
  //manipuladores de la clase
  bool insertarVertice(T vertice);
  bool insertarArista(T,T,U);
  void insertarElemento(int);
  T obtenerVertice(long);
  int cantVertices();
  int cantAristas();
  int buscarVertice(T vertice);
  int buscarVertice(int vertice); //recibe el identificador
  U buscarArista(T,T);
  bool eliminarVertice(T Vertice);    
  bool eliminarArista(T,T);
  std::vector<T> obtenerVertices();
  std::vector<AlgoritmoD> obtenerRecorrido();
  void InicializarRecorrido(std::vector<AlgoritmoD>);
  void InicializarRecorridoPrim();
  void GenerarRecorrido(int destino);
  void GenerarRecorridoPrim(int destino);
};

#include "Grafo.hxx"

#endif 