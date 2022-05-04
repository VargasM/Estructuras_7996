#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;



//Lista de adyacencia

template< class T, class U>
class Grafo {
private:
  std::vector<T> vertices ;
  //Aristas: lista de listas de pares, donde cada par contiene un índice de vértice (entero) y un costo de conexión (plantilla).
  std::vector < std::vector< std::pair< int, U > > > aristas;

public:
  Grafo();
  int cantVertices(){ return vertices.size(); }
  int cantAristas (){
      int suma = 0;
      for (int i=0; i< cantVertices(); i++){
        suma += aristas[i].size() ;
      }
      return suma;
  }

  int buscarVertices(T vert){
    int ind = -1;
    for(int i = 0 ; i < cantVertices(); i++){
      if(vertices[i] == vert)
          ind= i;
    }
      return ind;
  }

  bool insertarVertice ( T vert )
  {
      bool res = false;
      if (buscarVertice(vert) == -1){
          vertices.push_back(vert);
          std::vector< std::pair< int, U >>  *nvector = new std::vector < std::pair < int, U >>;
          aristas.push_back(*nvector);
          res = true;
      }
    return res;
  }

  bool insertarArista( T ori, T des, U cos ){
     bool res = false;
     int i_ori = buscarVertice(ori);
     int i_des = buscarVertice(des);
     if(i_ori != -1 && i_des != -1){
          bool esta = false;
          typename std::vector< std::pair<int, U>>:: iterator it = aristas[i_ori].begin();
          for(; it != aristas[i_ori].end(); it++){
                if(it->first == i_des) esta = true;
          }
          if (!esta){
            std::pair<int, U> *n_par = new std::pair<int, U>;
            n_par -> first = i_des;
            n_par -> second = cos;
            aristas[i_ori].push_back(n_par);
            res = true;
          }
     }
     return res;
  }

  U buscarArista(T ori, T des) {
		U res = -1;
		int i_ori = buscarVertice(ori);
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			typename std::vector< pair<int,U> >::iterator it = aristas[i_ori].begin();
			for (; it != aristas[i_ori].end(); it++) {
				if (it->first == i_des)  res = it->second;
			}
		}
		return res;
	}
	bool eliminarVertice(T vert) {
		bool res = false;
		int i_vert = buscarVertice(vert);
		if ( i_vert != -1) {
			typename std::vector< std::list< pair<int,U> > >::iterator itA, posE;
			int ind = 0;
			for (itA = aristas.begin(); itA != aristas.end(); itA++, ind++) {
				if (ind == i_vert) {
					posE = itA;
				} else {
					typename std::vector< std::pair<int,U> >::iterator it, posEE;
					for (it = itA->begin(); it != itA->end(); it++) {
						if (it->first == i_vert) {
							posEE = it;
						}
					}
					itA->erase(posEE);
				}
			}
			aristas.erase(posE);
		}
		return res;
	}
	bool eliminarArista(T ori, T des) {
		bool res = false;
		int i_ori = buscarVertice(ori);
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			typename vector< pair<int,U> >::iterator it, posE;
			for (it = aristas[i_ori].begin(); it != aristas[i_ori].end(); it++) {
				if (it->first == i_des)  posE = it;
			}
			aristas[i_ori].erase(posE);
		}
		return res;
	}
};
