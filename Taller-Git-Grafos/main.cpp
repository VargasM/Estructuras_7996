//
// Created by yeusepe on 4/29/22.
//

#include "grafo.h"

// Taller-Git-Grafos
// Generar un grafo con 4 nodos, C1, C2, C3 y C4, y conectarlos de la siguiente manera:
// C1 -> C2 con peso 2
// C1 -> C4 con peso 3
// C2 -> C1 con peso 6
// C2 -> C3 con peso 5
// C2 -> C4 con peso 2
// C3 -> C1 con peso 3
// C4 -> C3 con peso 6
// C4 -> C2 con peso 5

int main() {

    std::cout << std::endl << std::endl << "Taller-Git-Grafos" << std::endl << std::endl;

    // Pruebas

    grafo g;

    std::cout << "Creando grafo..." << std::endl;

    verticeGrafo v1("C1");
    verticeGrafo v2("C2");
    verticeGrafo v3("C3");
    verticeGrafo v4("C4");

    std::cout << "Agregando vertices..." << std::endl;

    g.agregarVertice(v1);
    g.agregarVertice(v2);
    g.agregarVertice(v3);
    g.agregarVertice(v4);

    std::cout << "Agregando aristas..." << std::endl;

    // Aristas de C1
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
    g.agregarArista("C4", "C3", 6);

    std::cout <<  std::endl;
    // Prueba cantidad de vertices
    std::cout << "Cantidad de vertices: " << g.getCantidadVertices() << std::endl;

    // Prueba cantidad de aristas
    std::cout << "Cantidad de aristas: " << g.getCantidadAristas() << std::endl;

    std::cout <<  std::endl;

    // Prueba Buscar vertice
    std::cout << "Buscar vertice: " << g.buscarVertice("C1")->getNombre() << std::endl;

    // Prueba Buscar arista
    std::cout << "Buscar arista: " << g.buscarArista("C2C1")->peso << std::endl;

    // Prueba imprimir grafo

    std::cout <<  std::endl;
    std::cout << "Mostrando grafo..." << std::endl;

    std::list<std::string> visitados; ///< Lista de vertices visitados

    // Prueba recorrido plano
    g.recorridoPlano();

    // Prueba recorrido en profundidad
    std::cout << "Recorrido en profundidad: " << std::endl;
    g.recorridoProfundidad("C2", visitados);

    // Imprimir visitados
    for (auto it = visitados.begin(); it != visitados.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Eliminar lista de visitados
    visitados.clear();

    // Prueba recorrido en anchura
    std::cout << "Recorrido en anchura: " << std::endl;
    g.imprimirRecorridoAnchura("C2", visitados);

    // Imprimir visitados
    for (auto it = visitados.begin(); it != visitados.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl << std::endl;

    // Prueba eliminar vertice
    std::cout << "Eliminando vertice..." << std::endl;
    g.eliminarVertice("C1");
    std::cout << "Cantidad de vertices: " << g.getCantidadVertices() << std::endl;
    std::cout << "Cantidad de aristas: " << g.getCantidadAristas() << std::endl;

    std::cout <<  std::endl;

    // Prueba eliminar arista
    std::cout << "Eliminando arista..." << std::endl;
    g.eliminarArista("C2C1");
    std::cout << "Cantidad de vertices: " << g.getCantidadVertices() << std::endl;
    std::cout << "Cantidad de aristas: " << g.getCantidadAristas() << std::endl;

    return 0;
}