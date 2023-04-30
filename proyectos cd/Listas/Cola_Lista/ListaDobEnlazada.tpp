


/* Nombre: ColaCircular.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 28/Feb/2020
   Descripción: Archivo de implementación de la clase Expresion
*/

#include "ListaDobEnlazada.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaDobEnlazada<T>::ListaDobEnlazada()
{
    ultimo = NULL;
    primero = NULL;
    tam= 0;
}


//*************************************************************************************
template <typename T>
ListaDobEnlazada<T>::ListaDobEnlazada(const ListaDobEnlazada & ls)
{
    ultimo = NULL;
    primero=NULL;
    tam= 0;
    *this = ls;
}


//*************************************************************************************
template <typename T>
ListaDobEnlazada<T>::~ListaDobEnlazada()
{
    Vaciar();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
ListaDobEnlazada<T> & ListaDobEnlazada<T>::operator= (const ListaDobEnlazada<T> & ls)
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
const T & ListaDobEnlazada<T>::operator[] (int pos) const
{
    return ObtenerPos(pos);
}


//*************************************************************************************
template <typename T>
T & ListaDobEnlazada<T>::operator[] (int pos)
{
    return ObtenerPos(pos);
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::AgregarAlPrincipio(const T & val)
{
    Elemento *aux = new Elemento(val,primero);
    if(tam == 0)
        ultimo = aux;
    else
        primero->anterior=aux;
    primero = aux;
    tam++;
}

//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::AgregarAlFinal(const T & val)
{
    Elemento *aux = new Elemento(val,NULL,ultimo);
    if(tam==0)
        primero=aux;
    else
        ultimo->siguiente = aux;
    ultimo=aux;

    tam++;
}

//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::AgregarEnPos(const T & val , int pos)
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

    Elemento *aux=ObtenerElemento(pos);
    Elemento * nuevo = new Elemento(val,aux,aux->anterior);
    nuevo->anterior->siguiente=nuevo;
    nuevo->siguiente->anterior=nuevo;


    ++tam;
    return true;
}


//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::EliminarDelPrincipio()
{
    if(EstaVacia()) return false;

    Elemento *porSalir=primero;
    primero=primero->siguiente;


    if(tam==1)
        ultimo=NULL;
    else
        primero->anterior=NULL;
    delete porSalir;

    tam--;
    return true;
}


//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::EliminarDelFinal()
{
    if(EstaVacia()) return false;

    Elemento *porSalir=ultimo;
    ultimo=ultimo->anterior;


    if(tam==1)
        primero=NULL;
    else
        ultimo->siguiente=NULL;
    delete porSalir;

    tam--;
    return true;
}



//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::EliminarDePos(int pos)
{
    if(pos < 0 || (unsigned)pos >= tam) return false;

    if(pos==0)
        return EliminarDelPrincipio();
    if((unsigned)pos==tam-1)
        return EliminarDelFinal();

    Elemento *aux=ObtenerElemento(pos);
    aux->siguiente->anterior=aux->anterior;
    aux->anterior->siguiente=aux->siguiente;
    delete aux;
    --tam;
    return true;
}


//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::Buscar(const T & val) const
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
int ListaDobEnlazada<T>::BuscarPos(const T & val) const
{
    Elemento * aux = primero;

    int pos=0;
    for(;aux != NULL && aux->valor != val ;++pos)
        aux= aux->siguiente;

    return aux != NULL ? pos : -1;
}


//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::EstaVacia() const
{
    return tam == 0;
}


//*************************************************************************************
template <typename T>
const T & ListaDobEnlazada<T>::ObtenerPrimero() const
{
    if(EstaVacia()) throw ListaVacia();

    return primero->valor;
}
//*************************************************************************************
template <typename T>
T & ListaDobEnlazada<T>::ObtenerPrimero()
{
    if(EstaVacia()) throw ListaVacia();

    return primero->valor;
}


//*************************************************************************************
template <typename T>
const T & ListaDobEnlazada<T>::ObtenerUltimo() const
{
    if(EstaVacia()) throw ListaVacia();

    return ultimo->valor;
}
//*************************************************************************************
template <typename T>
T & ListaDobEnlazada<T>::ObtenerUltimo()
{
    if(EstaVacia()) throw ListaVacia();

    return ultimo->valor;
}


//*************************************************************************************
template <typename T>
const T & ListaDobEnlazada<T>::ObtenerPos(int pos) const
{
    if(EstaVacia()) throw ListaVacia();
    if(pos < 0 || (unsigned)pos >= tam) throw std::out_of_range("Valor fuera de rango");
    return ObtenerElemento(pos)->valor;
}
//*************************************************************************************
template <typename T>
T & ListaDobEnlazada<T>::ObtenerPos(int pos)
{
    if(EstaVacia()) throw ListaVacia();
    if(pos < 0 || (unsigned)pos >= tam) throw std::out_of_range("Valor fuera de rango");
    return ObtenerElemento(pos)->valor;
}


//*************************************************************************************
template <typename T>
unsigned int ListaDobEnlazada<T>::ObtenerTamano() const
{
    return tam;
}


//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::Vaciar()
{
    while(!EstaVacia()) EliminarDelPrincipio();
}


//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::Imprimir() const
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
void ListaDobEnlazada<T>::EliminarElementosRepetidos()
{
    Elemento *aux=primero;


    for(int i=0;aux != NULL;++i)
    {
        Elemento *aRev=aux->siguiente;
        for(int j=i+1;aRev != NULL;++j)
        {
            if(aRev->valor == aux->valor)
            {
                aRev=aRev->siguiente;
                EliminarDePos(j);
                --j;
            }
            else aRev=aRev->siguiente;
        }
        aux= aux->siguiente;

    }
}


//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::EliminarPorCondicion( bool (*Condicion)(const T&) )
{
    Elemento *aux = primero;
    for(int i=0; aux  != NULL; ++i)
    {
        if(Condicion(aux->valor) )
        {
            EliminarDePos(i);
            --i;
        }
        aux= aux->siguiente;
    }
}


//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::EliminarElemento(const T & val)
{
    Elemento *aux = primero;
    for(int i=0; aux  != NULL; ++i)
    {
        if(val == aux->valor )
        {
            EliminarDePos(i);
            --i;
        }
        aux= aux->siguiente;
    }
}


//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::OrdenarAscendente()
{
    for(unsigned i=1;i<tam;++i)
    {
        for(unsigned j=0;j<tam-i;++j)
        {
            if((*this)[j] <  (*this)[j+1])
            {
                T aux = (*this)[j];
                (*this)[j]=(*this)[j+1];
                (*this)[j+1]=aux;
            }
        }
    }
}


//*************************************************************************************
template <typename T>
void ListaDobEnlazada<T>::IntercambiarLista(ListaDobEnlazada<T> & ls)
{
    Elemento *primAux=primero;
    Elemento *ultAux=ultimo ;
    unsigned tamAux = tam;

    tam=ls.tam;
    primero=ls.primero;
    ultimo=ls.ultimo;

    ls.tam=tamAux;
    ls.primero=primAux;
    ls.ultimo=ultAux;

}


//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::TransferirTodoA( ListaDobEnlazada<T> & ls)
{
    if(EstaVacia()) return false;

    if(ls.ultimo!=NULL)
        ls.ultimo->siguiente=primero;
    else
        ls.primero=primero;

    primero->anterior=ls.ultimo;
    ls.ultimo=ultimo;
    ls.tam+=tam;

    primero=ultimo=NULL;
    tam=0;
    return true;
}


//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::TransferirDesde( ListaDobEnlazada<T> & ls, int i)
{
    if(EstaVacia() || (unsigned)i>=tam || i<0) return false;
    if(i==0) return TransferirTodoA(ls);

    Elemento * aux= ObtenerElemento(i);
    Elemento * orAnt= aux->anterior;

    if(ls.ultimo!= NULL)
        ls.ultimo->siguiente=aux;
    else
        ls.primero=aux;

    aux->anterior=ls.ultimo;
    ls.ultimo=ultimo;
    ls.tam+=tam-i;

    orAnt->siguiente=NULL;
    ultimo=orAnt;
    tam=i;

    return true;
}


//*************************************************************************************
template <typename T>
bool ListaDobEnlazada<T>::TransferirDesdeHasta( ListaDobEnlazada<T> & ls, int i,int f)
{
    if((unsigned)i >= tam || (unsigned)f>=tam || i<0 || f<0) return false;

    if(i>f)
    {
        int aux=i;
        i=f;
        f=aux;
    }

    if((unsigned)f==tam-1)
    {
        TransferirDesde(ls,i);
        return true;
    }
    int tamOr= ls.tam;
    TransferirDesde(ls,i);
    ls.TransferirDesde(*this , tamOr +(f-i+1) );

    return true;
}

 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
const char * ListaDobEnlazada<T>::ListaVacia::what() const throw()
{
    return "Lista sin elementos...";
}

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template <typename T>
ListaDobEnlazada<T>::Elemento::Elemento(T v, Elemento * sig/*=NULL*/, Elemento * ant/*=NULL*/)
{
    valor=v;
    siguiente=sig;
    anterior=ant;
}


//*************************************************************************************
template <typename T>
typename ListaDobEnlazada<T>::Elemento * ListaDobEnlazada<T>::ObtenerElemento(int pos)
{
    bool empDerecha = ((unsigned)pos < tam/2 ? true : false);
    Elemento *aux;
    if(empDerecha)
    {
        aux=primero;
        for(int i=0;i<pos;++i)
            aux = aux -> siguiente;
    }
    else
    {
        aux=ultimo;
        for(int i=tam-1;i>pos; --i)
            aux= aux->anterior;
    }
    return aux;
}


 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t>
std::ostream & operator<<(std::ostream & salida, const ListaDobEnlazada<t> &ls)
{
    ls.Imprimir();
    return salida;
}
