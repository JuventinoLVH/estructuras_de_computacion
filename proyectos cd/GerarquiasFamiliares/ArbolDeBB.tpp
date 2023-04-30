/* Nombre: ArbolDeBB.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 14/04/21
   Descripción: Archivo de implementación de la clase 'ArbolDeBB'
*/

#include"ArbolDeBB.h"


 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T>
ArbolDeBB<T>::ArbolDeBB() : raiz(NULL),nNodos(0){}


//*************************************************************************************
template<typename T>
ArbolDeBB<T>::ArbolDeBB(const ArbolDeBB & abb) : raiz(NULL),nNodos(0)
{
    *this=abb;
}


//*************************************************************************************
template<typename T>
ArbolDeBB<T>::~ArbolDeBB()
{
    Vaciar();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T>
ArbolDeBB<T> & ArbolDeBB<T>::operator= (const ArbolDeBB<T> & abb)
{
    if(this == & abb) return *this;
    Vaciar();

    if(abb.raiz != NULL)
    {
        Nodo * aux;
        ColaCircular< ArbolDeBB<T>::Nodo* > cola;
        cola.Encolar(abb.raiz);
        while(!cola.EstaVacia())
        {

            aux= cola.PrimElemento();
            Agregar(aux->val);
            cola.Desencolar();

            if(aux->izq != NULL) cola.Encolar(aux->izq);
            if(aux->der != NULL) cola.Encolar(aux->der);
        }
    }


    return *this;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T>
bool ArbolDeBB<T>::Agregar(const T & eNodo)
{
    return Agregar(raiz,eNodo);
}


//*************************************************************************************
template<typename T>
bool ArbolDeBB<T>::Eliminar(const T & eNodo)
{

    try
    {
        Nodo *& subRaiz = ObtNodo(raiz,eNodo);
        Nodo * porSalir=subRaiz;
        switch(subRaiz->TNodo())
        {
            case 0:
                subRaiz = NULL;
                break;

            case 1:
                subRaiz= subRaiz->izq;
                break;

            case 2:
                subRaiz= subRaiz->der;
                break;

            case 3:
                std::cout<<"Si entra a qui llpdo";
                Nodo *& dirMayor = Mayor(subRaiz->izq);
                std::cout<<"Val may: "<<dirMayor->val;
                subRaiz->val = dirMayor->val;
                Eliminar(dirMayor);
                return true;
                break;
        }
        delete porSalir;
        --nNodos;
        return true;
    }
    catch(...)
    {
        return false;
    }


}


//*************************************************************************************
template<typename T>
bool ArbolDeBB<T>::Buscar(const T & eNodo) const
{
    Nodo *subArbol = raiz;
    while(subArbol != NULL)
    {
        if(subArbol->val == eNodo) return true;
        else
        {
            if(subArbol->val > eNodo) subArbol = subArbol->izq;
            else subArbol = subArbol->der;
        }
    }
    return false;
}


//*************************************************************************************
template<typename T>
unsigned ArbolDeBB<T>::NumeroDeNodos() const
{
    return nNodos;
}


//*************************************************************************************
template<typename T>
unsigned ArbolDeBB<T>::ObtenerAltura() const
{
    if(raiz == NULL) return 0;
    else return raiz->tam;
}


//*************************************************************************************
template<typename T>
bool ArbolDeBB<T>::PodarNodo(const T & eNodo)
{

    try
    {
        Nodo *& aux = ObtNodo(raiz,eNodo);
        PodarNodo(aux);
        return true;
    }
    catch(...)
    {
        return false;
    }



}


//*************************************************************************************
template<typename T>
bool ArbolDeBB<T>::Vaciar()
{
    if(nNodos == 0) return false;
    PodarNodo(raiz);
    return true;
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::Imprimir(Recorrido tipo /*=ASCENDENTE*/,std::ostream & salida/*=std::cout*/) const
{
    if(raiz == NULL) return;
    switch(tipo)
    {
        case ASCENDENTE:
            ImprAscendente(raiz,salida);
            break;
        case DESCENDENTE:
            ImprDescendente(raiz,salida);
            break;
        case PORNIVEL:
            ImprPorNivel(raiz,salida);
            break;
        case POSORDEN:
            ImprPosOrden(raiz,salida);
            break;
        case PREORDEN:
            ImprPreOrden(raiz,salida);
            break;
    }
    salida<<"\b,\b ";
}




/*****************************************************************************************
************************************   Excepciónes   *************************************
*****************************************************************************************/
//*************************************************************************************
template <typename T>
const char * ArbolDeBB<T>::NodoNoEncontrado::what() const throw()
{
    return "No existe el nodo buscado...";
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T>
ArbolDeBB<T>::Nodo::Nodo(const T &e, Nodo * iz/*=NULL*/, Nodo * de/*=NULL*/) :
    val(e),tam(1),der(de),izq(iz){}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::Nodo::ActAltura()
{
    unsigned subDer;
    unsigned subIzq;

    /*subDer = der == NULL ? 0:subDer =der->tam ;
    subIzq = izq == NULL ? 0:subIzq =izq->tam ; */

    if(der == NULL) subDer = 0;
    else subDer = der->tam;
    if(izq == NULL ) subIzq = 0;
    else subIzq = izq->tam;

    tam = subDer > subIzq ? subDer+1 : subIzq+1;
}


//*************************************************************************************
template<typename T>
 typename ArbolDeBB<T>::Nodo *& ArbolDeBB<T>::Mayor(Nodo *&subRaiz)
{
    if( subRaiz->der != NULL) return  Mayor(subRaiz->der);
    else return subRaiz;
}

//*************************************************************************************
template<typename T>
int ArbolDeBB<T>::Nodo::TNodo()
{
    if(der != NULL)
    {
        if(izq != NULL) return 3;
        else return 2;
    }
    else
    {
        if(izq != NULL) return 1;
        else return 0;
    }
}


//*************************************************************************************
template<typename T>
bool ArbolDeBB<T>::Agregar(Nodo *&subRaiz,const T & eNodo)
{
    bool resultado;
    if(subRaiz == NULL)
    {
        subRaiz = new Nodo(eNodo);
        ++nNodos;
        return true;
    }
    if(subRaiz->val == eNodo) return false;
    if(subRaiz->val > eNodo) resultado=Agregar(subRaiz->izq,eNodo);
    else  resultado=Agregar(subRaiz->der,eNodo);

    subRaiz->ActAltura();
    return resultado;
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::Eliminar(Nodo *&subRaiz)
{
    Nodo * porSalir=subRaiz;

    switch(subRaiz->TNodo())
    {
        case 0:
            subRaiz = NULL;
            break;

        case 1:
            subRaiz= subRaiz->izq;
            break;

        case 2:
            subRaiz= subRaiz->der;
            break;
    }

    delete porSalir;
    --nNodos;
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::PodarNodo(Nodo *&subRaiz)
{
    if(subRaiz != NULL)
    {
        PodarNodo(subRaiz->der);
        PodarNodo(subRaiz->izq);
        delete subRaiz;
        subRaiz = NULL;
        --nNodos;
    }
}


//*************************************************************************************
template<typename T>
typename ArbolDeBB<T>::Nodo *& ArbolDeBB<T>::ObtNodo(Nodo *& subRaiz , const T & eNodo)
{
    if(subRaiz != NULL )
    {
        if(subRaiz->val == eNodo) return subRaiz;
        if(subRaiz->val > eNodo) return ObtNodo(subRaiz->izq,eNodo);
        else return ObtNodo(subRaiz->der,eNodo);
    }
    throw NodoNoEncontrado();
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::ImprAscendente(Nodo *subRaiz, std::ostream & salida/*=std::cout*/)const
{
    if(subRaiz == NULL) return;
    ImprAscendente(subRaiz->izq,salida);
    salida<<subRaiz->val<<" ,";
    ImprAscendente(subRaiz->der,salida);
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::ImprDescendente(Nodo *subRaiz, std::ostream & salida/*=std::cout*/)const
{
    if(subRaiz == NULL) return;

    ImprDescendente(subRaiz->der,salida);
    salida<<subRaiz->val<<" ,";
    ImprDescendente(subRaiz->izq,salida);
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::ImprPorNivel(Nodo *subRaiz, std::ostream & salida/*=std::cout*/)const
{
    Nodo * aux;
    ColaCircular< ArbolDeBB<T>::Nodo* > cola;
    cola.Encolar(raiz);
    while(!cola.EstaVacia())
    {
        aux= cola.PrimElemento();
        cola.Desencolar();
        salida<<aux->val<<" ,";
        if(aux->izq != NULL) cola.Encolar(aux->izq);
        if(aux->der != NULL) cola.Encolar(aux->der);
    }
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::ImprPosOrden(Nodo *subRaiz, std::ostream & salida/*=std::cout*/)const
{
    if(subRaiz == NULL) return;

    ImprPosOrden(subRaiz->izq,salida);
    ImprPosOrden(subRaiz->der,salida);
    salida<<subRaiz->val<<" ,";
}


//*************************************************************************************
template<typename T>
void ArbolDeBB<T>::ImprPreOrden(Nodo *subRaiz, std::ostream & salida/*=std::cout*/)const
{
    if(subRaiz == NULL) return;

    salida<<subRaiz->val<<" ,";
    ImprPreOrden(subRaiz->izq,salida);
    ImprPreOrden(subRaiz->der,salida);
}

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t>
std::ostream & operator<<(std::ostream & salida,const ArbolDeBB<t> & abb)
{
    abb.Imprimir(POSORDEN,salida);
    return salida;
}
