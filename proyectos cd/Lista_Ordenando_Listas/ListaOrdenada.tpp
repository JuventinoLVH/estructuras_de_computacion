/* Nombre: ListaOrdenada.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 20/03/21
   Descripción: Archivo de implementación de la clase ListaOrdenada
*/

#include "ListaOrdenada.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaOrdenada<T>::ListaOrdenada(){}

//*************************************************************************************
template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada & ls)
{
    lista=ls;
}


//*************************************************************************************
template <typename T>
ListaOrdenada<T>::~ListaOrdenada(){}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaOrdenada<T> & ListaOrdenada<T>::operator= (const ListaOrdenada<T> & ls)
{
    if(this == &ls) return *this;

    lista=ls;


    return *this;
}


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::AgregarElemento(const T & val)
{
    int pos= PosDeValor(val);
    lista.AgregarEnPos(val,pos);
}

//*************************************************************************************
template <typename T>
bool ListaOrdenada<T>::EliminarElemento(const T & val)
{
    return lista.EliminarDePos(lista.BuscarPos(val) );
}


//*************************************************************************************
template <typename T>
bool ListaOrdenada<T>::Buscar(const T & val) const
{
    return lista.Buscar(val);
}


//*************************************************************************************
template <typename T>
bool ListaOrdenada<T>::EstaVacia() const
{
    return lista.EstaVacia();
}


//*************************************************************************************
template <typename T>
unsigned int ListaOrdenada<T>::ObtenerTamano() const
{
    return lista.ObtenerTamano();
}


//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::Vaciar()
{
    lista.Vaciar();
}


//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::ImprimirAscendente(std::ostream & salida/*=std::cout*/) const
{
    lista.Imprimir(salida);
}


//*************************************************************************************
template <typename T>
void ListaOrdenada<T>::ImprimirDescendente(std::ostream & salida/*=std::cout*/) const
{
    lista.ImprimirDescendente(salida);
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template <typename T>
int ListaOrdenada<T>::PosDeValor(const T & val)
{
    if(lista.EstaVacia() )return 0;

    int siz=lista.ObtenerTamano();
    for(int i=0;i<siz;++i)
    {
        if(val <= lista[i]) return i;
    }
    return siz;
}

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
//*************************************************************************************
template <typename t>
std::ostream & operator<<(std::ostream & salida, const ListaOrdenada<t> &ls)
{
    ls.ImprimirAscendente();
    return salida;
}
