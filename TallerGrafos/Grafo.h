#include <deque>
#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

template< class T, class U>
class Grafo {
private:
	std::vector<T> vertices ;
	std::vector < std::vector< std::pair< int, U > > > aristas;
public:
	Grafo();
	~Grafo();
  int cantVertices();
  int cantAristas ();
  int buscarVertices(T vert);
  bool insertarVertice ( T vert );
  bool insertarArista( T ori, T des, U cos );
  U buscarArista(T ori, T des);
  bool eliminarVertice(T vert);
  bool eliminarArista(T ori, T des);
};