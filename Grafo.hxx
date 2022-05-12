#ifndef __GRAFO__HXX__
#define __GRAFO__HXX__

#include <iostream>

template< class T, class U>
Grafo< T ,  U >::Grafo(){
};

template< class T, class U> int Grafo < T , U >::cantVertices(){ 
  return vertices.size(); 
};

template< class T, class U> int Grafo<T,U>::cantAristas (){
    int sum = 0;
    for (int i=0; i< cantVertices(); i++){
      sum += aristas[i].size();
    }
    return sum;
}

template< class T, class U> 
int Grafo<T,U>::buscarVertice(T vert){
  int ind = -1;
  for(int i = 0 ; i < cantVertices(); i++){
    if(this->vertices[i] == vert)
        ind= i;
  }
    return ind;
}

template< class T, class U> bool Grafo<T,U>::insertarVertice ( T vert )
{
    bool res = false;
    if (buscarVertice(vert) == -1){
        this->vertices.push_back(vert);
        std::vector< std::pair< int, U >>  *nvector = new std::vector < std::pair < int, U >>;
        this->aristas.push_back(*nvector);
        res = true;
    }
  return res;
}

template< class T, class U> bool Grafo<T,U>::insertarArista( T origen, T destino, U costo){
 bool res = false;
 int i_origen = buscarVertice(origen);
  //std::cout<<"Origen: "<<i_origen<<std::endl;
 int i_destino = buscarVertice(destino);
  //std::cout<<"destino: "<<i_destino<<std::endl;
  
 if(i_origen != -1 && i_destino != -1){
      bool esta = false;
      typename std::vector<std::pair<int, U> >::iterator it;  //pregunta
      for(it=aristas[i_origen].begin(); it != aristas[i_origen].end(); it++){
            if(it->first == i_destino) 
              esta = true;
              //std::cout<<"Está";
      }
      if (!esta){
        std::pair<int, U> *n_par = new std::pair<int, U>;
        n_par -> first = i_destino;
        n_par -> second = costo;
        aristas[i_origen].push_back(*n_par);
        //std::cout<<"Lo insertó "<<std::endl;
        res = true;
      }
 }
 return res;
}

template< class T, class U> U Grafo<T,U>::buscarArista(T origen, T destino) {
		U res = -1;
		int i_ori = buscarVertice(origen);
		int i_des = buscarVertice(destino);
		if ( i_ori != -1 && i_des != -1 ) {
			typename std::vector<std::pair<int,U> >::iterator it = aristas[i_ori].begin();
			for (; it != aristas[i_ori].end(); it++) {
				if (it->first == i_des)  
          res = it->second;
			}
		}
		return res;
	}

template< class T, class U> bool Grafo<T,U>::eliminarVertice(T vert) {
		bool res = false;
		int i_vert = buscarVertice(vert);
		if ( i_vert != -1) {
      //std::cout<<"Lo encontro "<<i_vert<<std::endl;
			typename std::vector< std::vector<std::pair<int,U> > >::iterator itA; //¿Por qué lista de pares?
      typename std::vector< std::vector<std::pair<int,U> > >::iterator posE;
			int ind = 0;
			for (itA = aristas.begin(); itA != aristas.end(); itA++) {
        ind+=1;
				if (ind == i_vert) {
          //std::cout<<"Lo encontro: "<<std::endl;
					posE = itA;
				} else if(!itA->empty()){ //Es destino y no origen
          //std::cout<<itA->size()<<std::endl;
					typename std::vector<std::pair<int,U>>::iterator it;
          typename std::vector<std::pair<int,U>>::iterator posEE;    
          if(itA->size()>1){
					for (it = itA->begin(); it != itA->end(); it++) {
            //std::cout<<"Entra"<<std::endl;
						if (it->first == i_vert) {
							posEE = it;
						}
					}
					itA->erase(posEE); //Se elimina del vector al que es un destino
            }
				}
			}
			//aristas.erase(posE);//Si es oriden de alguna conexión, se elimina de ese vector aristas completamente
      vertices.erase(vertices.begin()+i_vert);
		}
		return res;
	}

template< class T, class U> bool Grafo<T,U>::eliminarArista(T origen, T destino) {
		bool res = false;
		int i_ori = buscarVertice(origen);
		int i_des = buscarVertice(destino);
		if ( i_ori != -1 && i_des != -1 ){
			typename std::vector<std::pair<int,U>>::iterator it; //Era un vector ¿Por que?
      typename std::vector<std::pair<int,U>>::iterator posE;
			for (it = aristas[i_ori].begin(); it != aristas[i_ori].end(); it++) {
				if (it->first == i_des)  
          posE = it;
			}
			aristas[i_ori].erase(posE);
		}
		return res;
	}

#endif

