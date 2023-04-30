/* Nombre: ListaCircular.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 24/03/21
   Descripción: Archivo de implementación de la clase ListaCircular
*/

#include "ListaCircular.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaCircular<T>::ListaCircular()
{
    cabeza=NULL;
    tam= 0;
}


//*************************************************************************************
template <typename T>
ListaCircular<T>::ListaCircular(const ListaCircular & ls)
{
    cabeza=NULL;
    tam= 0;
    *this = ls;
}


//*************************************************************************************
template <typename T>
ListaCircular<T>::~ListaCircular()
{
    Vaciar();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaCircular<T> & ListaCircular<T>::operator= (const ListaCircular<T> & ls)
{

    if(this == &ls) return *this;
    Vaciar();

    Elemento *aux = ls.cabeza;
    unsigned tam=ls.ObtenerTamano();
    for(unsigned i=0; i < tam ;++i)
    {
        Agregar(aux->valor);
        aux=aux->siguiente;
    }

    return *this;
}


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
void ListaCircular<T>::Agregar(const T & val)
{
    if(tam==0)
    {
        Elemento *aux= new Elemento(val);
        cabeza=aux;
        cabeza->siguiente=aux;
        cabeza->anterior=aux;
    }
    else
    {
        Elemento *aux = new Elemento(val,cabeza->siguiente,cabeza);
        cabeza->siguiente->anterior=aux;
        cabeza->siguiente=aux;
    }
    tam++;
}


//*************************************************************************************
template <typename T>
T ListaCircular<T>::Eliminar()
{
    if(EstaVacia()) throw ListaVacia();

    Elemento *porSalir=cabeza->siguiente;
    T elemPorDevolver=porSalir->valor;

    porSalir->siguiente->anterior=porSalir->anterior;
    porSalir->anterior->siguiente=porSalir->siguiente;

    if(tam==1) cabeza= NULL;
    delete porSalir;

    --tam;
    return elemPorDevolver;

}


//*************************************************************************************
template <typename T>
bool ListaCircular<T>::Buscar(const T & val) const
{
    Elemento * aux = cabeza;
    for(unsigned i=0;i<tam;++i)
    {
        if (aux->valor == val ) return true;
        aux = aux->siguiente;
    }
    return false;
}


//*************************************************************************************
template <typename T>
bool ListaCircular<T>::EstaVacia() const
{
    return tam == 0;
}


//*************************************************************************************
template <typename T>
bool ListaCircular<T>::Avanzar()
{
    if(EstaVacia() ) return false;
    cabeza=cabeza->siguiente;
    return true;
}


//*************************************************************************************
template <typename T>
bool ListaCircular<T>::Retroceder()
{
    if(EstaVacia() ) return false;
    cabeza=cabeza->anterior;
    return true;
}


//*************************************************************************************
template <typename T>
const T & ListaCircular<T>::ObtenerCabeza() const
{
    if(EstaVacia()) throw ListaVacia();

    return cabeza->valor;
}


//*************************************************************************************
template <typename T>
unsigned int ListaCircular<T>::ObtenerTamano() const
{
    return tam;
}


//*************************************************************************************
template <typename T>
void ListaCircular<T>::Vaciar()
{
    while(!EstaVacia()) Eliminar();
}


//*************************************************************************************
template <typename T>
void ListaCircular<T>::Imprimir(std::ostream & salida/*=std::cout*/) const
{
    salida<<'{';

    Elemento *aux = cabeza;
    for(unsigned i=0;i<tam;++i)
    {
        salida<< aux->valor <<" ,";
        aux = aux->siguiente;
    }
    if(!EstaVacia())  salida<<"\b\b";
    salida<<"} ";
}


//*************************************************************************************
template <typename T>
bool ListaCircular<T>::EliminarPriOcurrencia(const T & val)
{
    if(EstaVacia() ) return false;
    if(cabeza->valor==val)
    {
        EliminarCab();
        return true;
    }

    Elemento *cabAux=cabeza;
    Avanzar();
    for(unsigned i=1;i<tam;++i)
    {
        if(cabeza->valor == val)
        {
            EliminarCab();
            cabeza=cabAux;
            return true;
        }
        Avanzar();
    }
    return false;
}


//*************************************************************************************
template <typename T>
bool ListaCircular<T>::EliminarTodaOcurrencia(const T & val)
{
    if(EstaVacia() ) return false;
    bool elimino=false;

    if(cabeza->valor==val)
    {
        elimino =true;
        do
        {
            EliminarCab();
        }while( !EstaVacia() && cabeza->valor==val);
    }

    Avanzar();
    for(unsigned i=1;i<tam;++i)
    {
        if(cabeza->valor == val)
        {
            EliminarCab();
            elimino=true;
            --i;
        }
        Avanzar();
    }
    return elimino;
}

 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
const char * ListaCircular<T>::ListaVacia::what() const throw()
{
    return "Lista sin elementos...";
}

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template <typename T>
ListaCircular<T>::Elemento::Elemento(T v, Elemento * sig/*=NULL*/, Elemento * ant/*=NULL*/)
{
    valor=v;
    siguiente=sig;
    anterior=ant;
}


//*************************************************************************************
template <typename T>
void ListaCircular<T>::EliminarCab()
{
    if(EstaVacia()) return ;

    Elemento *porSalir=cabeza;

    cabeza->siguiente->anterior=cabeza->anterior;
    cabeza->anterior->siguiente=cabeza->siguiente;

    if(tam!=1) cabeza=cabeza->siguiente;
    else cabeza= NULL;

    delete porSalir;

    --tam;
    return;

}


 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t>
std::ostream & operator<<(std::ostream & salida, const ListaCircular<t> &ls)
{
    ls.Imprimir(salida);
    return salida;
}
