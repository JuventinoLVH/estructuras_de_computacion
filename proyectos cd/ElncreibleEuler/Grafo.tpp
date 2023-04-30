/* Nombre: Grafo.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 04/04/21
   Descripción: Archivo de implementación de la clase 'Grafo'
*/

#include"Grafo.h"


 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T, typename A>
Grafo<T,A>::Grafo() : primero(NULL),ultimo(NULL),nNodos(0),nAristas(0){}


//*************************************************************************************
template<typename T, typename A>
Grafo<T,A>::Grafo(const Grafo & grf) : primero(NULL),ultimo(NULL),nNodos(0),nAristas(0)
{
    *this=grf;
}


//*************************************************************************************
template<typename T, typename A>
Grafo<T,A>::~Grafo()
{
    VaciarGrafica();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T, typename A>
Grafo<T,A> & Grafo<T,A>::operator= (const Grafo<T,A> & grf)
{
    if(this == & grf) return *this;
    VaciarGrafica();

    Nodo *auxNodo=grf.primero;
    while(auxNodo != NULL)
    {
        Agregar(auxNodo->ID);
        auxNodo=auxNodo->siguiente;
    }

    auxNodo=grf.primero;
    typename Nodo::Arista *auxArista=NULL;
    while(auxNodo != NULL)
    {
        auxArista=auxNodo->primero;
        while(auxArista != NULL)
        {
            if(!Buscar(auxNodo->ID,auxArista->adyacente->ID))
                Agregar(auxNodo->ID,auxArista->adyacente->ID);
            auxArista=auxArista->siguiente;
        }
        auxNodo=auxNodo->siguiente;
    }



    return *this;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::Agregar(const T & eNodo)
{
    if(Buscar(eNodo)) return false;

    Nodo *nuevo= new Nodo(eNodo,NULL,ultimo);
    if(ultimo != NULL)
        ultimo->siguiente= nuevo;
    else
        primero=nuevo;
    ultimo=nuevo;
    ++nNodos;
    return true;
}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::Agregar(const T & nodo1, const T & nodo2)
{
    Nodo *nodoIn=NULL;
    Nodo *nodoFin=NULL;

    nodoIn=ObtenerDir(nodo1);
    if(nodoIn == NULL) return false;
    nodoFin=ObtenerDir(nodo2);
    if(nodoFin == NULL) return false;
    if(Buscar(nodo1,nodo2)) return false;

    A aux;
    nodoIn->Agregar(nodoFin,aux);
    nodoFin->Agregar(nodoIn,aux);
    ++nAristas;
    return true;
}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::Agregar(const T & nodo1, const T & nodo2, const A  &peso)
{
    Nodo *nodoIn=NULL;
    Nodo *nodoFin=NULL;

    nodoIn=ObtenerDir(nodo1);
    if(nodoIn == NULL) return false;
    nodoFin=ObtenerDir(nodo2);
    if(nodoFin == NULL) return false;
    if(Buscar(nodo1,nodo2)) return false;

    nodoIn->Agregar(nodoFin,peso);
    nodoFin->Agregar(nodoIn,peso);
    ++nAristas;
    return true;
}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::Eliminar(const T & eNodo)
{

    Nodo *aux=ObtenerDir(eNodo);
    if(aux == NULL) return false;
    VaciarNodo(eNodo);


    if(aux!=primero)
        aux->anterior->siguiente=aux->siguiente;
    else
        primero=primero->siguiente;

    if(aux!=ultimo)
        aux->siguiente->anterior=aux->anterior;
    else
        ultimo=ultimo->anterior;

    delete aux;
    --nNodos;
    if(nNodos==0)
        primero=ultimo=NULL;
    return true;
}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::Eliminar(const T & nodo1, const T & nodo2)
{
    Nodo *nodoIn=NULL;
    Nodo *nodoFin=NULL;

    nodoIn=ObtenerDir(nodo1);
    if(nodoIn == NULL) return false;
    nodoFin=ObtenerDir(nodo2);
    if(nodoFin == NULL) return false;
    if(!Buscar(nodo1,nodo2)) return false;

    nodoIn->Eliminar(nodoFin);
    nodoFin->Eliminar(nodoIn);
    --nAristas;
    return true;

}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::Buscar(const T & eNodo) const
{
    return (ObtenerDir(eNodo) != NULL);
}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::Buscar(const T & nodo1, const T & nodo2) const
{
    Nodo *nodoIn=NULL;
    Nodo *nodoFin=NULL;

    nodoIn=ObtenerDir(nodo1);
    if(nodoIn == NULL) return false;
    nodoFin=ObtenerDir(nodo2);
    if(nodoFin == NULL) return false;

    return nodoIn->ObtenerDir(nodoFin);
}


//*************************************************************************************
template<typename T, typename A>
unsigned Grafo<T,A>::GradoDe(const T & eNodo) const
{
    Nodo *aux=ObtenerDir(eNodo);
    if(aux == NULL) throw NodoNoEncontrado();

    return aux->grado;
}


//*************************************************************************************
template<typename T, typename A>
unsigned Grafo<T,A>::NumeroDeNodos() const
{
    return nNodos;
}


//*************************************************************************************
template<typename T, typename A>
unsigned Grafo<T,A>::NumeroDeAristas() const
{
    return nAristas;
}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::VaciarNodo(const T & eNodo)
{

    Nodo *aux=ObtenerDir(eNodo);
    if(aux == NULL || aux->grado==0) return false;

    while(aux->primero != NULL) Eliminar(aux->ID, aux->primero->adyacente->ID);
    return true;
}


//*************************************************************************************
template<typename T, typename A>
bool Grafo<T,A>::VaciarGrafica()
{

    if(NumeroDeNodos() == 0) return false;
    while(primero != NULL) Eliminar(primero->ID);
    return true;
}


//*************************************************************************************
template<typename T, typename A>
void Grafo<T,A>::Imprimir(std::ostream & salida/*=std::cout*/) const
{
    Nodo *auxNodo=primero;
    typename Nodo::Arista *auxArista=NULL;

    while(auxNodo != NULL)
    {
        salida<<auxNodo->ID<<" ->{";
        auxArista=auxNodo->primero;
        while(auxArista != NULL)
        {
            salida<<auxArista->adyacente->ID<<", ";
            auxArista=auxArista->siguiente;
        }
        if(auxNodo->grado != 0)salida<<"\b\b";
        salida<<"}\n";
        auxNodo=auxNodo->siguiente;
    }
    salida<<'\n';
}


//*************************************************************************************
template<typename T, typename A>
void Grafo<T,A>::ImprimirConPesos(std::ostream & salida/*=std::cout*/) const
{
    Nodo *auxNodo=primero;
    typename Nodo::Arista *auxArista=NULL;

    salida<<'\n';
    while(auxNodo != NULL)
    {
        salida<<auxNodo->ID<<" ->{";
        auxArista=auxNodo->primero;
        while(auxArista != NULL)
        {
            salida<<auxArista->adyacente->ID<<":"<<auxArista->peso<<", ";
            auxArista=auxArista->siguiente;
        }
        if(auxNodo->grado != 0)salida<<"\b\b";
        salida<<"}\n";
        auxNodo=auxNodo->siguiente;
    }
}


//*************************************************************************************
template<typename T, typename A>
Pila<T> Grafo<T,A>::PaseoDeEuler()const
{
    if(NumeroDeNodos() == 0)throw GrafoVacio();
    Nodo *aux=primero;
    while(aux != NULL)
    {
        if(aux->grado%2 != 0) throw NoExistePaseoDeEuler();
        aux=aux->siguiente;
    }


    Grafo<T,A> gAux;
    Nodo *vc,*vp,*k;
    Pila<Nodo*> pila;
    ColaCircular<Nodo*> cola;
    typename Nodo::Arista *w;

    gAux=*this;

    //Vamos a iniciar en un nodo aleatorio
    aux=gAux.primero;
    unsigned r=rand()%gAux.NumeroDeNodos();
    for(;r != 0;--r) aux = aux->siguiente;

    vp=vc=aux;
    pila.Apilar(vp);
    cola.Encolar(vc);

    while(vc -> grado != 0 && vp->grado != 0)
    {
        w=vc->primero;
        while(w != NULL && w->adyacente->grado == 1 )
            w = w->siguiente;

        if(w != NULL)
        {
            gAux.Eliminar(vc->ID,w->adyacente->ID);
            cola.Encolar(w->adyacente);
            vc=w->adyacente;
        }

        if(vp->grado == 1)
        {
            k=vp->primero->adyacente;
            gAux.Eliminar(k->ID,vp->ID);
            pila.Apilar(k);
            vp = k;
        }
    }

    if(!pila.EstaVacia()) pila.Desapilar();
    while(!pila.EstaVacia())
    {
        cola.Encolar( pila.ConocerElemento() );
        pila.Desapilar();
    }
    Pila<T> res;
    while(!cola.EstaVacia())
    {
        res.Apilar(cola.PrimElemento()->ID);
        cola.Desencolar();
    }

    return res;
}


/*****************************************************************************************
************************************   Excepciónes   *************************************
*****************************************************************************************/
//*************************************************************************************
template <typename T, typename A>
const char * Grafo<T,A>::GrafoVacio::what() const throw()
{
    return "No hay nodos en el grafo...";
}

//*************************************************************************************
template <typename T, typename A>
const char * Grafo<T,A>::NoExistePaseoDeEuler::what() const throw()
{
    return "No existe el paseo de euler...";
}

//*************************************************************************************
template <typename T, typename A>
const char * Grafo<T,A>::NodoNoEncontrado::what() const throw()
{
    return "No existe el nodo buscado...";
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T, typename A>
typename Grafo<T,A>::Nodo * Grafo<T,A>::ObtenerDir(const T & eNodo) const
{
    Nodo *auxNodo=primero;
    while(auxNodo != NULL && auxNodo->ID != eNodo)
        auxNodo=auxNodo->siguiente;

    return auxNodo;
}


//*************************************************************************************
template<typename T, typename A>
typename Grafo<T,A>::Nodo::Arista * Grafo<T,A>::Nodo::ObtenerDir(const Nodo * ad) const
{
    Arista *auxAr=primero;
    while(auxAr != NULL && auxAr->adyacente != ad)
        auxAr=auxAr->siguiente;
    return auxAr;
}


//*************************************************************************************
template<typename T, typename A>
Grafo<T,A>::Nodo::Nodo(const T &e, Nodo * sig/*=NULL*/, Nodo * ant/*=NULL*/) :
    ID(e),grado(0),anterior(ant),siguiente(sig),primero(NULL),ultimo(NULL){}


//*************************************************************************************
template<typename T, typename A>
Grafo<T,A>::Nodo::Arista::Arista(Nodo *ad ,const A &p, Arista *aSig/*=NULL*/ , Arista *aAnt/*=NULL*/) :
    peso(p),adyacente(ad),anterior(aAnt),siguiente(aSig){}


//*************************************************************************************
template<typename T, typename A>
void Grafo<T,A>::Nodo::Agregar(Nodo *ad, const A &p)
{
    Arista *nuevo= new Arista(ad,p,NULL,ultimo);
    if(ultimo != NULL)
        ultimo->siguiente= nuevo;
    else
        primero=nuevo;
    ultimo=nuevo;
    ++grado;
}


//*************************************************************************************
template<typename T, typename A>
void Grafo<T,A>::Nodo::Eliminar(const Nodo *ad)
{
    Arista *aux=ObtenerDir(ad);

    if(aux!=primero)
        aux->anterior->siguiente=aux->siguiente;
    else
        primero=primero->siguiente;

    if(aux!=ultimo)
        aux->siguiente->anterior=aux->anterior;
    else
        ultimo=ultimo->anterior;

    delete aux;
    --grado;
    if(grado==0)
        primero=ultimo=NULL;
}

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t,typename a>
std::ostream & operator<<(std::ostream & salida,const Grafo<t,a> & grf)
{
    grf.Imprimir(salida);
    return salida;
}
