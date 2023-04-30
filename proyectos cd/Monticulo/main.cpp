/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 25/04/21
   Descripción: Cliente para probara la clase Heap
*/

#include<limits>
#include<windows.h>
#include<iostream>
#include"Vector.h"
#include"Heap.h"

using namespace std;

 /***************************************************************************************
 ********************************  Funciónes aux  ***************************************
 ***************************************************************************************/
//*************************************************************************************
/** \brief Gestiona la mayoría de las operaciones
 *
 * \param hp El Heap en la que se realizará la operación
 * \param op La operación a efectuar
 * \return si La operación se realizo exitosamente
 *
 */
template<typename T , bool (*criterio)(const T &a, const T &b)>
bool RealizarOp(Heap<T,criterio> & hp, char op);

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
    cout<<"Buenos dias.A continuaci\242n se mostrara la majestad de la clase Heap, para ello tendra "<<
            "a su dispoci\242n 3 tipos de arboles:\nuno de enteros, de caracteres y otro de vectores.\n";
    cout<<"Para hacerlo m\240s interecante, el heap de enteros ser\240 m\240ximo y el de caracteres "<<
            "ser\240 m\241nimo\n";
    Heap<int,maximo> hpI;
    Heap<char,minimo> hpC;
    Heap<Vector,minimo> hpV;
    bool exito;
    char tList,op;

    tList = LeerOpcion("Tipo de heap inicial: int(i), char(c), vector(v): ","ivc");
    do
    {
        cout<<"Recuerde, el tipo del heap es: ("<<tList<<")";
        ImprMenu();
        op=LeerOpcion("Opci\242n: ","012345678c");

        if(op == '0' || op=='c' )
        {
            exito=true;
            if(op=='c')
                tList = LeerOpcion("Tipo de heap: int(i), char(c), vector(v): ","ivc");
        }
        else
        {
            switch (tList)
            {
                case 'i':
                    exito=RealizarOp(hpI,op);
                    break;
                case 'v':
                    exito=RealizarOp(hpV,op);
                    break;
                case 'c':
                    exito=RealizarOp(hpC,op);
                    break;
            }
        }
        if(op != '0')
        {
            if(exito)
                cout<<"\nexito en la operaci\242n\n";
            else
                cout<<"la operaci\242n no altero el heap...\nTal vez ya no hay memoria, se "<<
                        "elimino un elemento no existente o se vacio algo que ya estaba vac\241o...\n";
        }
        system("pause");
        system("cls");
    }while(op != '0');

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
template<typename T , bool (*criterio)(const T &a, const T &b)>
bool RealizarOp(Heap<T,criterio> & hp, char op)
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
                return hp.Agregar(aux);
                break;

            case '2': //Eliminar
                return hp.Eliminar();
                break;

            case '3': //Obt Elemento
                if(hp.EstaVacio()) return false;
                cout<<"El elemento al frente es: "<<hp.ObtenerFrente()<<" ...";
                break;

            case '4': //Esta vacio
                if(hp.EstaVacio()) cout<<"El heap SI est\240 vacio";
                else cout<<"El heap NO est\240 vacio";
                break;

            case '5': // Vaciar
                op2=LeerOpcion("\250Seguro que dese\240 borrar el heap?: Si(S),No(N): ","SNsn");
                if(op2 == 'S' || op2=='s')  return hp.Vaciar();
                else return false;
                break;

            case '6': //Número nodos
                cout<<"El heap tiene : "<<hp.NumeroDeNodos()<<" nodos";
                break;

            case '7': // Imprimir
                cout<<"Heap: "<<hp;
                break;

            case '8': // Imprimir
                cout<<"La capacidad es "<<hp.ObtenerCap();
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
    cout<<"Obtener elemento al frente: 3\n";
    cout<<"Esta vacio: 4\n";
    cout<<"Vaciar arbol: 5\n";
    cout<<"Obtener n\243mero de nodos: 6\n";
    cout<<"Imprimir arbol : 7\n";
    cout<<"Obtener capacidad : 8\n";
    cout<<"Cambiar tipo de lista: c\n";
    cout<<"Salir: 0\n";
}
