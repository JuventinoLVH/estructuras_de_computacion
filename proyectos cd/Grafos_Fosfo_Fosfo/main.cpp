/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 24/03/21
   Descripci�n: Cliente para probara la clase Grafo
*/

#include<limits>
#include<windows.h>
#include<iostream>
#include"Vector.h"
#include"Grafo.h"

using namespace std;

 /***************************************************************************************
 ********************************  Funci�nes aux  ***************************************
 ***************************************************************************************/
//*************************************************************************************
/** \brief Funci�n que captura de forma segura un n�mero entero
 *
 * \param solicitud Mensaje de solicitud para la captura
 * \return Entero capturado
 */
int CapturaEntero(const char solicitud []);

//*************************************************************************************
/** \brief Gestiona la mayor�a de las operaciones
 *
 * \param grf El grafo en la que se realizar� la operaci�n
 * \param op La operaci�n a efectuar
 * \return si La operaci�n se realizo exitosamente
 *
 */
template<typename T,typename A>
bool RealizarOp(Grafo<T,A> & grf, char op,bool pesos);

//*************************************************************************************
/** \brief Imprime el menu
 */
void ImprMenu();

//*************************************************************************************
/** \brief Lee una opci�n y regresa un car�cter dentro del rango v�lido
 *
 * \param mensaje El mensaje para pedir la opci�n
 * \param opciones Una cadena donde cada car�cter representa una opci�n valida
 * \return Una opci�n v�lida
 *
 */
char LeerOpcion(const char * mensaje,const char *opciones  );


 /***************************************************************************************
 *****************************************  Main  ***************************************
 ***************************************************************************************/
//*************************************************************************************
int main()
{
    cout<<"Buenos dias.A continuaci\242n se mostrara la elegancia de la clase Grafo, para ello tendra "<<
            "a su dispoci\242n 3 tipos de grafos:\nuno de enteros, de caracteres y otro de vectores.\n";

    Grafo<int> grfI;
    Grafo<string> grfC;
    Grafo<Vector> grfV;

    bool exito,grafoConPeso;
    char tList;
    char op;
    tList = LeerOpcion("Tipo de lista inicial: int(i), string(c), vector(v): ","ivs");
    op = LeerOpcion("\250Las aristas tienen peso?: Si(S),No(N)", "snSN");
    if(op == 'S' || op == 's') grafoConPeso=true;
    else grafoConPeso=false;

    do
    {
        cout<<"Recuerde, el tipo de la lista es: ("<<tList<<")";
        ImprMenu();
        op=LeerOpcion("Opci\242n: ","0123456789c");

        if(op == '0' || op=='c' )
        {
            exito=true;
            if(op=='c')
                tList = LeerOpcion("Tipo de lista inicial: int(i), string(c), vector(v): ","ivs");
        }
        else
        {
            switch (tList)
            {
                case 'i':
                    exito=RealizarOp(grfI,op,grafoConPeso);
                    break;
                case 'v':
                    exito=RealizarOp(grfV,op,grafoConPeso);
                    break;
                case 'c':
                    exito=RealizarOp(grfC,op,grafoConPeso);
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
    return 0;
}


 /***************************************************************************************
 ********************************  Implementaci�n  **************************************
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
template<typename T,typename A>
bool RealizarOp(Grafo<T,A> & grf, char op,bool pesos)
{
    char op2;
    T aux,aux2;
    A aux3;
    try
    {
        switch(op)
        {
            case '1': //Agregar
                op2=LeerOpcion("Tipo de elemento a buscar: Nodo(N),Arista(A): ","ANan");
                if(op2 == 'N' || op2=='n')
                {
                    cout<<"Nodo a agregar: ";
                    cin>>aux;
                    return grf.Agregar(aux);
                }
                else
                {
                    cout<<"Nodo a uno de los extremos de la arista: ";
                    cin>>aux;
                    cout<<"Nodo al otro extremo de la arista: ";
                    cin>>aux2;
                    if(pesos)
                    {
                        cout<<"Peso de la arista: ";
                        cin>>aux3;
                        return grf.Agregar(aux,aux2,aux3);
                    }
                    else return grf.Agregar(aux,aux2);
                }
                break;

            case '2': //Eliminar
                op2=LeerOpcion("Tipo de elemento a buscar: Nodo(N),Arista(A): ","ANan");
                if(op2 == 'N' || op2=='n')
                {
                    cout<<"Nodo a eliminar: ";
                    cin>>aux;
                    return grf.Eliminar(aux);
                }
                else
                {
                    cout<<"Nodo a uno de los extremos de la arista: ";
                    cin>>aux;
                    cout<<"Nodo al otro extremo de la arista: ";
                    cin>>aux2;
                    return grf.Eliminar(aux,aux2);
                }
                break;

            case '3': //Buscar
                op2=LeerOpcion("Tipo de elemento a buscar: Nodo(N),Arista(A): ","ANan");
                if(op2 == 'N' || op2=='n')
                {
                    cout<<"Nodo a buscar: ";
                    cin>>aux;
                    cout<<"El nodo "<<(grf.Buscar(aux)? "SI" : "NO" )<<" se encuentra";
                }
                else
                {
                    cout<<"Nodo a uno de los extremos de la arista: ";
                    cin>>aux;
                    cout<<"Nodo al otro extremo de la arista: ";
                    cin>>aux2;
                    cout<<"La arista "<<(grf.Buscar(aux,aux2)? "SI" : "NO" )<<" se encuentra";
                }
                break;

            case '4': //Obtener grado
                try
                {
                    cout<<"Nodo a buscar: ";
                    cin>>aux;
                    cout<<"El grado de "<<aux<<" es: "<<grf.GradoDe(aux);
                }
                catch(exception & e)
                {
                    cout<<e.what();
                    return false;
                }
                return true;
                break;

            case '5': // Obtener n�mero de nodos
                cout<<"La grafica tiene : "<<grf.NumeroDeNodos()<<" nodos";
                break;

            case '6': //Obtener n�mero de aristas
                cout<<"La grafica tiene : "<<grf.NumeroDeAristas()<<" aristas";
                break;

            case '7': // Vaciar nodo
                cout<<"Nodo a vaciar: ";
                cin>>aux;
                return grf.VaciarNodo(aux);
                break;

            case '8': // Vaciar grafica
                op2=LeerOpcion("\250Seguro que dese\240 borrar la grafica?: Si(S),No(N): ","SNsn");
                if(op2 == 'S' || op2=='s')  return grf.VaciarGrafica();
                else return false;
                break;

            case '9': // Imprimir
                if(pesos) grf.ImprimirConPesos();
                else cout<<grf;
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
    cout<<"Obtener grado de un nodo: 4\n";
    cout<<"Obtener n\243mero de nodos : 5\n";
    cout<<"Buscar n\243mero de aristas : 6\n";
    cout<<"Vaciar nodo: 7\n";
    cout<<"Vaciar grafica: 8\n";
    cout<<"Imprimir grafica : 9\n";
    cout<<"Cambiar tipo de lista: c\n";
    cout<<"Salir: 0\n";
}
