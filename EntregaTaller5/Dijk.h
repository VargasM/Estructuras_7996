#ifndef __DIJK__H__
#define __DIJK__H__

#include <vector>

class AlgoritmoD{
  private:
  int ID; 
  float CostoConexion;
  int Predecesor; //El identificador de cada vertice
  int Visitado;

  public:
    AlgoritmoD();
    void fijarID(int);
    void fijarCostoConexion(float);
    void fijarPredecesor(int);
    void fijarVisitado(bool);
    float obtenerCostoConexion();
    int obtenerPredecesor();
    bool obtenerVisitado();
    int obtenerID();
};

#endif 