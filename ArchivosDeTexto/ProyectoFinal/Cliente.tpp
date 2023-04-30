/*
Nombre:         Cliente.tpp
Autor(es):      Aguilar H, Escobar R, Velazquez L y Villalba J.
Fecha:          19/05/21
Descripción:    Archivo que contiene la implementación de la clase Cliente, que permite probar
                los metodos de la clase ArbolB*.
*/
#include "Cliente.h"
#include "CapturaSegura.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

//-------------------------------------------------------------------------------
template <typename T, unsigned grado>
Cliente<T,grado>::Cliente(){}
//-------------------------------------------------------------------------------
template <typename T, unsigned grado>
void Cliente<T,grado>::Ejecutar()
{
    system("cls");
    cout << "A conuaci\242n se realizar\240 la captura de los elementos iniciales del \240rbol." << endl;
    pruebas.CapturarXArchivo("entrada.txt");
    system("cls");
    int opcion;
    do{
        cout << "\265rbol (n = " << grado << " ): \n\n" << pruebas;
        cout << "Opciones disponibles:" << endl;
        cout << "(0)-------------------------Volver al men\243 principal." << endl;
        cout << "(1)-------------------------Agregar." << endl;
        cout << "(2)-------------------------Eliminar." << endl;
        cout << "(3)-------------------------Vaciar." << endl;
        cout << "(4)-------------------------Buscar." << endl;
        cout << "(5)-------------------------Obtener n\243mero de claves." << endl;
        cout << "(6)-------------------------Copiar." << endl;
        cout << "(7)-------------------------Imprimir." << endl;

        do{
            CapturaSegura(opcion, "\250Qu\202 opci\242n le gustaria realizar?: ");
        }while(opcion < 0 || opcion > 7);

        switch(opcion){
            case SALIR:
                return;
            case AGREGAR:
                GestionAgregarElemento();
                break;
            case ELIMINAR:
                GestionEliminarElemento();
                break;
            case VACIAR:
                if(pruebas.Vaciar()) cout << "\n\nEl \240rbol ha sido vaciado con exito.";
                else cout << "\n\nEl \240rbol no contiene elementos...";
                break;
            case BUSCAR:
                GestionBuscar();
                break;
            case OBT_CLAVES:
                cout << "\n\nEl \240rbol contiene " << pruebas.NumeroDeElementos() << " clave(s)." << endl;
                break;
            case COPIAR:{
                ArbolBA<T,grado> copia = pruebas;
                cout << "\nUsted ha elegido crear una copia de un \240rbol." << endl << endl;
                cout << "Copia: " << endl << copia;
            }
                break;
            case IMPRIMIR:
                GestionImprimir();
                break;
        }
        cout << endl << endl;
        system("pause");
        system("cls");
    }while(opcion != SALIR);
}
//-------------------------------------------------------------------------------
template <typename T, unsigned grado>
void Cliente<T,grado>::GestionAgregarElemento()
{
    cout << "\nUsted ha elegido agregar un elemento al \240rbol." << endl << endl;
    T id;
    CapturaSegura(id, "\nClave a agregar: ");
    pruebas.Agregar(id);
    cout << "\nEl elemento ha sido agregado." << endl;

}
//-------------------------------------------------------------------------------
template <typename T, unsigned grado>
void Cliente<T,grado>::GestionEliminarElemento()
{
    cout << "\nUsted ha elegido eliminar un elemento a la \240rbol." << endl;
    if(pruebas.NumeroDeElementos() == 0){
        cout << "\nEl \240rbol no contiene elementos para eliminar." << endl;
        return;
    }

    T id;
    CapturaSegura(id, "\nElemento a eliminar:");
    if (pruebas.Eliminar(id)) cout << "\nEl elemento ha sido eliminado." << endl;
    else cout << "\nEl elemento no ha podido ser eliminado, intente ingresar un elemento que se encuentre en el \240rbol." << endl;
}
//-------------------------------------------------------------------------------
template <typename T, unsigned grado>
void Cliente<T,grado>::GestionBuscar() const
{
    cout << "\nUsted ha elegido buscar un elemento del \240rbol." << endl;
    if(pruebas.NumeroDeElementos() == 0){
        cout << "\nEl \240rbol no contiene elementos para buscar." << endl;
        return;
    }
    T id;
    CapturaSegura(id, "\nElemento a buscar: ");
    if(pruebas.Buscar(id)) cout << "\n\nEl elemento " << id << " se encuentra en el \240rbol." << endl;
    else cout << "\n\nEl elemento " << id << " no se encuentra en el \240rbol." << endl;
}
//-------------------------------------------------------------------------------
template <typename T, unsigned grado>
void Cliente<T,grado>::GestionImprimir() const
{
    cout << "\nUsted ha elegido imprimir los elementos del \240rbol." << endl;
    if(pruebas.NumeroDeElementos() == 0){
        cout << "\nEl \240rbol no contiene elementos para imprimir." << endl;
        return;
    }
    int opcion;
    cout << "\nOpciones:" << endl;
    cout << "(0)-------------------------Cancelar." << endl;
    cout << "(1)-------------------------Imprimir de forma ascendente." << endl;
    cout << "(2)-------------------------Imprimir de forma descendente." << endl;
    do{
        CapturaSegura(opcion, "\250Qu\202 opci\242n le gustaria realizar?: ");
    }while(opcion < 0 || opcion > 3);

    cout << endl;
    switch(opcion){
        case SALIR:
            return;
        case 1:
            pruebas.Imprimir(ASCENDENTE);
            break;
        case 2:
            pruebas.Imprimir(DESCENDENTE);
            break;
    }
    cout << endl << endl;

}
//-------------------------------------------------------------------------------
