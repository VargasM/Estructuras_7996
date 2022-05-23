#include "Dijk.h"
#include <vector>

AlgoritmoD::AlgoritmoD(){
  this->CostoConexion=0;
}

void AlgoritmoD::fijarID(int id){
  this->ID=id;
}

void AlgoritmoD::fijarCostoConexion(float costo){
  this->CostoConexion=costo;
}
void AlgoritmoD::fijarPredecesor(int pred){
  this->Predecesor=pred;
}
void AlgoritmoD::fijarVisitado(bool vis){
  this->Visitado=vis;
}
float AlgoritmoD::obtenerCostoConexion(){
  return this->CostoConexion;
}
int AlgoritmoD::obtenerPredecesor(){
  return this->Predecesor;
}
bool AlgoritmoD::obtenerVisitado(){
  return this->Visitado;
}

int AlgoritmoD::obtenerID(){
  return this->ID;
}
