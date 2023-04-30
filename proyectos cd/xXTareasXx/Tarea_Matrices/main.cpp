/* Nombre:main.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 5/2/21 (A ultima hora)
   Descripción: Archivo de prueba para la implementacion de Matriz.h
*/
#include"Matriz.h"
#include <iostream>

using namespace std;

int main()
{
    cout<<"A continuaci\242n se mostrar\240 todo lo que la clase Matriz puede hacer, Usted solo teclear\240"<<
            "una matriz de 3x2 y otra de 3x2";

    try
    {
        Matriz m1(3,2);
        Matriz m2(2,3);
        cout<<"Matriz 3x2:\n";
        cin>>m1;
        cout<<"Matriz 2x3:\n";
        cin>>m2;

        cout<<m1<<'\n'<<m2<<'\n';

        Matriz m3(0);
        m3 =(2,2);
        cout<<m3<<'\n';

        cout<<(2*(m1*m2)) + (m1*m2)<<'\n';
        cout<<(m1*m2) - ((m1*m2)*2)<<'\n';
        try
        {
            cout<<(m1*m2).Inversa();
        }
        catch(logic_error & e)
        {
            cout<<e.what()<<'\n';
            cout<<"Lastima, el producto de las dos matricez no es inversible :(, pero juro que si sirve"<<'\n';
        }

        cout<<m2.CambiarDimension(m1[0][0],1)<<'\n';
        cout<< (m3-m2).Tranpuesta()<<'\n';
        cout<<m3<<'\n';
        cout<<m1.CambiarDimension(3,3)<<'\n';
        cout<<m2.CambiarDimension(3,3)<<'\n';
        cout<<m2<<'\n';
        cout<<m1<<'\n';

    }
    catch(out_of_range & e)
    {
        cout<<e.what();
    }
    catch(logic_error & e)
    {
        cout<<e.what();
    }
    catch(bad_alloc & e)
    {
        cout<<e.what();
    }
    return 0;
}
