/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#include<iostream>
#include<cstdlib>
#include"Pila.h"

using namespace std;

int main()
{

    Pila<bool,10> primerapila;

    try
    {
        for(int i=0;i<=11;++i)
        {
            primerapila.AgregarElemento(double(i) );
            cout<<'\n';
            primerapila.Imprimir();
        }
    }
    catch(exception & ex)
    {
        cout<<ex.what();
    }
    return 0;
}
