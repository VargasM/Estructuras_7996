#ifndef __GRAFO__HXX__
#define __GRAFO__HXX__

#include <iostream>
#include <climits>

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

template< class T, class U> int Grafo<T,U>::buscarVertice(int indicador){
  int ind = -1;
  for(int i = 0 ; i < cantVertices(); i++){
    if(this->vertices[i].identificador == indicador)
        ind= i;
  }
    return ind;
}

template< class T, class U> bool Grafo<T,U>::insertarVertice ( T vert )
{
    bool res = false;
    if (buscarVertice(vert.identificador) == -1){
        this->vertices.push_back(vert);
        std::vector< std::pair< int, U >>  *nvector = new std::vector < std::pair < int, U >>;
        this->aristas.push_back(*nvector);
        res = true;
    }
  return res;
}

template< class T, class U> bool Grafo<T,U>::insertarArista( T origen, T destino, U costo){
 bool res = false;
 int i_origen = buscarVertice(origen.identificador);
  //std::cout<<"Origen: "<<i_origen<<std::endl;
 int i_destino = buscarVertice(destino.identificador);
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
		int i_ori = buscarVertice(origen.identificador);
		int i_des = buscarVertice(destino.identificador);
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
		int i_vert = buscarVertice(vert.identificador);
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
		int i_ori = buscarVertice(origen.identificador);
		int i_des = buscarVertice(destino.identificador);
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

template< class T, class U> std::vector<T>  Grafo<T,U>::obtenerVertices(){
  return vertices;
}

template< class T, class U> T Grafo<T,U>::obtenerVertice(long start){
  T Vacio;
  for(int i = 0 ; i < cantVertices(); i++){
    if(this->vertices[i].identificador == start){
      return this->vertices[i];
      }
    }
  return Vacio;
}

template< class T, class U> void Grafo<T,U>::InicializarRecorrido(std::vector<AlgoritmoD> RecorridoP){
  for(int i=0; i<this->Recorrido.size(); i++){
      RecorridoP.push_back(this->Recorrido[i]);
    }
    //std::cout<<"tamano vctor"<<RecorridoP.size()<<std::endl;
}

template< class T, class U> std::vector<AlgoritmoD> Grafo<T,U>::obtenerRecorrido(){
  return this->Recorrido;
}

template<class T, class U> void Grafo<T,U>::InicializarRecorridoPrim(){
  for(int i=0; i<this->Recorrido.size(); i++){
    if(i==0){
        this->Recorrido[i].fijarCostoConexion(0);
        this->Recorrido[i].fijarVisitado(true);
        this->Recorrido[i].fijarPredecesor(-1);
          }
      else{
        this->Recorrido[i].fijarCostoConexion(INT_MAX);
        this->Recorrido[i].fijarVisitado(false);
        this->Recorrido[i].fijarPredecesor(-1);
      }
  }
}

template< class T, class U> void Grafo<T,U>::insertarElemento(int id){
  AlgoritmoD Nuevo;
  Nuevo.fijarID(id);
  if(id==0){
      Nuevo.fijarCostoConexion(0);
      Nuevo.fijarVisitado(true);
        }
    else{
      Nuevo.fijarCostoConexion(INT_MAX);
      Nuevo.fijarVisitado(false);
    }
  this->Recorrido.push_back(Nuevo);
}

template< class T, class U> void Grafo<T,U>::GenerarRecorridoPrim(int destino){
  int marcados=0;
  int NodoActual=0;
  float costoMin=INT_MAX;
  float costoCalculado=0;
  int idNodo=0;
  typename std::vector<std::pair<int,U>>::iterator it;
  //std::cout<<"\nFuncion Generar Recorrido Prim"<<std::endl;
  this->InicializarRecorridoPrim();
  
  while(marcados<vertices.size()){
    //std::cout<<"Entro al while "<<this->Recorrido[destino].obtenerID()<<std::endl;
    costoMin=INT_MAX;
    for(it=aristas[NodoActual].begin(); it<aristas[NodoActual].end(); it++){
    //  std::cout<<"Nodo actual "<<NodoActual<<std::endl;
      if(this->Recorrido[it->first].obtenerVisitado()==false){
        //std::cout<<"Nodo actual recorrido: "<<this->Recorrido[it->first].obtenerID()<<std::endl;
        //std::cout<<"Nodo conexion "<<it->first<<std::endl;
        //std::cout<<"Costo Arista "<<it->second<<std::endl;
        costoCalculado=it->second;
        if(costoCalculado<this->Recorrido[it->first].obtenerCostoConexion()){
          this->Recorrido[it->first].fijarCostoConexion(costoCalculado);
          this->Recorrido[it->first].fijarPredecesor(NodoActual);
          //std::cout<<"costo conexipn "<<costoCalculado<<std::endl;
        }
      }
   }
    //std::cout<<"\nId nodo"<<idNodo<<std::endl;
    //this->Recorrido[idNodo].fijarPredecesor(NodoActual);
    int minimoC=INT_MAX;
    for(int i=1; i<this->Recorrido.size(); i++){
      if(this->Recorrido[i].obtenerVisitado()==false && this->Recorrido[i].obtenerCostoConexion()<=minimoC){
        minimoC=this->Recorrido[i].obtenerCostoConexion();
        idNodo=i;
      }
    }
  NodoActual=this->Recorrido[idNodo].obtenerID(); 
 this->Recorrido[NodoActual].fijarVisitado(true);
 //std::cout<<"Visitado "<<this->Recorrido[NodoActual].obtenerID()<<std::endl; 
 marcados=marcados+1;
//std::cout<<"marcados "<<marcados<<std::endl;
  }
}

template< class T, class U> void Grafo<T,U>::GenerarRecorrido(int destino){
  int marcados=0;
  int NodoActual=0;
  float costoMin=INT_MAX;
  float costoCalculado=0;
  int idNodo=0;
  typename std::vector<std::pair<int,U>>::iterator it;
  //std::cout<<"\nFuncion Generar Recorrido"<<std::endl;
  this->InicializarRecorridoPrim();
  
  while(marcados<vertices.size()){
    //std::cout<<"Entro al while "<<this->Recorrido[destino].obtenerID()<<std::endl;
    costoMin=INT_MAX;
    for(it=aristas[NodoActual].begin(); it<aristas[NodoActual].end(); it++){
      //std::cout<<"Nodo actual "<<NodoActual<<std::endl;
      if(this->Recorrido[it->first].obtenerVisitado()==false){
        //std::cout<<"Nodo actual recorrido: "<<this->Recorrido[it->first].obtenerID()<<std::endl;
        //std::cout<<"Nodo conexion "<<it->first<<std::endl;
        //std::cout<<"Costo Arista "<<it->second<<std::endl;
        costoCalculado=it->second+this->Recorrido[NodoActual].obtenerCostoConexion();
        if(costoCalculado<this->Recorrido[it->first].obtenerCostoConexion()){
          this->Recorrido[it->first].fijarCostoConexion(costoCalculado);
          this->Recorrido[it->first].fijarPredecesor(NodoActual);
          //std::cout<<"costo conexipn "<<costoCalculado<<std::endl;
        }
      }
   }
    //std::cout<<"\nId nodo"<<idNodo<<std::endl;
    //this->Recorrido[idNodo].fijarPredecesor(NodoActual);
    int minimoC=INT_MAX;
    for(int i=1; i< this->Recorrido.size(); i++){
      if(this->Recorrido[i].obtenerVisitado()==false && this->Recorrido[i].obtenerCostoConexion()<=minimoC){
        minimoC=this->Recorrido[i].obtenerCostoConexion();
        idNodo=i;
      }
    }
  NodoActual=this->Recorrido[idNodo].obtenerID(); 
 this->Recorrido[NodoActual].fijarVisitado(true);
 //std::cout<<"Visitado "<<this->Recorrido[NodoActual].obtenerID()<<std::endl; 
 marcados=marcados+1;
//std::cout<<"marcados "<<marcados<<std::endl;
  }
}

#endif

