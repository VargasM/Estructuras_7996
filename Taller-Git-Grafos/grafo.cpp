//
// Created by yeusepe on 4/29/22.
//

#include "grafo.h"
#include <string>
#include <algorithm>

/**
 * @brief Constructor de la clase grafo
 */
grafo::grafo(){
}

/**
 * @brief Funcion que busca un vertice en el grafo
 * @param nombre Nombre del vertice que se buscara
 * @return verticeGrafo Vertice que se buscara
 */
verticeGrafo* grafo::buscarVertice(std::string nombre) {
    // Busca el vertice en el grafo
    for (auto it = this->vertices.begin(); it != this->vertices.end(); it++) {
        // Si el vertice es el que se busca
        if (it->getNombre() == nombre) {
            // Retorna el vertice
            return &(*it);
        }
    }
    // Si no se encontro el vertice
    return nullptr;
}



/**
 * @brief Funcion que agrega un vertice al grafo
 * @param vertice Vertice que se agregara al grafo
 */
void grafo::agregarVertice(verticeGrafo vertice) {
    // Busca si el vertice ya existe
    verticeGrafo* verticeExistente = this->buscarVertice(vertice.getNombre());
    // Si el vertice no existe
    if (verticeExistente == nullptr) {
        // Agrega el vertice al grafo
        this->vertices.push_back(vertice);
    } else {
        // Si el vertice existe
        std::cout << "El vertice ya existe" << std::endl;
    }
}

/**
 * @brief Funcion que elimina un vertice del grafo
 * @param nombre Nombre del vertice que se eliminara
 */
void grafo::eliminarArista(std::string nombre) {
    // Busca si el vertice existe
    verticeGrafo::aristaGrafo* arista = this->buscarArista(nombre);
    // Si existe la elimina
    verticeGrafo* verticeOrigen = this->buscarVertice(arista->origen);
    // Recorre el vector de aristas del vertice origen
    for (auto it = verticeOrigen->aristas.begin(); it != verticeOrigen->aristas.end(); it++) {
        // Si la arista es la que se eliminara
        if (it->nombre == nombre) {
            // Elimina la arista
            verticeOrigen->aristas.erase(it);
            break;
        }
    }
    // Actualiza la cantidad de aristas
    this->getCantidadAristas();
}

/**
 * @brief Funcion que elimina un vertice del grafo
 * @param nombre Nombre del vertice que se eliminara
 */
void grafo::eliminarVertice(std::string nombre) {
    // Busca si el vertice existe
    verticeGrafo* vertice = this->buscarVertice(nombre);
    // Si existe la elimina
    if (vertice != nullptr) {
        // Recorre el vector de aristas del vertice
        for (auto it = this->vertices.begin(); it != this->vertices.end(); it++) {
            // Si el vertice es el que se eliminara
            if (it->getNombre() == nombre) {
                // Elimina el vertice
                this->vertices.erase(it);
                break;
            }
        }
    }
    // Busca todas las aristas que tengan el vertice eliminado
    for (auto it = this->vertices.begin(); it != this->vertices.end(); it++) {
        // Recorre el vector de aristas del vertice
        for (auto it2 = it->aristas.begin(); it2 != it->aristas.end(); it2++) {
            // Si el vertice es el que se eliminara
            if (it2->nombre == nombre) {
                // Elimina la arista
                it->aristas.erase(it2);
            }
        }
    }
    // Actualiza la cantidad de vertices
    this->getCantidadVertices();
}

/**
 * @brief Funcion retorna todos los vertices del grafo
 * @return std::list<verticeGrafo> Lista de vertices del grafo
 */
std::list<verticeGrafo> grafo::getVertices() {
    return this->vertices;
}

/**
 * @brief Funcion retorna la cantidad de vertices del grafo
 * @return int Cantidad de vertices del grafo
 */
int grafo::getCantidadVertices() {
    return this->vertices.size();
}

/**
 * @brief Funcion retorna la cantidad de aristas del grafo
 * @return int Cantidad de aristas del grafo
 */
int grafo::getCantidadAristas() {
    int cantidad = 0;
    // Recorre el vector de vertices
    for (auto it = this->vertices.begin(); it != this->vertices.end(); it++) {
        // Recorre el vector de aristas del vertice
        cantidad += it->aristas.size();
    }
    return cantidad;
}


/**
 * @brief Funcion que agrega una arista al grafo
 */

void grafo::agregarArista(std::string nombreVertice1, std::string nombreVertice2, int peso){
    // Se busca el vertice con el direccion de vertice1
    verticeGrafo* vertice1 = this->buscarVertice(nombreVertice1);
    // Se busca el vertice con el direccion de vertice2
    verticeGrafo* vertice2 = this->buscarVertice(nombreVertice2);
    // Se busca si ya existe la arista
    if(vertice1->buscarArista(nombreVertice2) == nullptr){
        // Se agrega la arista al vertice
        vertice1->agregarArista(nombreVertice2, peso, vertice2);
    }
}

/**
 * @brief Recorrido plano del grafo
 */
void grafo::recorridoPlano() {
    std::cout << "Recorrido plano del grafo" << std::endl;
    // Recorre el vector de vertices
    for (auto it = this->vertices.begin(); it != this->vertices.end(); it++) {
        std::cout << it->getNombre() << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Recorrido en profundidad del grafo desde un vertice teniendo en cuenta el peso de las aristas de manera recursiva
 * @param vertice Nombre del vertice desde el cual se inicia el recorrido
 * @param visitados Direccion de lista de los nombres de los vertices visitados
 */
void grafo::recorridoProfundidad(std::string vertice, std::list<std::string>& visitados) {
    // Se busca el vertice con el direccion de vertice1
    verticeGrafo *vertice1 = this->buscarVertice(vertice);
    // Se agrega el vertice a la lista de visitados
    visitados.push_back(vertice1->getNombre());
    // Ordena la lista de aristas del vertice
    std::list<verticeGrafo::aristaGrafo> aristasOrdenadas = vertice1->ordenarAristas();
    // Recorre la lista de aristas del vertice
    for (auto it = aristasOrdenadas.begin(); it != aristasOrdenadas.end(); it++) {
        // Se busca el vertice con el direccion de vertice2
        verticeGrafo *vertice2 = this->buscarVertice(it->destino->getNombre());
        // Se busca si ya existe la arista
        if (std::find(visitados.begin(), visitados.end(), vertice2->getNombre()) == visitados.end()) {
            // Se llama recursivamente al metodo
            this->recorridoProfundidad(vertice2->getNombre(), visitados);
        }
    }
}

/**
 * @brief Buscar Arista
 * @param arista Nombre de la arista a buscar
 * @return verticeGrafo::aristaGrafo* Direccion de la arista
 */
verticeGrafo::aristaGrafo* grafo::buscarArista(std::string arista) {
    // Recorre todos los vertices del grafo
    for (auto it = this->vertices.begin(); it != this->vertices.end(); it++) {
        // Recorre todas las aristas del vertice
        for (auto it2 = it->aristas.begin(); it2 != it->aristas.end(); it2++) {
            // Se busca la arista
            if (it2->nombre == arista) {
                return &(*it2);
            }
        }
    }
    // Si no se encontro la arista se retorna nullptr
    return nullptr;
}

/**
 * @brief Recorrido en anchura del grafo desde un vertice, recorre todas las aristas de manera recursiva
 * @param vertice Nombre del vertice desde el cual se inicia el recorrido
 * @param visitadas Lista de los nombres de las aristas visitadas
 * @param visitadosVertices Lista de los nombres de los vertices visitados
 */
void grafo::recorridoAnchura(std::string vertice, std::list<std::string>& visitadas, std::list<std::string>& visitadosVertices) {
    // Se busca el vertice con el direccion de vertice1
    verticeGrafo *vertice1 = this->buscarVertice(vertice);
    // Se agrega el vertice a la lista de visitados
    visitadosVertices.push_back(vertice1->getNombre());
    // Ordena la lista de aristas del vertice
    std::list<verticeGrafo::aristaGrafo> aristasOrdenadas = vertice1->ordenarAristas();

    // Recorre la lista de aristas del vertice
    for (auto it = aristasOrdenadas.begin(); it != aristasOrdenadas.end(); it++) {
        // Se busca el vertice con el direccion de vertice2
        verticeGrafo *vertice2 = this->buscarVertice(it->destino->getNombre());
        // Se busca si ya se visito la arista
        if (std::find(visitadas.begin(), visitadas.end(), it->nombre) == visitadas.end()) {
            // Se agrega la arista a la lista de visitadas
            visitadas.push_back(it->nombre);
            // Se llama recursivamente al metodo
            this->recorridoAnchura(vertice2->getNombre(), visitadas, visitadosVertices);
        }
    }
}

/**
 * @brief Imprime el recorrido en anchura del grafo desde un vertice
 * @param vertice Nombre del vertice desde el cual se inicia el recorrido
 * @param visitadosVertices Lista de los nombres de los vertices visitados
 */
void grafo::imprimirRecorridoAnchura(std::string vertice, std::list<std::string>& visitadosVertices) {
    // Se crea una lista de visitadas
    std::list<std::string> visitadas;
    // Se llama al metodo recursivo
    this->recorridoAnchura(vertice, visitadas, visitadosVertices);
}





