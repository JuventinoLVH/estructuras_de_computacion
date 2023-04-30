/*
Nombre:         CapturaSegura.tpp
Autor(es):      Aguilar H, Escobar R, Velazquez L y Villalba J.
Fecha:          19/05/21
Descripción:    Archivo que contiene la función plantilla para caturar un dato.
*/

#include <iostream>
#include <cstdlib>
#include <limits>
#include <stdexcept>
//Función encargada de la captura segura de un dato.
template <typename T1>
void CapturaSegura(T1 &a, const char mensaje[] /* = ""*/)
{
    while(true){
        std::cout << mensaje;
        std::cin >> a;
        if(std::cin.bad()){
            std::cout << "Ocurri\242 un error irrecuperable en el flujo del programa.";
            throw std::runtime_error("Ocurri\242 un error irrecuperable en el flujo del programa.");
        }
        if(std::cin.fail()){
            std::cout << "Error, el tipo de dato ingresado no es un n\243mero, ingrese un dato valido..." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        return;
    }
}
