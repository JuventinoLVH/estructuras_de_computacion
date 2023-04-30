/* Nombre: main.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 2/03/2020
   Descripción: Cliente echo para probar la clase ColaCircular
*/

#include<stdlib.h>
#include<iostream>
#include"ColaCircular.h"

using namespace std;
 /***************************************************************************************
 ********************************  Funciónes aux  ***************************************
 ***************************************************************************************/
//*************************************************************************************
/** \brief Gestiona la mayoría de las operaciones
 *
 * \param cola la cola en la que se realizará la operación
 * \param memCola la memoria de la cola
 * \param op la operación a efectuar
 *
 */
template<typename T>
void RealizarOp(ColaCircular<T> & cola ,ColaCircular<ColaCircular<T> > & memCola, char op);

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

int main()
{
    cout<<"Bienvenido a la implementaci\242n de la increible clase cola :0 Se pondr\240 a su disposici\242n " <<
            "2 tipos de colas, una de n\243meros y otra de caracteres\n Tambi\202n podras guardar el estado " <<
                "de cada cola, \41Pero la memoria tambien es una cola!\n";

    ColaCircular<int> cEnt;
    ColaCircular<string> cStr;
    ColaCircular<ColaCircular<int> >memCEnt;
    ColaCircular<ColaCircular<string> >memCStr;

    char colaAct,op;
    colaAct=LeerOpcion( "\250En qu\202 cola quieres encolar? (Int: 'i' , String 's')\n" , "is" );

    int auxI;
    string auxS;
    do
    {
        if(colaAct=='s')
            cout<<"Recuerda, el tipo de la cola es: string\n";
        else
            cout<<"Recuerda, el tipo de la cola es: int\n";
        ImprMenu();
        op=LeerOpcion("Opci\242n: " , "0123456789cpui");

        if(op == '0' || op=='c' || op=='1')
        {
            if(op == '1')
            {
                try
                {
                    if(colaAct == 's')
                    {
                        cout<<"Cadena a guardar: ";
                        cin>>auxS;
                        cStr.Encolar(auxS);
                    }
                    else
                    {
                        cout<<"N\243mero a guardar: ";
                        cin>>auxI;
                        cEnt.Encolar(auxI);
                    }
                    cout<<"Exito al guardar :)\n ";
                }
                catch(...)
                {
                    cout<<"No se pudo guardar...\n";
                }
            }

            if(op == 'c')
            {
                colaAct = colaAct == 's' ? 'i' : 's';
                cout<<"Cambio con exito :D\n";
            }
        }
        else
        {
            if(colaAct == 's')
                RealizarOp(cStr,memCStr,op);
            else
                RealizarOp(cEnt,memCEnt,op);
        }
        system("pause");
        system("cls");


    }while(op != '0');

    cout<<"Gracias por usar el programa de colas, son 3 pesos porfavor\n";
    system("pause");
    return 0;
}

 /***************************************************************************************
 ********************************  Implementación  **************************************
 ***************************************************************************************/

//*************************************************************************************
void ImprMenu()
{
    cout<<"\nMenu:\n";
    cout<<"Agregar: 1\n";
    cout<<"Eliminar primer elemento: 2\n";
    cout<<"Elemento al inicio: 3\n";
    cout<<"Elemento al final: 4\n";
    cout<<"Verificar si est\240 vacia: 5\n";
    cout<<"Vaciar cola: 6\n";
    cout<<"Tama\244o de la cola : 7\n";
    cout<<"Guardar cola: 8\n";
    cout<<"Imprimir cola: 9\n";
    cout<<"Cambiar de cola: c\n";
    cout<<"Cargar primer elemento: p\n";
    cout<<"Cargar ultimo elemento: u\n";
    cout<<"Imprimir memoria: i\n";
    cout<<"Salir: 0\n";
}


//*************************************************************************************
char LeerOpcion(const char * mensaje , const char *opciones )
{
    bool opValida=true;
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
            cout<<"Opci\242n no v\240lida...";

    }while(!opValida);

    return op;
}


//*************************************************************************************
template<typename T>
void RealizarOp(ColaCircular<T> & cola ,ColaCircular<ColaCircular<T> > & memCola, char op)
{
    switch(op)
    {
        case '2':
            if(!cola.EstaVacia())
            {
                cola.Desencolar();
                cout<<"Elemento desencolado...\n";
            }
            else
                cout<<"La cola est\240 vacia...\n";

            break;

        case '3':
            if(!cola.EstaVacia())
            {
                cout<<"Elemento al inicio : "<<cola.PrimElemento()<<"\n";
            }
            else
                cout<<"La cola est\240 vacia...\n";
            break;

        case '4':
            if(!cola.EstaVacia())
            {
                cout<<"Elemento al final : "<<cola.UltElemento()<<"\n";
            }
            else
                cout<<"La cola est\240 vacia... \250porqu\202 eres as\241?\n ";
            break;

        case '5':
            if(cola.EstaVacia())
                cout<<"Si est\240 vacia\n";
            else
                cout<<"No est\240 vacia\n";
            break;

        case '6':
            cola.Vaciar();
            cout<<"Listo, la cola ya se vaci\242\n";
            break;

        case '7':
            cout<<"La cola tiene : "<<cola.ObtenerTam()<<" elementos\n";
            break;

        case '8':
            try
            {
                memCola.Encolar(cola);
                cout<<"Exito al guardar c: \n";
            }
            catch(...)
            {
                cout<<"No se pudo guardar...\n";
            }
            break;

        case '9':
            cout<<"La cola actual contiene: ";
            cola.Imprimir();
            cout<<'\n';
            break;

        case 'p':
            if(!cola.EstaVacia())
            {
                cola = memCola.PrimElemento();
                cout<<"Exito al cargar \n";
            }
            else
                cout<<"La memoria est\240 vacia...\n";

            break;

        case 'u':
            if(!cola.EstaVacia())
            {
                cola = memCola.UltElemento();
                cout<<"Exito al cargar \n";
            }
            else
                cout<<"La memoria est\240 vacia...\n";
            break;

        case 'i':
            cout<<"La memoria de la cola actual tiene: ";
            memCola.Imprimir();
            cout<<'\n';
            break;
    }
}
