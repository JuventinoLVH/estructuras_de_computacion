/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 14/04/21
   Descripción: Cliente para probara la clase ArbolDeBVL
*/

#include<limits>
#include<windows.h>
#include<iostream>
#include"Vector.h"
#include"ArbolDeBVL.h"

using namespace std;

 /***************************************************************************************
 ********************************  Funciónes aux  ***************************************
 ***************************************************************************************/
//*************************************************************************************
/** \brief Gestiona la mayoría de las operaciones
 *
 * \param abb El ArbolDeBVL en la que se realizará la operación
 * \param op La operación a efectuar
 * \return si La operación se realizo exitosamente
 *
 */
template<typename T>
bool RealizarOp(ArbolDeBVL<T> & abb, char op);

//*************************************************************************************
/** \brief Imprime el menu
 */
void ImprMenu();

//*************************************************************************************
/** \brief Lee una opción y regresa un carácter dentro del rango válido
 *
 * \param mensaje El mensaje para pedir la opción
 * \param opciones Una cadena donde cada carácter representa una opción valida
 * \return Una opción válida
 *
 */
char LeerOpcion(const char * mensaje,const char *opciones  );


 /***************************************************************************************
 *****************************************  Main  ***************************************
 ***************************************************************************************/
//*************************************************************************************
int main()
{
    cout<<"Buenos dias.A continuaci\242n se mostrara la potestad de la clase ArbolDeBVL, para ello tendra "<<
            "a su dispoci\242n 3 tipos de arboles:\nuno de enteros, de caracteres y otro de vectores.\n";

    ArbolDeBVL<int> abbI,a;
    ArbolDeBVL<char> abbC;
    ArbolDeBVL<Vector> abbV;
    bool exito;
    char tList,op;

    tList = LeerOpcion("Tipo de lista inicial: int(i), char(c), vector(v): ","ivc");
    do
    {
        cout<<"Recuerde, el tipo de la lista es: ("<<tList<<")";
        ImprMenu();
        op=LeerOpcion("Opci\242n: ","012345678c");

        if(op == '0' || op=='c' )
        {
            exito=true;
            if(op=='c')
                tList = LeerOpcion("Tipo de lista inicial: int(i), char(c), vector(v): ","ivc");
        }
        else
        {
            switch (tList)
            {
                case 'i':
                    exito=RealizarOp(abbI,op);
                    break;
                case 'v':
                    exito=RealizarOp(abbV,op);
                    break;
                case 'c':
                    exito=RealizarOp(abbC,op);
                    break;
            }
        }
        if(op != '0')
        {
            if(exito)
                cout<<"\nexito en la operaci\242n\n";
            else
                cout<<"la operaci\242n no altero la grafica...\nTal vez se agreg\242 un elemento repetido, se "<<
                        "elimino un elemento no existente o se vacio algo que ya estaba vac\241o...\n";
        }
        system("pause");
        system("cls");
    }while(op != '0');
    a=abbI;
    cout<<abbI<<'\n';
    cout<<a<<'\n';
    return 0;
}


 /***************************************************************************************
 ********************************  Implementación  **************************************
 ***************************************************************************************/
//*************************************************************************************
char LeerOpcion(const char * mensaje , const char *opciones )
{
    bool opValida=false;
    char op;

    do
    {
        cout<<mensaje;
        cin>>op;

        for(int i=0; opciones[i]!= 0;++i)
        {
            if(op == opciones[i])
            {
                opValida=true;
                break;
            }
        }

        if(!opValida)
            cout<<"Opci\242n no v\240lida...\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');

    }while(!opValida);


    return op;
}


//*************************************************************************************
template<typename T>
bool RealizarOp(ArbolDeBVL<T> & abb, char op)
{
    char op2;
    T aux;
    try
    {
        switch(op)
        {
            case '1': //Agregar
                cout<<"Nodo a agregar: ";
                cin>>aux;
                return abb.Agregar(aux);
                break;

            case '2': //Eliminar
                cout<<"Nodo a eliminar: ";
                cin>>aux;
                return abb.Eliminar(aux);
                break;

            case '3': //Buscar
                cout<<"Nodo a buscar: ";
                cin>>aux;
                cout<<"El nodo "<<(abb.Buscar(aux)? "SI" : "NO" )<<" se encuentra";
                break;

            case '4': //Número de nodos
                cout<<"El arbol tiene : "<<abb.NumeroDeNodos()<<" nodos";
                break;

            case '5': // Altura
                cout<<"La grafica tiene altura : "<<abb.ObtenerAltura();
                break;

            case '6': //Podar Nodo
                cout<<"Nodo a podar: ";
                cin>>aux;
                return abb.PodarNodo(aux);
                break;

            case '7': // Vaciar
                op2=LeerOpcion("\250Seguro que dese\240 borrar el arbol?: Si(S),No(N): ","SNsn");
                if(op2 == 'S' || op2=='s')  return abb.Vaciar();
                else return false;
                break;

            case '8': // Imprimir
                op2=LeerOpcion("Criterio para imprimir: Ascendente(A), Descendente(D), PorNivel(N), PreOrden(P), PosOrden(O) ",
                        "ADNPO");
                switch(op2)
                {
                    case 'A':
                        abb.Imprimir(ASCENDENTE);
                        break;
                    case 'D':
                        abb.Imprimir(DESCENDENTE);
                        break;
                    case 'N':
                        abb.Imprimir(PORNIVEL);
                        break;
                    case 'P':
                        abb.Imprimir(PREORDEN);
                        break;
                    case 'O':
                        abb.Imprimir(POSORDEN);
                        break;
                }
                break;
        }
    }
    catch(exception & e)
    {
        cout<<"Algo fuera de mis limites acaba de pasar, posiblemente error "<<
                "al asignar la memoria: "<<e.what()<<endl;
        return false;
    }
    return true;
}


//*************************************************************************************
void ImprMenu()
{
    cout<<"\nMenu:\n";
    cout<<"Agregar elemento: 1\n";
    cout<<"Eliminar elemento: 2\n";
    cout<<"Buscar elemento : 3\n";
    cout<<"Obtener n\243mero de nodos : 4\n";
    cout<<"Buscar altura : 5\n";
    cout<<"Podar nodo: 6\n";
    cout<<"Vaciar arbol: 7\n";
    cout<<"Imprimir arbol : 8\n";
    cout<<"Cambiar tipo de lista: c\n";
    cout<<"Salir: 0\n";
}
