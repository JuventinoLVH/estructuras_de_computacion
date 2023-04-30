/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 24/03/21
   Descripción: Cliente para probara la clase ListaCircular
*/

#include<limits>
#include<windows.h>
#include<iostream>
#include"Vector.h"
#include"ListaCircular.h"

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
 * \return si la operación se realizo exitosamente
 *
 */
template<typename T>
bool RealizarOp(ListaCircular<T> & ls, char op);

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
    cout<<"Buenos dias.A continuaci\242n se mostrara la elegancia de la clase ListaCircular, para ello tendra "<<
            "a su dispoci\242n 3 tipos de lista:\nuna de enteros, de caracteres y otra de vectores. "<<
                "Recuerd\202 que en las listas circulares los elementos se \nagregan y elimimnan a "<<
                    "la derecha de los elementos (Si est\202 vaci\240 ,la acci\242n se efectua"<<
                        "en la cabeza)\n";

    ListaCircular<int> listaI;
    ListaCircular<char> listaC;
    ListaCircular<Vector > listaV;

    bool exito;
    char tList;
    char op;
    tList = LeerOpcion("Tipo de lista inicial: int(i), char(c), vector(v)\n","ivc");

    do
    {
        cout<<"Recuerde, el tipo de la lista es: ("<<tList<<")";
        ImprMenu();
        op=LeerOpcion("Opci\242n: ","0123456789iptc");

        if(op == '0' || op=='c' )
        {
            exito=true;
            if(op=='c')
                tList=LeerOpcion("Tipo de lista: int(i), char(c), vector(v)\n","ivc");
        }
        else
        {
            switch (tList)
            {
                case 'i':
                    exito=RealizarOp(listaI,op);
                    break;
                case 'v':
                    exito=RealizarOp(listaV,op);
                    break;
                case 'c':
                    exito=RealizarOp(listaC,op);
                    break;
            }
        }
        if(op != '0')
        {
            if(exito)
                cout<<"\nexito en la operaci\242n\n";
            else
                cout<<"la operaci\242n no se pudo concretar...\nTal vez un error con los indices "<<
                        "o se intento borrar un elemento que no est\240...\n";
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
bool RealizarOp(ListaCircular<T> & ls, char op)
{
    try
    {
        T aux;
        switch(op)
        {
            case '1': //Agregar
                cout<<"Elemento a agregar: ";
                cin>>aux;
                ls.Agregar(aux);
                break;

            case '2': //Eliminar
                if(ls.EstaVacia()) return false;

                cout<<"Elemento eliminado: "<<ls.Eliminar();
                break;

            case '3': //Avanzar
                return ls.Avanzar();
                break;

            case '4': //Retroceder
                return ls.Retroceder();
                break;

            case '5': // Obtener cabeza
                if(ls.EstaVacia()) return false;
                else cout<<"Valor de la cabeza: "<<ls.ObtenerCabeza();
                break;

            case '6': //Buscar
                cout<<"Elemento a buscar: ";
                cin>>aux;
                if(ls.Buscar(aux)) cout<<"Si est\240...\n";
                else cout<<"No est\240...\n";
                break;

            case '7': // EstaVacia
                if(ls.EstaVacia()) cout<<"Si est\240 vacia...\n";
                else cout<<"No est\240 vacia...\n";
                break;

            case '8': // Vaciar
                ls.Vaciar();
                cout<<"Ahora est\240 vacia :D\n";
                break;

            case '9': // tamaño
                cout<<"El n\243mero de elementos en la lista es: ";
                cout<<ls.ObtenerTamano()<<'\n';
                break;

            case 'i': // imp. asc.
                cout<<"Lista : \n";
                cout<<ls<<'\n';
                break;

            case 'p': // Eliminar primera ocurrencia
                cout<<"Elemento a eliminar: ";
                cin>>aux;
                return ls.EliminarPriOcurrencia(aux);
                break;

            case 't': // Eliminar toda ocurrencia
                cout<<"Elemento a eliminar: ";
                cin>>aux;
                return ls.EliminarTodaOcurrencia(aux);
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
    cout<<"Agregar : 1\n";
    cout<<"Eliminar : 2\n";
    cout<<"Avanzar cabeza : 3\n";
    cout<<"Retroceder cabeza: 4\n";
    cout<<"Obtener cabeza : 5\n";
    cout<<"Buscar un elemento : 6\n";
    cout<<"Verificar si est\240 vacia: 7\n";
    cout<<"Vaciar lista: 8\n";
    cout<<"Tama\244o de la lista : 9\n";
    cout<<"Imprimir lista : i\n";
    cout<<"Eliminar primera ocurrencia: p\n";
    cout<<"Eliminar toda ocurrencia: t\n";;
    cout<<"Cambiar tipo de lista: c\n";
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
