#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Grafo.cpp"
#include "Grafo.h"
using namespace std;
typedef Grafo<string, int> TGrafo;

int main()
{
  
   TGrafo grafo;

  for(int i=0; i<4;i++){
    string a,b,c,d;
    cout<<"Ingrese el nombre del vertice"<<endl;
    cin>>a;
    grafo.insertarVertice(a);
    cout<<"Ingrese el nombre del vertice"<<endl;
    cin>>b;
    grafo.insertarVertice(b);
    cout<<"Ingrese el nombre del vertice"<<endl;
    cin>>c;
    grafo.insertarVertice(c);
    cout<<"Ingrese el nombre del vertice"<<endl;
    cin>>d;
    grafo.insertarVertice(d);
  }
     
 /* En nuestro ejemplo los vertices que se deben ingresar 
    son:
    grafo.insertarVertice("c1");
    grafo.insertarVertice("c1");
    grafo.insertarVertice("c1");
    grafo.insertarVertice("c1"); */

  //rellenar aristas y el peso entre de las aristas 
  for(int j=0; j<8;j++){
    int a,b,c,d,e,f,g;
    
    cout<<"Ingrese el peso que se encuentra entre las aristas a c1-c2 "<<endl;
    cin>>a;
    grafo.insertarArista("c1", "c2", a);
    cout<<"Ingrese el peso que se encuentra entre las aristas a c1-c4 "<<endl;
    cin>>b;
    grafo.insertarArista("c1", "c4", b);

    cout<<"Ingrese el peso que se encuentra entre las aristas a c2-c1 "<<endl;
    cin>>c;
    grafo.insertarArista("c2", "c1", c);
    cout<<"Ingrese el peso que se encuentra entre las aristas a c2-c3 "<<endl;
    cin>>d;
    grafo.insertarArista("c2", "c3", d);

    cout<<"Ingrese el peso que se encuentra entre las aristas a c3-c1 "<<endl;
    cin>>e;
    grafo.insertarArista("c3", "c1", e);

    cout<<"Ingrese el peso que se encuentra entre las aristas a c4-c2 "<<endl;
    cin>>f;
    grafo.insertarArista("c4", "c2", f);
    cout<<"Ingrese el peso que se encuentra entre las aristas a c4-c3 "<<endl;
    cin>>g;
    grafo.insertarArista("c4", "c3", g);
       
  }
  
  /* En nuestro ejemplo los pesos de las aristas que se deben ingresar 
    son:
    grafo.insertarArista("c1", "c2", 2);
    grafo.insertarArista("c1", "c4", 3);

    grafo.insertarArista("c2", "c1", 6);
    grafo.insertarArista("c2", "c3", 5);

    grafo.insertarArista("c3", "c1", 3);

    grafo.insertarArista("c4", "c2", 5);
    grafo.insertarArista("c4", "c3", 3);
     */
 
  //con estos datos ingresados el grafo de ejemplo quedaria armado 
  
  
}
