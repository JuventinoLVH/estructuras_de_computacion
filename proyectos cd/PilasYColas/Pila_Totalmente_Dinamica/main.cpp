/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 21/02/21
   Descripción: Archivo donde se prueba la clase "pila"
*/

#include <iostream>

#include"Pila.h"

using namespace std;

int main()
{
    try
    {

        cout<<"A continuaci\243n se mostrara el poderio de la clase pila"<<'\n';

        Pila<int> pila1,pila3;
        Pila<bool> pila2;
        Pila < Pila<> > pilaDePilas;
        int n;

        cout<<"Se capturar\240 una cantidad indefinida de n\243meros enteros(hasta que el usuario tecle\202 '-1')"<<
                "y se guardar\240n en 'pila1'"<<'\n';
        do
        {
            cout<<"Elemento "<<pila1.Tamano()+1<<" : ";
            cin>>n;
            if(n!=-1)
                pila1.Apilar(n);

        }while(n != -1);


        cout<<'\n';
        cout<<"Se capturar\240 una cantidad indefinida de valores boleanos enteros(hasta que el usuario tecle\202 un "<<
                "n\243mero diferente a '0' o '1') y se guardar\240n en 'pila2'"<<'\n';
        do
        {
            cout<<"Elemento "<<pila2.Tamano()+1<<" : ";
            cin>>n;
            if(n==0 || n== 1)
                pila2.Apilar(n);

        }while(n == 0 || n== 1);

        cout<<'\n';
        cout<<pila1<<'\n';
        cout<<pila2<<'\n';
        cout<<'\n';

        cout<<"Copia de la primera pila: "<<'\n';
        pila3=pila1;
        cout<<pila3<<'\n';
        cout<<'\n';

        cout<<"Se eliminar\240 el primer elemento de pila1 y se imprimir\240 pila1 y su copia\n";
        pila1.Desapilar();
        cout<<pila1<<'\n';
        cout<<pila3<<'\n';

        cout<<"Se guardar\240 la pila 1 y su copia en una pila de pilas..."<<'\n';
        pilaDePilas.Apilar(pila1);
        pilaDePilas.Apilar(pila3);
        cout<<'\n';

        cout<<"Elemento al tope de cada pila: "<<'\n';
        cout<<pila1.ConocerElemento()<<'\n';
        cout<<pila2.ConocerElemento()<<'\n';
        cout<<pila3.ConocerElemento()<<'\n';
        cout<<pilaDePilas.ConocerElemento()<<'\n';
        cout<<'\n';

        cout<<"Se vaciara pila1 y eliminar\240 el primer elemento de cada pila( excepto de la pila de pilas) y se imprimir\240n\n";
        pila1.Vaciar();
        pila2.Desapilar();
        pila3.Desapilar();

        try
        {
            cout<<"Tope de pila2: "<<pila2.ConocerElemento()<<'\n';
            cout<<"Tope de la copia de pila1: "<<pila3.ConocerElemento()<<'\n';
            cout<<"Tope de pila1: "<<pila1.ConocerElemento()<<'\n';
        }
        catch(exception & e)
        {
            cout<<e.what()<<'\n';
        }
        cout<<'\n';

        cout<<"Se imprimir\240n las pilas, su n\243mero de elementos y su capacidad "<<'\n';
        cout<<pila1<<"  "<<pila1.Tamano()<<"  "<<'\n';
        cout<<pila2<<"  "<<pila2.Tamano()<<"  "<<'\n';
        cout<<pila3<<"  "<<pila3.Tamano()<<"  "<<'\n';
        cout<<pilaDePilas<<"  "<<pilaDePilas.Tamano()<<"  "<<'\n';

    }
    catch(std::bad_alloc & e)
    {
        cout<<"No hay memoria... "<<e.what();
    }
    catch(exception & e)
    {
        cout<<"Problema inesperado..."<<e.what();
    }

    return 0;
}
