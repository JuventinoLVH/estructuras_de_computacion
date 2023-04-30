/*
Nombre: main.cpp
Autor:  Los punteros a NULL
Fecha:  19/05/2021
Descripción:  Programa que pone a prueba los metodos de la clase ArbolB
*/

#include <iostream>
#include <cstdlib>
#include "Vector.h"
#include "CapturaSegura.h"
#include "Cliente.h"
using namespace std;

enum OPCIONES_PRINCIPALES {INT = 1, STRING, VECTOR};

int main()
{

    try{
        int opcion;
        do{
            cout << "Bienvenid@ a nuestro programa de pruebas, a continuaci\242n se presenta un cliente para probar " << endl <<
                 "los metodos de la clase Arbol*." << endl << endl;

            cout << "\nOpciones disponibles:" << endl;
            cout << "0)-------------------------Salir." << endl;
            cout << "1)-------------------------Probar con un \240rbol de enteros." << endl;
            cout << "2)-------------------------Probar con un \240rbol de strings." << endl;
            cout << "3)-------------------------Probar con un \240rbol de vectores." << endl;
            do{
                CapturaSegura(opcion,"\250Qu\202 opci\242n le gustaria realizar?: ");
            }while(opcion < 0 || opcion > 4);

            switch(opcion){
                case INT:{
                    cout << "\nUsted ha elegido probar con enteros." << endl;
                    system("pause");
                    Cliente<int> pruebasInt;
                    pruebasInt.Ejecutar();
                    break;
                }
                case STRING:{
                    cout << "\nUsted ha elegido probar con strings." << endl;
                    system("pause");
                    Cliente<string> pruebasString;
                    pruebasString.Ejecutar();
                    break;
                }
                case VECTOR:{
                    cout << "\nUsted ha elegido probar con Vectores." << endl;
                    system("pause");
                    Cliente<Vector> pruebasVector;
                    pruebasVector.Ejecutar();
                    break;
                }
            }
            system("pause");
            system("cls");
        }while(opcion != SALIR);


        cout << "Gracias por utilizar nuestro programa, disfruta tu d\241a " << char(2) << endl;

    }catch(std::exception &exc){
        cerr << "Error: " << exc.what() << endl;
    }catch(...){
        cerr << "Ha ocurrido un error inesperado en el flujo del programa... " << endl;
    }
    return 0;
}
