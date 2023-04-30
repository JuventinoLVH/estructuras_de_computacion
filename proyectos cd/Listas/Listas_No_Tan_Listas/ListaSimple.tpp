/* Nombre: ListaSimple.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 28/Feb/2020
   Descripción: Archivo de implementación de la clase ListaSimple
*/

#include "ListaSimple.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaSimple<T>::ListaSimple()
{
    ultimo = NULL;
    primero = NULL;
    tam= 0;
}


//*************************************************************************************
template <typename T>
ListaSimple<T>::ListaSimple(const ListaSimple & ls)
{
    ultimo = NULL;
    primero=NULL;
    tam= 0;
    *this = ls;
}


//*************************************************************************************
template <typename T>
ListaSimple<T>::~ListaSimple()
{
    Vaciar();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaSimple<T> & ListaSimple<T>::operator= (const ListaSimple<T> & ls)
{

    if(this == &ls) return *this;
    Vaciar();

    Elemento *aux = ls.primero;
    while(aux != NULL)
    {
        AgregarAlFinal(aux->valor);
        aux=aux->siguiente;
    }

    return *this;
}


//*************************************************************************************
template <typename T>
const T & ListaSimple<T>::operator[] (int pos) const
{
    return ObtenerPos(pos);
}


//*************************************************************************************
template <typename T>
T & ListaSimple<T>::operator[] (int pos)
{
    return ObtenerPos(pos);
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
void ListaSimple<T>::AgregarAlPrincipio(const T & val)
{
    Elemento *aux = new Elemento(val,primero);
    primero = aux;
    if(tam == 0)
        ultimo = aux;
    tam++;
}

//*************************************************************************************
template <typename T>
void ListaSimple<T>::AgregarAlFinal(const T & val)
{
    Elemento *aux = new Elemento(val);
    if(tam==0)
        primero=aux;
    else
        ultimo->siguiente = aux;
    ultimo=aux;

    tam++;
}

//*************************************************************************************
template <typename T>
bool ListaSimple<T>::AgregarEnPos(const T & val , int pos)
{
    if(pos < 0 || (unsigned)pos > tam) return false;

    if(pos == 0)
    {
        AgregarAlPrincipio(val);
        return true;
    }
    if((unsigned)pos == tam)
    {
        AgregarAlFinal(val);
        return true;
    }

    Elemento *ant = primero;
    for(int i=1;i<pos;++i)
        ant = ant -> siguiente;

    Elemento * nuevo = new Elemento(val, ant->siguiente);
    ant->siguiente = nuevo;
    ++tam;
    return true;
}


//*************************************************************************************
template <typename T>
void ListaSimple<T>::EliminarDelPrincipio()
{
    if(EstaVacia()) return;

    Elemento *porSalir=primero;
    primero=primero->siguiente;
    delete porSalir;

    if(tam==1)
        ultimo=NULL;

    tam--;
}


//*************************************************************************************
template <typename T>
void ListaSimple<T>::EliminarDelFinal()
{
    if(EstaVacia()) return;

    Elemento *ant = primero;
    while(ant->siguiente != NULL && ant->siguiente != ultimo)
        ant= ant->siguiente;

    delete ultimo;

    ultimo = ant;
    ultimo->siguiente = NULL;

    if(tam==1)
        primero=ultimo=NULL;
    --tam;
}



//*************************************************************************************
template <typename T>
void ListaSimple<T>::EliminarDePos(int pos)
{
    if(EstaVacia()) return;

    if(pos < 0 || (unsigned)pos >= tam) return;

    if(pos==0)
    {
        EliminarDelPrincipio();
        return;
    }
    if((unsigned)pos==tam-1)
    {
        EliminarDelFinal();
        return;
    }

    Elemento *ant = primero;
    for(int i=1;i<pos;++i)
        ant = ant -> siguiente;

    Elemento * porSalir = ant->siguiente;
    ant->siguiente=ant->siguiente->siguiente;
    delete porSalir;
    --tam;
}


//*************************************************************************************
template <typename T>
bool ListaSimple<T>::Buscar(const T & val) const
{
    Elemento * aux = primero;
    while(aux != NULL )
    {
        if (aux->valor == val ) return true;
        aux = aux->siguiente;
    }
    return false;
}


//*************************************************************************************
template <typename T>
int ListaSimple<T>::BuscarPos(const T & val) const
{
    Elemento * aux = primero;

    int pos=0;
    for(;aux != NULL && aux->valor != val ;++pos)
        aux= aux->siguiente;

    return aux != NULL ? pos : -1;
}


//*************************************************************************************
template <typename T>
bool ListaSimple<T>::EstaVacia() const
{
    return tam == 0;
}


//*************************************************************************************
template <typename T>
const T & ListaSimple<T>::ObtenerPrimero() const
{
    if(EstaVacia()) throw ListaVacia();

    return primero->valor;
}


//*************************************************************************************
template <typename T>
T & ListaSimple<T>::ObtenerPrimero()
{
    if(EstaVacia()) throw ListaVacia();

    return primero->valor;
}


//*************************************************************************************
template <typename T>
const T & ListaSimple<T>::ObtenerUltimo() const
{
    if(EstaVacia()) throw ListaVacia();

    return ultimo->valor;
}


//*************************************************************************************
template <typename T>
T & ListaSimple<T>::ObtenerUltimo()
{
    if(EstaVacia()) throw ListaVacia();

    return ultimo->valor;
}


//*************************************************************************************
template <typename T>
const T & ListaSimple<T>::ObtenerPos(int pos) const
{
    if(EstaVacia()) throw ListaVacia();
    if(pos < 0 || (unsigned)pos >= tam) throw std::out_of_range("Valor fuera de rango");

    Elemento *aux = primero;
    for(int i=0;i<pos;++i)
        aux = aux -> siguiente;

    return aux->valor;
}


//*************************************************************************************
template <typename T>
T & ListaSimple<T>::ObtenerPos(int pos)
{
    if(EstaVacia()) throw ListaVacia();
    if(pos < 0 || (unsigned)pos >= tam) throw std::out_of_range("Valor fuera de rango");

    Elemento *aux = primero;
    for(int i=0;i<pos;++i)
        aux = aux -> siguiente;

    return aux->valor;
}


//*************************************************************************************
template <typename T>
bool ListaSimple<T>::ModPos(int pos, const T & val)
{
    if(EstaVacia() || pos < 0 || pos >= tam )return false;
    ObtenerPos(pos)=val;
    return true;
}

//*************************************************************************************
template <typename T>
unsigned int ListaSimple<T>::ObtenerTamano() const
{
    return tam;
}


//*************************************************************************************
template <typename T>
void ListaSimple<T>::Vaciar()
{
    while(!EstaVacia()) EliminarDelPrincipio();
}


//*************************************************************************************
template <typename T>
void ListaSimple<T>::Imprimir() const
{
    std::cout<<'{';

    if(!EstaVacia() )
    {
        Elemento *aux = primero ;
        while(aux != NULL)
        {
            std::cout<< aux->valor <<" ,";
            aux = aux->siguiente;
        }
    }
    if(!EstaVacia())  std::cout<<"\b\b ";
    std::cout<<'}';
}

 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
const char * ListaSimple<T>::ListaVacia::what() const throw()
{
    return "Lista sin elementos...";
}

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
template <typename T>
ListaSimple<T>::Elemento::Elemento(T v, Elemento * sig)
{
    valor=v;
    siguiente=sig;
}

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t>
std::ostream & operator<<(std::ostream & salida, const ListaSimple<t> &ls)
{
    ls.Imprimir();
    return salida;
}

