#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "VerticeGrafo.cxx"

int main()
{
    VerticeGrafo v1("C1");
    VerticeGrafo v2("C2");
    VerticeGrafo v3("C3");
    VerticeGrafo v4("C4");

    v1.agregarArista("C1", 2, &v2);
    v1.agregarArista("C1", 3, &v4);

    v2.agregarArista("C2", 6, &v1);
    v2.agregarArista("C2", 5, &v3);
    v2.agregarArista("C2", 2, &v4);

    v3.agregarArista("C3", 3, &v1);

    v4.agregarArista("C4", 5, &v2);
    v4.agregarArista("C4", 6, &v3);
/*    // Aristas de C1
    g.agregarArista("C1", "C2", 2);
    g.agregarArista("C1", "C4", 3);

    // Aristas de C2
    g.agregarArista("C2", "C1", 6);
    g.agregarArista("C2", "C3", 5);
    g.agregarArista("C2", "C4", 2);

    // Aristas de C3
    g.agregarArista("C3", "C1", 3);

    // Aristas de C4
    g.agregarArista("C4", "C2", 5);
    g.agregarArista("C4", "C3", 6);*/

    std::cout <<  std::endl;
    std::cout << "Mostrando grafo..." << std::endl;
    v1.imprimir();

    // menu de opciones para el usuario que desea realizar una accion sobre el grafo
    std::cout << std::endl;
    std::cout << "Menu de opciones:" << std::endl;
    std::cout << "1. eliminar vertice" << std::endl;
    std::cout << "2. eliminar arista" << std::endl;
    std::cout << "3. imprimir grafo" << std::endl;

    int opcion;
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        std::cout << "Eliminando vertice..." << std::endl;
        break;
    case 2:
        std::cout << "Eliminando arista..." << std::endl;
        break;
    case 3:
        std::cout << "Imprimiendo grafo..." << std::endl;
        v1.imprimir();
        break;
    default:
        std::cout << "Opcion no valida" << std::endl;
    return 0;
    }
}

