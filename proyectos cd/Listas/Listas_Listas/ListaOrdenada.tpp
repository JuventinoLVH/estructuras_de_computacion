/* Nombre: ListaOrdenada.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 16/Mar/2021
   Descripción: Archivo de implementación de la clase ListaOrdenada
*/

#include "ListaOrdenada.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaOrdenada<T>::ListaOrdenada()
{
    ultimo = NULL;
    primero = NULL;
    tam= 0;
}


//*************************************************************************************
template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada & ls)
{
    ultimo = NULL;
    primero=NULL;
    tam= 0;
    *this = ls;
}


//*************************************************************************************
template <typename T>
ListaOrdenada<T>::~ListaOrdenada()
{
    Vaciar();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaOrdenada<T> & ListaOrdenada<T>::operator= (const ListaOrdenada<T> & ls)
{

    if(this == &ls) return *this;
    Vaciar();

    Elemento *aux = ls.primero;
    while(aux != NULL)
    {
        AgregarElemento(aux->valor);
        aux=aux->siguiente;
    }

    return *this;
}


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::AgregarElemento(const T & val)
{
    Elemento *aux=primero;
    while(aux!= NULL && aux->valor < val) aux=aux->siguiente;

    Elemento **anteriorOr = (aux==NULL ? &ultimo : &(aux->anterior));
    Elemento *nuevo = new Elemento(val,aux,*anteriorOr);

    if(aux==primero) primero=nuevo;
    else (*anteriorOr)->siguiente= nuevo;

    *anteriorOr=nuevo;
    tam++;
}

//*************************************************************************************
template <typename T>
bool ListaOrdenada<T>::EliminarElemento(const T & val)
{
    Elemento *porSalir=primero;
    while(porSalir!= NULL && porSalir->valor < val) porSalir=porSalir->siguiente;

    if(porSalir->valor != val) return false;

    if(porSalir == primero) primero=primero->siguiente;
    else porSalir->anterior->siguiente = porSalir->siguiente;

    if(porSalir == ultimo) ultimo=ultimo->anterior;
    else porSalir->siguiente->anterior = porSalir->anterior;

    delete porSalir;
    --tam;

    return true;
}


//*************************************************************************************
template <typename T>
bool ListaOrdenada<T>::Buscar(const T & val) const
{
    Elemento * aux = primero;
    while(aux != NULL && aux->valor < val)  aux = aux->siguiente;

    return aux->valor == val;
}


//*************************************************************************************
template <typename T>
bool ListaOrdenada<T>::EstaVacia() const
{
    return tam == 0;
}


//*************************************************************************************
template <typename T>
unsigned int ListaOrdenada<T>::ObtenerTamano() const
{
    return tam;
}


//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::Vaciar()
{
    while(!EstaVacia() ) EliminarElemento(primero->valor);
}


//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::ImprimirAscendente() const
{
    std::cout<<'{';

    Elemento *aux = primero ;
    while(aux != NULL)
    {
        std::cout<< aux->valor <<" ,";
        aux = aux->siguiente;
    }
    if(!EstaVacia())  std::cout<<"\b\b";
    std::cout<<"} ";
}


//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::ImprimirDescendente() const
{
    std::cout<<'{';

    Elemento *aux = ultimo ;
    while(aux != NULL)
    {
        std::cout<< aux->valor <<" ,";
        aux = aux->anterior;
    }
    if(!EstaVacia())  std::cout<<"\b\b";
    std::cout<<"} ";
}


 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
const char * ListaOrdenada<T>::ListaVacia::what() const throw()
{
    return "Lista sin elementos...";
}

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template <typename T>
ListaOrdenada<T>::Elemento::Elemento(T v, Elemento * sig/*=NULL*/, Elemento * ant/*=NULL*/)
{
    valor=v;
    siguiente=sig;
    anterior=ant;
}


 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t>
std::ostream & operator<<(std::ostream & salida, const ListaOrdenada<t> &ls)
{
    ls.ImprimirAscendente();
    return salida;
}
