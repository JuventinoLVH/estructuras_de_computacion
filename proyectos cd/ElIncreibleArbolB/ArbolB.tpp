/* Nombre: ArbolB.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 06/05/21
   Descripción: Archivo de implementación de la clase 'ArbolB'
*/

#include"ArbolB.h"


 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T, int G>
ArbolB<T,G>::ArbolB()
{
    if(G < 3) throw std::logic_error("No puede existir un arbol B con grado menor a 3...");
    raiz=NULL;


}


//*************************************************************************************
template<typename T, int G>
ArbolB<T,G>::ArbolB(const ArbolB & grf)
{
    raiz = NULL;
    if(G < 3) throw std::logic_error("No puede existir un arbol B con grado menor a 3...");
    *this=grf;
}


//*************************************************************************************
template<typename T, int G>
ArbolB<T,G>::~ArbolB()
{
    Vaciar();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T, int G>
ArbolB<T,G> & ArbolB<T,G>::operator= (const ArbolB<T,G> & grf)
{
    if(this == & grf) return *this;
    Vaciar();


    return *this;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::Agregar(const T & eNodo)
{
    Agregar(eNodo,raiz);
    if(raiz->numClaves == G)
    {
        Nodo *nuevaRaiz = new Nodo();
        Partir(nuevaRaiz,raiz,0);
        raiz=nuevaRaiz;
    }
}


//*************************************************************************************
template<typename T, int G>
bool ArbolB<T,G>::Eliminar(const T & eNodo)
{
    return Eliminar(eNodo,raiz);
}


//*************************************************************************************
template<typename T, int G>
bool ArbolB<T,G>::Buscar(const T & eNodo) const
{

}


//*************************************************************************************
template<typename T, int G>
unsigned ArbolB<T,G>::NumeroDeClaves() const
{
    return 2;
}


//*************************************************************************************
template<typename T, int G>
bool ArbolB<T,G>::Vaciar()
{


}


//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::Imprimir(Recorrido r/*=ASCENDENTE*/,std::ostream & salida/*=std::cout*/) const
{

}


/*****************************************************************************************
************************************   Excepciónes   *************************************
*****************************************************************************************/
//*************************************************************************************
template <typename T, int G>
const char * ArbolB<T,G>::ArbolBVacio::what() const throw()
{
    return "No hay nodos en el ArbolB...";
}


//*************************************************************************************
template <typename T, int G>
const char * ArbolB<T,G>::NodoNoEncontrado::what() const throw()
{
    return "No existe el nodo buscado...";
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T, int G>
ArbolB<T,G>::Nodo::Nodo()
{
    for(int i=0;i < G; ++i)
        clavez[i]=NULL;
    numClaves = 0;
}

//*************************************************************************************
template<typename T, int G>
ArbolB<T,G>::Nodo::Clave::Clave(const T &e, Nodo *de/*=NULL*/, Nodo *iz/*=NULL*/) :
        val(e),der(de),izq(iz){}


//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::Agregar(const T & eNodo, Nodo &subRaiz)
{
    if(subRaiz==NULL)
    {
        subRaiz = new Nodo();
        subRaiz->clavez[0] = new typename Nodo::Clave(eNodo);
        ++nClaves;
        ++subRaiz->numClavez;
        return;
    }
    else
    {
        int i;
        for(i=0;i<subRaiz-> numClavez && (eNodo > subRaiz->clavez[i] -> val ) ; ++i);

        //En una hoja, ninguna clave tienen hijos así que puedes revisar en cualquiera
        if(subRaiz->clavez[0] -> der == NULL)
        {
            //Lo elegante de estas lineas quema como mil soles
            typename Nodo::Clave *aMeter = new typename Nodo::Clave(eNodo);
            typename Nodo::Clave *siguiente=subRaiz->clavez[i];
            for(; i < subRaiz-> numClavez ;++i)
            {
                subRaiz->clavez[i]=aMeter;
                aMeter=siguiente;
                siguiente=subRaiz->clavez[i+1];
            }
            subRaiz->clavez[i]=aMeter;
            ++nClaves;
            ++subRaiz->numClavez;
        }
        else
        {
            Nodo *aAgregar;
            if(i==subRaiz->numClavez ) aAgregar=subRaiz->clavez[i-1]->der;
            else  aAgregar=subRaiz->clavez[i]->izq;

            Agregar(eNodo, aAgregar );
            if( aAgregar->numClavez == G )
            Partir(*this,aAgregar,i);
        }
    }
}


//*************************************************************************************
template<typename T, int G>
bool ArbolB<T,G>::Eliminar(const T & eNodo, Nodo &subRaiz)
{


}


//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::Partir(Nodo &subRaiz, Nodo & hijo, int i) const
{
    int j,tope=(G-1)/2;
    Nodo *izq=new Nodo();
    Nodo *der=new Nodo();

    for(int j=0;j < tope;++j) izq[j]=hijo->clavez[j];
    typename Nodo::Clave *aMeter = hijo->clavez[tope];
    for(int j=tope+1;j <= tope;++j) der[j-tope-1]=hijo->clavez[j];

    delete hijo; //Un minuto del silencio u.u
    aMeter->der=der;
    aMeter->izq=izq;

    //Ordenando a los hijos
    if(i-1 != 0) subRaiz->clavez[i-1]->der = izq;
    if(i != subRaiz->numClavez) subRaiz->clavez[i]->izq = der;

    //Otra vez estas lineas tan bellas, pero ahora no son tan bellas u.u
    typename Nodo::Clave *siguiente=subRaiz->clavez[i];
    for(; i < subRaiz-> numClavez ;++i)
    {
        subRaiz->clavez[i]=aMeter;
        aMeter=siguiente;
        siguiente=subRaiz->clavez[i+1];
    }
    subRaiz->clavez[i]=aMeter;
}


//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::Mezclar(Nodo &subRaiz, Nodo & hijo, int i) const
{

}


//*************************************************************************************
template<typename T, int G>
T & ArbolB<T,G>::Mayor(Nodo &subRaiz)
{
    if( (subRaiz->clavez[ subRaiz->numClavez-1 ])->der ==NULL )
        return (subRaiz->clavez[ subRaiz->numClavez-1 ]) -> val;
    else
        return Mayor((subRaiz->clavez[ subRaiz->numClavez-1 ])->der );
}


//*************************************************************************************
template<typename T, int G>
T & ArbolB<T,G>::Menor(Nodo &subRaiz)
{
    if( (subRaiz->clavez[0] )->izq ==NULL )
        return (subRaiz->clavez[0] )-> val;
    else
        return Menor((subRaiz->clavez[0])->izq );
}


//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::ImprimirA()
{

}


//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::ImprimirD()
{

}


//*************************************************************************************
template<typename T, int G>
void ArbolB<T,G>::ImprimirPN()
{
    if(nClaves==0) return;
    ColaCircular<Nodo*>cola;

    cola.Encolar(raiz);
    while(!cola.Vacia())
    {

    }
}

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t,int g>
std::ostream & operator<<(std::ostream & salida,const ArbolB<t,g> & grf)
{
    grf.Imprimir(PORNIVEL,salida);
    return salida;
}
