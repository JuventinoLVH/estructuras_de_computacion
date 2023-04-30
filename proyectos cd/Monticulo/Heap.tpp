/* Nombre: Heap.tpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 25/04/21
   Descripción: Archivo de implementación de la clase 'Heap'
*/

#include"Heap.h"


 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T, bool (*criterio)(const T &a, const T &b) >
Heap<T,criterio>::Heap() : monticulo(),tope(-1),capacidad(31)
{
    monticulo = new T[31];
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
Heap<T,criterio>::Heap(const Heap & heap) : monticulo(),tope(-1),capacidad(31)
{
    monticulo = new T[31];
    *this=heap;
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
Heap<T,criterio>::~Heap()
{
    Vaciar();
    delete monticulo;
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
Heap<T,criterio> & Heap<T,criterio>::operator= (const Heap<T,criterio> & heap)
{
    if(this == & heap) return *this;
    Vaciar();

    for(int tope=0;tope<heap.tope;++tope)
        monticulo[tope]=heap.monticulo[tope];


    return *this;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
bool Heap<T,criterio>::Agregar(const T & e)
{
    if(tope >= capacidad-1 ) Red();
    monticulo[++tope]=e;

    EArriba();
    return true;

}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
bool Heap<T,criterio>::Eliminar()
{
    if(tope == -1) return false;
    monticulo[0]=monticulo[tope];
    --tope;

    EAbajo();
    return true;
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
T Heap<T,criterio>::ObtenerFrente() const
{
    if(tope==-1) throw HeapVacio();
    return monticulo[0];
}

//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
bool Heap<T,criterio>::EstaVacio() const
{
    if(tope==-1) return true;
    return false;
}

//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
int Heap<T,criterio>::NumeroDeNodos() const
{
    return tope+1;
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
int Heap<T,criterio>::ObtenerCap() const
{
    return capacidad;
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
bool Heap<T,criterio>::Vaciar()
{
    if(tope == -1) return false;
    tope=-1;
    return true;
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
void Heap<T,criterio>::Imprimir(std::ostream & salida/*=std::cout*/) const
{
    salida<<'{';
    for(int i=0;i<=tope;++i)
        salida<<monticulo[i]<<" ,";

    if(tope!=-1) salida<<"\b\b";
    salida<<"} ";
}

 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
const char * Heap<T,criterio>::HeapVacio::what() const throw()
{
    return "Heap vac\24o";
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
void Heap<T,criterio>::EArriba()
{
    T aux;
    int pad;
    int posAct=tope;
    while(posAct >= 0)
    {
        pad = (posAct-1)/2;
        if(monticulo[posAct] != monticulo[pad] &&
            criterio(monticulo[posAct],monticulo[pad]))
        {
            aux=monticulo[pad];
            monticulo[pad]=monticulo[posAct];
            monticulo[posAct]=aux;
            posAct = pad;
        }
        else break;
    }
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
void Heap<T,criterio>::EAbajo()
{
    T aux;
    int posAct=0;
    int hjoD,hjoI;
    while(posAct < tope)
    {
        hjoI= (posAct*2)+1;
        hjoD = (posAct*2)+2;
        if(hjoI > tope) hjoI =-1;
        if(hjoD > tope) hjoD =-1;

        if(hjoI == -1) break;// Si no tiene izquierdo, tampoco tiene derecho
        else
        {
            if(hjoD == -1 || criterio(monticulo[hjoI] , monticulo[hjoD]))
            {
                if(criterio(monticulo[hjoI] , monticulo[posAct]) )
                {

                    aux=monticulo[hjoI];
                    monticulo[hjoI]=monticulo[posAct];
                    monticulo[posAct]=aux;
                    posAct=hjoI;
                }
                else break;
            }
            else
            {
                if(criterio(monticulo[hjoD] , monticulo[posAct]) )
                {
                    aux=monticulo[hjoD];
                    monticulo[hjoD]=monticulo[posAct];
                    monticulo[posAct]=aux;
                    posAct=hjoD;
                }
            }
        }
    }
}


//*************************************************************************************
template<typename T , bool (*criterio)(const T &a, const T &b)>
void Heap<T,criterio>::Red()
{
    T * aux = new T [capacidad*2 +1]; //<<<<------------------------------------------------Esta función regresa un error----
    for(int i=0;i<=tope;++i)
        aux[i]= monticulo[i];
    delete [] monticulo;
    monticulo=aux;
    capacidad= capacidad*2 +1;
}


 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template<typename t , bool (*cr)(const t &a, const t &b)>
std::ostream & operator<<(std::ostream & salida,const Heap<t,cr> & hp)
{
    hp.Imprimir(salida);
    return salida;
}
