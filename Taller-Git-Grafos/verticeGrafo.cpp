//
// Created by yeusepe on 4/29/22.
//

#include "verticeGrafo.h"



/**
 * @brief Constructor de la clase verticeGrafo
 * @param nombre Nombre del vertice
 */
verticeGrafo::verticeGrafo(std::string nombre) {
    this->nombre = nombre;
}

/**
 * @brief Busca una arista en la lista de aristas
 * @param nombre Nombre de la arista
 * @return Arista encontrada
 */
verticeGrafo::aristaGrafo *verticeGrafo::buscarArista(std::string nombre) {
    // Recorre la lista de aristas
    for (auto it = aristas.begin(); it != aristas.end(); it++) {
        // Si la arista es la buscada
        if ((*it).direccion == nombre) {
            // Retorna la arista
            std::cout << (*it).nombre << std::endl;
            return &(*it);
        }
    }
    return nullptr;
}

/**
 * @brief Agrega una arista al vertice
 * @param nombre Nombre de la arista
 * @param peso Peso de la arista
 * @param destino Puntero al vertice destino de la arista
 */
void verticeGrafo::agregarArista(std::string nombre, int peso, verticeGrafo *destino) {
    aristaGrafo arista;
    arista.direccion = nombre;
    arista.peso = peso;
    arista.destino = destino;
    arista.nombre = this->nombre + destino->nombre;
    arista.origen = this->nombre;
    aristas.push_back(arista);
}

/**
 * @brief Imprime las aristas del vertice
 */
void verticeGrafo::imprimir()
{
    std::cout << "Vertice: " << this->nombre << std::endl;
    std::cout << "Aristas: " << std::endl;
    for (auto it = aristas.begin(); it != aristas.end(); it++) {
        std::cout << "Nombre: " << it->direccion << " Peso: " << it->peso << " Destino: " << it->destino->nombre << std::endl;
    }
}

/**
 * @brief Consigue el nombre del vertice
 * @return Nombre del vertice
 */
std::string verticeGrafo::getNombre() {
    return this->nombre;
}

/**
 * @brief Establece si el vertice fue visitado
 * @param visitado Estado de visitado
 */
void verticeGrafo::setVisitado(bool visitado) {
    this->visitado = visitado;
}

/**
 * @brief Consigue el estado de visitado
 * @return Estado de visitado
 */
bool verticeGrafo::getVisitado() {
    return this->visitado;
}

/**
 * @brief Organiza la lista de aristas de menor a mayor peso
 * @return Lista de aristas ordenada
 */
std::list<verticeGrafo::aristaGrafo> verticeGrafo::ordenarAristas() {
    std::list<aristaGrafo> aristasOrdenadas; ///< Lista de aristas ordenadas

    // Copia la lista de aristas
    for (auto it = aristas.begin(); it != aristas.end(); it++) {
        aristasOrdenadas.push_back(*it);
    }

    // Ordena la lista de aristas de menor a mayor peso
    aristasOrdenadas.sort([](const aristaGrafo &a, const aristaGrafo &b) {
        return a.peso < b.peso;
    });

    return aristasOrdenadas;
}

