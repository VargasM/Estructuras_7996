// TODO # 0: Incluir el archivo cabecera del grafo
#include "Grafo.h"
#include "Dijk.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
//g++ -std=c++11 -o exe main.cxx Dijk.cxx
// -------------------------------------------------------------------------
struct Punto
{
  int identificador;
  float X, Y;
  float distanciaA( const Punto& b ) const
    {
      float x = X - b.X;
      float y = Y - b.Y;
      return( std::sqrt( ( x * x ) + ( y * y ) ) );
    }
};

// -------------------------------------------------------------------------

// TODO # 1: Definir el tipo para un grafo con Puntos como vertices y costos reales
typedef Grafo<Punto,double> Condominio;

typedef std::vector< unsigned long > TRuta;
typedef std::vector< TRuta > TCaminos;
typedef std::vector< float > TDist;

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  if( argc < 2 )
  {
    std::cerr
      << "Uso: " << argv[ 0 ] << " archivo_entrada"
      << std::endl;
    return( 1 );
  }

  // TODO # 2: Declarar el grafo
   Condominio grafo;

  // Cargar el archivo en un bufer
  std::ifstream in_mesh_stream( argv[ 1 ], std::ifstream::binary );
  if( !in_mesh_stream )
  {
    std::cerr << "Error leyendo \"" << argv[ 1 ] << "\"" << std::endl;
    return( 1 );
  }
  
  in_mesh_stream.seekg( 0, in_mesh_stream.end );
  unsigned long in_mesh_file_length = in_mesh_stream.tellg( );
  in_mesh_stream.seekg( 0, in_mesh_stream.beg );
  char* in_mesh_file_buffer = new char[ in_mesh_file_length ];
  in_mesh_stream.read( in_mesh_file_buffer, in_mesh_file_length );
  in_mesh_stream.close( );
  std::istringstream in_mesh( in_mesh_file_buffer );

  // Leer los vertices desde el bufer
  long nPoints;
  int identificador=0;
  in_mesh >> nPoints;
  for( long pId = 0; pId < nPoints; pId++ )
  {
    Punto pnt;
    in_mesh >> pnt.X >> pnt.Y;
    // TODO # 3: Insertar el Punto en el grafo
    pnt.identificador=identificador;
    grafo.insertarElemento(identificador);
    identificador+=1;
    grafo.insertarVertice(pnt);
  }

  // Leer las aristas desde el bufer
  long nEdges;
  in_mesh >> nEdges;
  for( long eId = 0; eId < nEdges; eId++ )
  {
    long start, end;
    in_mesh >> start >> end;
   // TODO # 4: Calcular el costo de la arista
    Punto verticeInicio= grafo.obtenerVertice(start);
    Punto verticeFinal= grafo.obtenerVertice(end);
    float costo=verticeInicio.distanciaA(verticeFinal);
    
  // Insertarla en el grafo como no dirigida
    grafo.insertarArista(verticeInicio,verticeFinal,costo);
    grafo.insertarArista(verticeFinal,verticeInicio,costo);
  }
  delete [] in_mesh_file_buffer;

  std::cout << "Porteria: " 
            << grafo.obtenerVertice(0).X << "," << grafo.obtenerVertice(0).Y << std::endl;

  //TODO # 5: Calcular distancias lineales (distancia Euclidiana) respecto al origen
    for(int i=0; i<grafo.cantVertices(); i++){
      if(i>0){
        std::cout<<"Distancia lineal desde el origen 0 al vertice "<<i<<" es: "<<grafo.obtenerVertice(i).distanciaA(grafo.obtenerVertice(0))<<std::endl;
        }
    }

  /* TODO # 6: Encontrar las rutas de costo minimo usando los algoritmos requeridos
  */

  /* TODO # 7: Imprimir el informe de Prim */
  std::cout<<"\nAlgoritmo de Prim"<<std::endl;
  grafo.GenerarRecorridoPrim(0);
  std::vector<AlgoritmoD> RecorridoPrim;
  int actual;
  float costo=0;
  for(int i=1; i<grafo.obtenerVertices().size(); i++){
    costo=0;
    int cT;
    std::cout<<"\nDestino "<<i<<std::endl;
    std::cout<<"La ruta de menor costo desde la portería hasta el vertice "<<i<<" es: "<<std::endl;
    actual=i;
    RecorridoPrim=grafo.obtenerRecorrido();
    std::stack<int> ResultadoPrim;
    ResultadoPrim.push(RecorridoPrim[actual].obtenerID());
    
    while(actual!=0){              
      costo=costo+RecorridoPrim[actual].obtenerCostoConexion();
      ResultadoPrim.push(RecorridoPrim[actual].obtenerPredecesor());
        actual=RecorridoPrim[actual].obtenerPredecesor();
    }
    while(!ResultadoPrim.empty()){
      std::cout<<ResultadoPrim.top()<<", ";
      ResultadoPrim.pop();
    }
    std::cout<<"Costo total de la ruta: "<<costo<<std::endl;
  }

  /* TODO # 8: Imprimir el informe de Dijkstra (mismo fomato que informe de Prim)*/
   std::cout<<"\nAlgoritmo de Dijkstra"<<std::endl;
  std::vector<AlgoritmoD> Recorrido;
  grafo.GenerarRecorrido(0);
  int cT;
  
  for(int i=1; i<grafo.obtenerVertices().size(); i++){
    cT=0;
    std::cout<<"\nDestino "<<i<<std::endl;
    std::cout<<"La ruta de menor costo desde la portería hasta el vertice "<<i<<" es: "<<std::endl;
    actual=i;
    Recorrido=grafo.obtenerRecorrido();
    std::stack<int> Resultado;
    //std::cout<<i<<std::endl;
    Resultado.push(Recorrido[actual].obtenerID());
    while(actual!=0){        Resultado.push(Recorrido[actual].obtenerPredecesor());
        actual=Recorrido[actual].obtenerPredecesor();
    }
    while(!Resultado.empty()){
      std::cout<<Resultado.top()<<", ";
      Resultado.pop();
    }
    std::cout<<"Costo total de la ruta: "<<Recorrido[i].obtenerCostoConexion()<<std::endl;
  }

  return( 0 );
}

// eof - taller_5_grafos.cxx
//g++ -std=c++11 -o exe main.cxx Dijk.cxx