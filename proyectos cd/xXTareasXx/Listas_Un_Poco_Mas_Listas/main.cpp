/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 28/Feb/2020
   Descripción: Cliente para probara la clase ListaDobEnlazada
*/

#include<limits>
#include<windows.h>
#include<iostream>
#include<iostream>
#include"ListaDobEnlazada.h"
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
/** \brief Dice si un índicec está dentro del rango valido de una lista
 *
 * \param ls una lista
 * \param i el indice a validar
 * \return true si i >= 0 || i< tamaño de la lista, false de lo contrario
 */
template<typename T>
bool RangoValido(int i, const ListaDobEnlazada<T> & ls);

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
bool RealizarOp(ListaDobEnlazada<T> & ls, char op, ListaDobEnlazada<T> & mLs);

//*************************************************************************************
/** \brief Criterio para eliminar en la funcion "EliminarPorCondicion"
 *
 * \param val el valor a juzgar
 * \return sí el elemento se elimina
 *
 */
template<typename T>
bool LaCondicion(const T & val);

//*************************************************************************************
/** \brief Imprime el menu
 */
void ImprMenu();

//*************************************************************************************
/** \brief Pregunta en dondé quiere realizar la operacion (inicio, fin, indice)
 */
void Impr3Op();

//*************************************************************************************
/** \brief Pregunta cómo se eliminara el elemento(inicio, fin,
 *          indice, todos los repetidos, todo elemento 'x' o por 'la condicion')
 *
 */
void ImprOpEliminar();

//*************************************************************************************
/** \brief Pregunta cómo se transfieren las listas
 */
void ImprTrans();

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

    ListaDobEnlazada<int> listaI;
    ListaDobEnlazada<Vector > listaV;
    ListaDobEnlazada<char> listaC;
    ListaDobEnlazada<int> listaIM;
    ListaDobEnlazada<Vector > listaVM;
    ListaDobEnlazada<char> listaCM;
    bool exito;
    char tList;
    char op;
    //tList = LeerOpcion("Tipo de lista inicial: int(i), char(c), vector(v)\n","imc");

    tList='i';
    for(int i=0;i<10;++i)
    {
        listaI.AgregarAlFinal(i);
    }
    cout<<listaI<<'\n';

    do
    {
        cout<<"Recuerde, el tipo de la lista es: ("<<tList<<")";
        ImprMenu();
        op=LeerOpcion("Opci\242n: ","0123456789opmgcli");

        if(op == '0' || op=='l' )
        {
            exito=true;
            if(op=='l')
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
                cout<<"\nla operaci\242n no se pudo concretar...\nTal vez un error con los indices "<<
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

    }while(!opValida);

    return op;
}


//*************************************************************************************
template<typename T>
bool RealizarOp(ListaDobEnlazada<T> & ls , char op, ListaDobEnlazada<T> & mLs)
{
    try
    {
        int i,f;
        char opAux;
        T aux;
        switch(op)
        {
            case '1': //Agregar
                Impr3Op();
                opAux=LeerOpcion("Opci\242n: ","ife");
                cout<<"Elemento a agregar: ";
                cin>>aux;

                switch(opAux)
                {
                    case 'i':
                        ls.AgregarAlPrincipio(aux);
                        break;
                    case 'f':
                        ls.AgregarAlFinal(aux);
                        break;
                    case 'e':
                        do
                        {
                            i=CapturaEntero("Posici\242n: ");
                            if(!((unsigned)i==ls.ObtenerTamano() || RangoValido(i,ls)))
                                cout<<"Rango invalido...\n";

                        }while(!((unsigned)i==ls.ObtenerTamano() || RangoValido(i,ls)));

                        ls.AgregarEnPos(aux,i);
                        break;
                }
                break;

            case '2': //Eliminar
                if(ls.EstaVacia() )
                {
                    cout<<"No hay elementos en la lista...\n";
                    return false;
                    break;
                }

                ImprOpEliminar();
                opAux=LeerOpcion("Opci\242n: ","ifeorc");

                switch(opAux)
                {
                    case 'i':
                        return ls.EliminarDelPrincipio();
                        break;
                    case 'f':
                        return ls.EliminarDelFinal();
                        break;
                    case 'e':
                        do
                        {
                            i=CapturaEntero("Posici\242n: ");
                            if(!RangoValido(i,ls)) cout<<"Rango invalido...\n";

                        }while(!RangoValido(i,ls));
                        return ls.EliminarDePos(i);
                        break;
                    case 'c':
                        ls.EliminarPorCondicion(LaCondicion );
                        break;
                    case 'o':
                        cout<<"Elemento a eliminar: ";
                        cin>>aux;
                        ls.EliminarElemento(aux);
                        break;
                    case 'r':
                        ls.EliminarElementosRepetidos();
                        break;
                }
                break;

            case '3': //Obtener
                if(ls.EstaVacia() )
                {
                    cout<<"No hay elementos en la lista...\n";
                    return false;
                    break;
                }

                Impr3Op();
                opAux=LeerOpcion("Opci\242n: ","ife");

                switch(opAux)
                {
                    case 'i':
                        cout<<"El elemento al inicio es: "<<ls.ObtenerPrimero()<<'\n';
                        break;

                    case 'f':
                        cout<<"El elemento al final es: "<<ls.ObtenerUltimo()<<'\n';
                        break;

                    case 'e':
                        do
                        {
                            i=CapturaEntero("Posici\242n: ");
                            if(!RangoValido(i,ls)) cout<<"Rango invalido...\n";

                        }while(!RangoValido(i,ls));
                        cout<<"El elemento en la posici\242n "<<i<<" es: "<<ls[i]<<'\n';
                        break;
                }
                break;

            case '4': //Modificar
                if(ls.EstaVacia() )
                {
                    cout<<"No hay elementos en la lista...\n";
                    return false;
                    break;
                }

                Impr3Op();
                opAux=LeerOpcion("Opci\242n: ","ife");
                cout<<"Nuevo elemento: ";
                cin>>aux;
                switch(opAux)
                {
                    case 'i':
                        cout<<"Elemento anterior: "<<ls.ObtenerPrimero()<<'\n';
                        ls[0]=aux;
                        cout<<"Nuevo elemento: "<<ls.ObtenerPrimero()<<'\n';
                        break;
                    case 'f':
                        cout<<"Elemento anterior: "<<ls.ObtenerUltimo()<<'\n';
                        ls.ObtenerUltimo()=aux;
                        cout<<"Nuevo elemento: "<<ls.ObtenerUltimo()<<'\n';
                        break;
                    case 'e':
                        do
                        {
                            i=CapturaEntero("Posici\242n: ");
                            if(!RangoValido(i,ls)) cout<<"Rango invalido...\n";

                        }while(!RangoValido(i,ls));
                        cout<<"El elemento anterior en la posici\242n "<<i<<" es: "<<ls[i]<<'\n';
                        ls[i]=aux;
                        cout<<"El nuevo elemento en la posici\242n "<<i<<" es: "<<ls[i]<<'\n';
                        break;
                }
                break;

            case '5': //Buscar
                cout<<"Elemento a buscar: ";
                cin>>aux;
                if(ls.Buscar(aux)) cout<<"Si est\240...\n";
                else cout<<"No est\240...\n";
                break;

            case '6': //Buscar pos
                cout<<"Elemento a buscar: ";
                cin>>aux;
                i=ls.BuscarPos(aux);
                if(i != -1) cout<<"El elemento "<<aux<<" tiene el indice: "<<i<<'\n';
                else cout<<"El elemento no est\240...\n";
                break;

            case '7': // EstaVacia
                if(ls.EstaVacia()) cout<<"Si est\240 vacia...\n";
                else cout<<"No est\240 vacia...\n";
                break;

            case '8': // Vaciar
                ls.Vaciar();
                cout<<"Ahora est\240 vacia :D\n";

                break;
            case '9': // tam
                cout<<"La lista tiene: "<<ls.ObtenerTamano()<<" elementos\n";
                break;

            case 'o': //Ordenar
                ls.OrdenarAscendente();
                break;

            case 'p': //print
                cout<<ls<<'\n';
                break;

            case 'm': //print mem
                cout<<mLs<<'\n';
                break;

            case 'g': //Guardar
                ImprTrans();
                opAux=LeerOpcion("Opci\242n: ","123");
                switch(opAux)
                {
                    case '1':
                        ls.TransferirTodoA(mLs);
                        break;
                    case '2':
                        i=CapturaEntero("Inicio: ");
                        return ls.TransferirDesde(mLs,i);
                        break;
                    case '3':
                        i=CapturaEntero("Inicio: ");
                        f=CapturaEntero("Final: ");
                        return ls.TransferirDesdeHasta(mLs,i,f);
                        break;
                }
                break;

            case 'c': //Cargar
                ImprTrans();
                opAux=LeerOpcion("Opci\242n: ","123");
                switch(opAux)
                {
                    case '1':
                        mLs.TransferirTodoA(ls);
                        break;
                    case '2':
                        i=CapturaEntero("Inicio: ");
                        return mLs.TransferirDesde(ls,i);
                        break;
                    case '3':
                        i=CapturaEntero("Inicio: ");
                        f=CapturaEntero("Final: ");
                        return mLs.TransferirDesdeHasta(ls,i,f);
                        break;
                }
                break;

            case 'i': //Intercambiar
                ls.IntercambiarLista(mLs);
                break;
        }
    }
    catch(exception & e)
    {
        cout<<"Algo fuera de mis limites acaba de pasar, posiblemente error "<<
                "al asignar la memoria: "<<e.what();
        return false;
    }
    return true;
}


//*************************************************************************************
template<typename T>
bool LaCondicion(const T & val)
{
    return val < 65;
}


//*************************************************************************************
void ImprMenu()
{
    cout<<"\nMenu:\n";
    cout<<"Agregar: 1\n";
    cout<<"Eliminar : 2\n";
    cout<<"Obtener un elemento: 3\n";
    cout<<"Modificar un elemento: 4\n";
    cout<<"Buscar un elemento : 5\n";
    cout<<"Buscar la posici\242n de un elemento: 6\n";
    cout<<"Verificar si est\240 vacia: 7\n";
    cout<<"Vaciar lista: 8\n";
    cout<<"Tama\244o de la lista : 9\n";
    cout<<"Ordenar lista : o\n";
    cout<<"Imprimir lista : p\n";
    cout<<"Imprimir memoria : m\n";
    cout<<"Transferir a la memoria: g\n";
    cout<<"Transferir de la memoria: c\n";
    cout<<"Intercambiar memoria y lista: i\n";
    cout<<"Cambiar tipo de lista: l\n";
    cout<<"Salir: 0\n";
}


//*************************************************************************************
void Impr3Op()
{
    cout<<"\250En d\242nde quieres realizar la operaci\242n?\n";
    cout<<"Inicio: i\n";
    cout<<"Final: f\n";
    cout<<"Especificar posici\242n: e\n";
}

//*************************************************************************************
void ImprOpEliminar()
{
    cout<<"\250C\242mo quieres realizar la operaci\242n?\n";
    cout<<"Eliminar del inicio: i\n";
    cout<<"Eliminar del final: f\n";
    cout<<"Eliminar de una posici\242n especifica: e\n";
    cout<<"Todo ocurrencia de un elemento : o\n";
    cout<<"Todo elemento repetido: r\n";
    cout<<"Segun 'la condici\242n' : c\n";
}


//*************************************************************************************
void ImprTrans()
{
    cout<<"\250Desde d\242nde quieres transferir?\n";
    cout<<"Inicio: 1\n";
    cout<<"Especificar posici\242n de inicio: 2\n";
    cout<<"Especificar posici\242n de inicio y fin: 3\n";
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


//*************************************************************************************
template<typename T>
bool RangoValido(int i, const ListaDobEnlazada<T> & ls)
{
    if(i>= 0 && (unsigned)i< ls.ObtenerTamano()) return true;
    return false;
}
