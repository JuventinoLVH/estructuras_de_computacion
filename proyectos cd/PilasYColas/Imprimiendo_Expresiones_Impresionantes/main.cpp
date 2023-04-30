/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 28/Feb/2020
   Descripción: Archivo de prueba para la clase Expresión
*/


#include "Expresion.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    cout<<"\t\tBienveido al poderoso \"Evaluador de expresi\242nes aritm\202ticas\"\n\n";

    bool seguirEvaluando;
    int op;
    Expresion exp;
    do
    {
        cout<<"Expresi\242n a evaluar: ";
        cin>>exp;
        if(exp.EsValida())
        {
            try
            {
                cout<<"El valor de la expresi\242n : "<<exp<<"  es: "<<exp.Evaluar()<<'\n';
            }
            catch(logic_error e)
            {
                cout<<e.what();
            }
        }
        else
            cout<<"La expresi\242n: "<<exp<<" no est\240 bien escrita...\n";

        do
        {
            cout<<"Quieres seguir evaluando? (0 no, 1 si): ";
            cin>>op;
            if(op != 0 && op != 1)
                cout<<"Opci\243n invalida...\n";
        }
        while(op != 0 && op != 1);
        seguirEvaluando= op==1;

    }while(seguirEvaluando);

    system("pause");
    return 0;
}
