/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/
#include"Matriz.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        Matriz mat(3,2);
        Matriz mat2(2,3);
        cin>>mat>>mat2;
        cout<<mat*mat2;
    }
    catch(...)
    {
        cout<<"Algo malo paso";
    }
    return 0;
}
