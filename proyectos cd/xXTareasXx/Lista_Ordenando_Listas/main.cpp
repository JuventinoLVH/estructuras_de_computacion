/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 20/03/21
   Descripción: Cliente para probara la clase ListaOrdenada
*/

#include<limits>
#include<windows.h>
#include<iostream>
#include<iostream>
#include"ListaOrdenada.h"
#include"Vector.h" //Hoy no hay "ListaSimple<ListaSimple<> >", estoy triste :(

using namespace std;

 /***************************************************************************************
 ********************************  Funciónes aux  ***************************************
 ***************************************************************************************/
//*************************************************************************************
/** \brief Función que captura de forma segura un número entero
 *
 * \param solicitud Mensaje de solicitud para la captura
 * \return Entero capturado
 */
int CapturaEntero(const char solicitud []);

//*************************************************************************************
/** \brief Gestiona la mayoría de las operaciones
 *
 * \param ls la lista en la que se realizará la operación
 * \param op la operación a efectuar
 * \param mLs la "memoria" de la lista
 * \return si la operación se realizo exitosamente
 *
 */
template<typename T>
bool RealizarOp(ListaOrdenada<T> & ls, char op, ListaOrdenada<T> & mLs);

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
    cout<<"Buenos dias.A continuaci\242n se mostrara el poder de la clase ListaSimple, para ello tendra "<<
            "a su dispoci\242n 3 tipos de lista:\nuna de enteros, otra de caracteres y otra de matrices. "<<
                "Tambi\202n podras guardar tu lista en otra lista a modo de memoria  \n";

    ListaOrdenada<int> listaI;
    ListaOrdenada<Vector > listaV;
    ListaOrdenada<char> listaC;
    ListaOrdenada<int> listaIM;
    ListaOrdenada<Vector > listaVM;
    ListaOrdenada<char> listaCM;
    bool exito;
    char tList;
    char op;
    tList = LeerOpcion("Tipo de lista inicial: int(i), char(c), vector(v)\n","ivc");

    do
    {
        cout<<"Recuerde, el tipo de la lista es: ("<<tList<<")";
        ImprMenu();
        op=LeerOpcion("Opci\242n: ","0123456789opmgcli");

        if(op == '0' || op=='9' )
        {
            exito=true;
            if(op=='9')
                tList=LeerOpcion("Tipo de lista: int(i), char(c), vector(v)\n","ivc");
        }
        else
        {
            switch (tList)
            {
                case 'i':
                    exito=RealizarOp(listaI,op,listaIM);
                    break;
                case 'v':
                    exito=RealizarOp(listaV,op,listaVM);
                    break;
                case 'c':
                    exito=RealizarOp(listaC,op,listaCM);
                    break;
            }
        }
        if(op != '0')
        {
            if(exito)
                cout<<"\nexito en la operaci\242n\n";
            else
                cout<<"la operaci\242n no se pudo concretar...\nTal vez un error con los indices "<<
                        "o se intento borrar un elemento que no est\240\n";
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
template<typename T>
bool RealizarOp(ListaOrdenada<T> & ls , char op, ListaOrdenada<T> & mLs)
{
    try
    {
        T aux;
        switch(op)
        {
            case '1': //Agregar
                cout<<"Elemento a agregar: ";
                cin>>aux;
                ls.AgregarElemento(aux);
                break;

            case '2': //Eliminar
                cout<<"Elemento a eliminar: ";
                cin>>aux;
                return ls.EliminarElemento(aux);
                break;

            case '3': //Buscar
                cout<<"Elemento a buscar: ";
                cin>>aux;
                if(ls.Buscar(aux)) cout<<"Si est\240...\n";
                else cout<<"No est\240...\n";
                break;

            case '4': // EstaVacia
                if(ls.EstaVacia()) cout<<"Si est\240 vacia...\n";
                else cout<<"No est\240 vacia...\n";
                break;

            case '5': // Vaciar
                ls.Vaciar();
                cout<<"Ahora est\240 vacia :D\n";
                break;

            case '6': // tamaño
                cout<<"El n\243mero de elementos en la lista es: "<<
                        ls.ObtenerTamano()<<'\n';
                break;

            case '7': // imp. asc.
                cout<<"Lista ordenada de forma ascendente: \n";
                cout<<ls<<'\n';
                break;

            case '8': // imp. des.
                cout<<"Lista ordenada de forma descendente: \n";
                ls.ImprimirDescendente();
                cout<<'\n';
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
    cout<<"Buscar un elemento : 3\n";
    cout<<"Verificar si est\240 vacia: 4\n";
    cout<<"Vaciar lista: 5\n";
    cout<<"Tama\244o de la lista : 6\n";
    cout<<"Imprimir lista de forma ascendente: 7\n";
    cout<<"Imprimir lista de forma ascendente: 8\n";
    cout<<"Cambiar tipo de lista: 9\n";
    cout<<"Salir: 0\n";
}


//*************************************************************************************
int CapturaEntero(const char solicitud [])
{
    int n;
    while(true){
        std::cout << solicitud;
        std::cin >> n;

        if(std::cin.bad()){
            std::cout << "Ocurri\242 un error irrecuperable en el flujo de entrada\n";
            system("pause");
            exit(1);
        }
        if(std::cin.fail()){
            std::cout << "Error: no es un n\243mero. Introduzca de nuevo...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        return n;
    }
}
