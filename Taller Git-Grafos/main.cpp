#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Grafo.cxx"

int main()
{


    Grafo grafo;
    int opcion;
    int vertice1;
    int vertice2;
    int peso;
    char nombreVertice[100];
    bool salir = false;
    while (!salir)
    {
        std::cout << "1. Insertar vertice" << std::endl;
        std::cout << "2. Insertar arista" << std::endl;
        std::cout << "3. Eliminar vertice" << std::endl;
        std::cout << "4. Eliminar arista" << std::endl;
        std::cout << "5. Buscar vertice" << std::endl;
        std::cout << "6. Buscar arista" << std::endl;
        std::cout << "7. Salir mostrando con la cantidad de vertices y la cantidad de aristas" << std::endl;
        std::cin >> opcion;
        switch (opcion)
        {
        case 1:
            std::cout << "Ingrese el nombre del vertice: " << std::endl;
            std::cin >> nombreVertice;
            grafo.insertarVertice(nombreVertice);
            break;
        case 2:
            std::cout << "Ingrese el vertice 1: " << std::endl;
            std::cin >> vertice1;
            std::cout << "Ingrese el vertice 2: " << std::endl;
            std::cin >> vertice2;
            std::cout << "Ingrese el peso de la arista: " << std::endl;
            std::cin >> peso;
            grafo.insertarArista(vertice1, vertice2, peso);
            break;
        case 3:
            std::cout << "Ingrese el vertice a eliminar: " << std::endl;
            std::cin >> vertice1;
            grafo.eliminarVertice(vertice1);
            break;
        case 4:
            std::cout << "Ingrese el vertice 1: " << std::endl;
            std::cin >> vertice1;
            std::cout << "Ingrese el vertice 2: " << std::endl;
            std::cin >> vertice2;
            grafo.eliminarArista(vertice1, vertice2);
            break;
        case 5:
            std::cout << "Ingrese el vertice a buscar: " << std::endl;
            std::cin >> nombreVertice;
            std::cout << "El vertice " << nombreVertice << " esta en el vertice " << grafo.buscarVertices(nombreVertice) << std::endl;
            break;

        case 6:
            std::cout << "Ingrese el vertice 1: " << std::endl;
            std::cin >> vertice1;
            std::cout << "Ingrese el vertice 2: " << std::endl;
            std::cin >> vertice2;
            std::cout << "La arista " << vertice1 << " " << vertice2 << " tiene un peso de " << grafo.buscarArista(vertice1, vertice2) << std::endl;
            break;
        case 7:
            salir = true;
            break;
        
        }
    }
        std::ifstream archivo("Grafo.txt");
    std::string linea;
    std::vector<std::string> vertices;
    std::vector<std::string> aristas;
    std::vector<std::string> pesos;
    std::vector<std::string>::iterator it;

    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            if (linea.find("c") != std::string::npos)
            {
                std::string vertice = linea.substr(linea.find(" ") + 3) + " ";
                vertices.push_back(vertice);
            }
            else if (linea.find(" ") != std::string::npos)
            {
                std::string arista = linea.substr(linea.find(" ") + 0) + " ";
                aristas.push_back(arista);
            }
        }
        archivo.close();
    }
    else
    {
        std::cout << "No se pudo abrir el archivo" << std::endl;
    }

    std::cout << "Vertices: " << std::endl;
    for (it = vertices.begin(); it != vertices.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "Aristas: " << std::endl;
    for (it = aristas.begin(); it != aristas.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    
    return 0;
}

