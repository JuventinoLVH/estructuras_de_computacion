/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 24/03/21
   Descripción: Segundo examen parcial
*/

#include<limits>
#include<windows.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"Grafo.h"

using namespace std;

 /***************************************************************************************
 ********************************  Funciónes aux  ***************************************
 ***************************************************************************************/
//*************************************************************************************
/** \brief Función que captura una grafica por archivo(del archivo "entrada.txt")
 * \param grf el grafo a capturar
 */
void CapturarGrafica(Grafo<char> & grf);


 /***************************************************************************************
 *****************************************  Main  ***************************************
 ***************************************************************************************/
//*************************************************************************************
int main()
{
    cout<<"Buenas tardes, en este programa se calcular\240 un paseo de euler usando el algoritmo de Fleury";
    cout<<"\n\255Incluso puede calcular m\240s de un camino!\n";

    char op;
    Grafo<char> grf;
    CapturarGrafica(grf);
    Pila<char> camino;

    do
    {
        cout<<"Grafica a calcular el camino:";
        cout<<grf;
        cout<<'\n';
        try{
            camino=grf.PaseoDeEuler();
            cout<<"Inicio: ";
            while(!camino.EstaVacia())
            {
                cout<<camino.ConocerElemento()<<"-> ";
                camino.Desapilar();
            }
            cout<<"\b\b\b   \n";
        }
        catch(exception & e)
        {
            cout<<e.what();
            return -1;
        }
        cout<<"\250Qui\202res otro camino(Puede no haber otro camino)? (1 = Si, 0 = No)";
        cin>>op;
        system("cls");
    }while(op != '0');
    cout<<"Avoir";
    return 0;
}


 /***************************************************************************************
 ********************************  Implementación  **************************************
 ***************************************************************************************/
//*************************************************************************************
void CapturarGrafica(Grafo<char> & grf)
{
    ifstream archivo("entrada.txt");
    char linea[10];

    if(!archivo )
    {
        cout<<"Nn sea mala, no me cambie el archivo :(";
        archivo.close();
        return ;
    }

    while(!archivo.eof())
    {
        archivo.getline(linea,10);
        if(linea[0] == '!') break;
        grf.Agregar(linea[0]);
    }
    while(!archivo.eof())
    {
        archivo.getline(linea,10);
        if(linea[0] == '!') break;
        grf.Agregar(linea[0],linea[2]);
    }
}
