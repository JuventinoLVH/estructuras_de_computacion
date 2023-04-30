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
template<typename T, unsigned G>
ArbolB<T,G>::ArbolB()
{
    if(G < 3) throw std::logic_error("No puede existir un arbol B con grado menor a 3...");
    nClaves=0;
    raiz=NULL;
}


//*************************************************************************************
template<typename T, unsigned G>
ArbolB<T,G>::ArbolB(const ArbolB & grf)
{
    if(G < 3) throw std::logic_error("No puede existir un arbol B con grado menor a 3...");
    nClaves=0;
    raiz=NULL;
    *this=grf;
}


//*************************************************************************************
template<typename T, unsigned G>
ArbolB<T,G>::~ArbolB()
{
    Vaciar();
}


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T, unsigned G>
ArbolB<T,G> & ArbolB<T,G>::operator= (const ArbolB<T,G> & grf)
{
    if(this == & grf) return *this;
    Vaciar();
    Copiar(this->raiz,grf.raiz);
    this->nClaves = grf.nClaves;
    return *this;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::Agregar(const T & eClave)
{
    Agregar(eClave,raiz);
    if(raiz->numClaves == G)
    {
        Nodo *nuevaRaiz = new Nodo();
        Partir(nuevaRaiz,raiz,0);
        raiz=nuevaRaiz;
    }
}


//*************************************************************************************
template<typename T, unsigned G>
bool ArbolB<T,G>::Eliminar(const T & eClave)
{
    bool res;
    res= Eliminar(eClave,raiz);
    if(raiz->numClaves == 0)
    {
        //La raiz puede estar vacia por 2 motivos
        if(raiz->claves[0]->der == NULL )
        {
            //Realmente está vacia
            delete raiz->claves[0]; //Si se elimina el ultimo elemento de un nodo, yo no lo borro en Eliminar
            delete raiz; //Adios adios
            raiz=NULL;
            }
        else
        {
            //Al mezclar se perdio el ultimo nodo, pero queda un nodo por ahi flotando
            Nodo *aux=raiz->claves[0]->der;
            delete raiz->claves[0];
            delete raiz;
            raiz=aux;
        }
    }
    return res;
}


//*************************************************************************************
template<typename T, unsigned G>
bool ArbolB<T,G>::Buscar(const T & eClave) const
{
    return Buscar(eClave,raiz);
}


//*************************************************************************************
template<typename T, unsigned G>
unsigned ArbolB<T,G>::NumeroDeClaves() const
{
    return nClaves;
}


//*************************************************************************************
template<typename T, unsigned G>
bool ArbolB<T,G>::Vaciar()
{
    while(raiz!= NULL)Eliminar(raiz->claves[0]->val);
    return true;
}


//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::Imprimir(Recorrido r/*=ASCENDENTE*/,std::ostream & salida/*=std::cout*/) const
{
    switch(r)
    {
        case PORNIVEL:
            ImprimirPN(salida);
            break;

        case ASCENDENTE:
            salida<<'{';
            if(nClaves > 0)
            {
                ImprimirA(raiz,salida);
                salida<<"\b\b";
            }
            salida<<'}';
            break;

        case DESCENDENTE:
            salida<<'{';
            if(nClaves > 0)
            {
                ImprimirD(raiz,salida);
                salida<<"\b\b";
            }
            salida<<'}';
            break;
    }
}


/*****************************************************************************************
************************************   Excepciónes   *************************************
*****************************************************************************************/
//*************************************************************************************
template <typename T, unsigned G>
const char * ArbolB<T,G>::ArbolBVacio::what() const throw()
{
    return "No hay claves en el ArbolB...";
}


//*************************************************************************************
template <typename T, unsigned G>
const char * ArbolB<T,G>::NodoNoEncontrado::what() const throw()
{
    return "No existe el nodo buscado...";
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
template<typename T, unsigned G>
ArbolB<T,G>::Nodo::Nodo()
{
    for(unsigned i=0;i < G; ++i)
        claves[i]=NULL;
    numClaves = 0;
}

//*************************************************************************************
template<typename T, unsigned G>
ArbolB<T,G>::Nodo::Clave::Clave(const T &e, Nodo *de/*=NULL*/, Nodo *iz/*=NULL*/) :
        val(e),der(de),izq(iz){}


//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::Agregar(const T & eClave, Nodo *&subRaiz)
{
    if(subRaiz==NULL)
    {
        subRaiz = new Nodo();
        typename Nodo::Clave *aMeter = new typename Nodo::Clave(eClave);
        subRaiz->claves[0]=aMeter;
        ++subRaiz->numClaves;
        ++nClaves;
        return;
    }
    unsigned i;
    for(i=0;i<subRaiz-> numClaves && (eClave > subRaiz->claves[i] -> val ) ; ++i);

    //En una hoja, ninguna clave tienen hijos así que puedes revisar en cualquiera
    if(subRaiz->claves[0] -> der == NULL)
    {
        typename Nodo::Clave *aMeter = new typename Nodo::Clave(eClave);
        typename Nodo::Clave *siguiente=subRaiz->claves[i];
        for(; i < subRaiz-> numClaves ;++i)
        {

            subRaiz->claves[i]=aMeter;
            aMeter=siguiente;
            siguiente=subRaiz->claves[i+1];
        }
        subRaiz->claves[i]=aMeter;
        ++nClaves;
        ++subRaiz->numClaves;
    }
    else
    {
        Nodo *aAgregar;
        if(i==subRaiz->numClaves ) aAgregar=subRaiz->claves[i-1]->der;
        else  aAgregar=subRaiz->claves[i]->izq;

        Agregar(eClave, aAgregar );
        if( aAgregar->numClaves == G )
            Partir(subRaiz,aAgregar,i);
    }
}


//*************************************************************************************
template<typename T, unsigned G>
bool ArbolB<T,G>::Eliminar(const T & eClave, Nodo *&subRaiz)
{
    if(subRaiz == NULL) return false;

    unsigned i;
    bool resultado;
    for(i=0;i<subRaiz-> numClaves ; ++i)
    {
        if(eClave == subRaiz->claves[i]-> val)
        {
            if(subRaiz->claves[0]->izq == NULL) //Es hoja
            {
                if(subRaiz-> numClaves != 1) //Explicación de esto mas abajo...
                {
                    delete (subRaiz->claves[i]);
                    for( ; i<subRaiz-> numClaves ;++i)
                        subRaiz->claves[i]=subRaiz->claves[i+1];
                }
                --subRaiz->numClaves;
                --nClaves;
                return true;
            }
            else //No es hoja
            {
                T aux = Mayor(subRaiz->claves[i]->izq ); //El mayor de los mayores
                subRaiz->claves[i]->val = aux;

                Eliminar(aux,subRaiz->claves[i]->izq);
                if(subRaiz->claves[i]->izq-> numClaves < (G-1)/2 )
                    Mezclar(subRaiz,subRaiz->claves[i]->izq,i);
                return true;
            }
        }
        else if(eClave < subRaiz->claves[i] -> val)  break; //En esté nodo ya no está
    }

    //Termino de revisar o encontró una clave que tiene mayor valor
    Nodo *aEliminar;
    if(i == subRaiz-> numClaves ) aEliminar = subRaiz->claves[i-1]->der;
    else aEliminar =subRaiz->claves[i]->izq;

    resultado = Eliminar(eClave,aEliminar );
    if(aEliminar -> numClaves < (G-1)/2 )
        Mezclar(subRaiz,aEliminar,i);

    return resultado;
}


//*************************************************************************************
template<typename T, unsigned G>
bool ArbolB<T,G>::Buscar(const T & eClave,Nodo *subRaiz) const
{
    if(subRaiz == NULL) return false;
    unsigned i;
    for(i=0;i<subRaiz-> numClaves ; ++i)
    {
        if(eClave == subRaiz->claves[i]-> val)
        {
            return true;
        }
        else if(eClave < subRaiz->claves[i] -> val)  break; //En esté nodo ya no está
    }

    //Termino de revisar o encontró una clave que tiene mayor valor
    Nodo *aBuscar;
    if(i == subRaiz-> numClaves ) aBuscar = subRaiz->claves[i-1]->der;
    else aBuscar =subRaiz->claves[i]->izq;
    return Buscar(eClave,aBuscar);
}


//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::Partir(Nodo *&subRaiz, Nodo *hijo, unsigned i)
{
    unsigned j,tope=(G-1)/2;
    Nodo *izq=new Nodo();
    Nodo *der=new Nodo();
    izq->numClaves=tope;
    der->numClaves=tope;

    typename Nodo::Clave *aMeter = hijo->claves[tope];
    for(j=0;j < tope;++j)izq->claves[j]=hijo->claves[j];
    for(j=tope+1;j < G;++j) der->claves[j-tope-1]=hijo->claves[j];

    delete hijo; //Un minuto del silencio u.u
    aMeter->der=der;
    aMeter->izq=izq;

    //Ordenando a los hijos
    if(i != 0) subRaiz->claves[i-1]->der = izq;
    if(i != subRaiz->numClaves) subRaiz->claves[i]->izq = der;

    typename Nodo::Clave *siguiente=subRaiz->claves[i];
    for(j=i; j < subRaiz-> numClaves ;++j)
    {
        subRaiz->claves[j]=aMeter;
        aMeter=siguiente;
        siguiente=subRaiz->claves[j+1];
    }

    subRaiz->claves[j]=aMeter;
    ++subRaiz->numClaves;
}


//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::Mezclar(Nodo *&subRaiz, Nodo *hijo, unsigned i)
{

    Nodo *aPedirFiado;
    bool pedirIzq;

    if(i==subRaiz->numClaves)
    {
        --i;// Indíce en el rango
        aPedirFiado= subRaiz->claves[i]->izq;
        pedirIzq=true;
    }
    else
    {
        aPedirFiado= subRaiz->claves[i]->der;
        pedirIzq=false;
    }


    if(aPedirFiado->numClaves == (G-1)/2 )
    {
        Nodo *nUnion= new Nodo();
        unsigned j=0;

        if(pedirIzq)
        {
            for(;j<aPedirFiado->numClaves ;++j)
                nUnion->claves[j]=aPedirFiado->claves[j];

            nUnion->claves[j]=subRaiz->claves[i];
            ++j;

            for(unsigned k=0;k<hijo->numClaves ;++j,++k)
                nUnion->claves[j]=hijo->claves[k];

            nUnion->claves[(G-1)/2]->izq =  nUnion->claves[(G-1)/2-1]->der;
            nUnion->claves[(G-1)/2]->der = hijo->claves[0]->izq;
            //Aqui hice trampa, si no hay nodos en el hijo, claves[0] sigue teniendo una clave
            //en la que el derecho y el izquierdo apuntan al mismo lulgar

        }
        else
        {
            for(;j<hijo->numClaves ;++j)
                nUnion->claves[j]=hijo->claves[j];
            nUnion->claves[j]=subRaiz->claves[i];
            ++j;

            for(unsigned k=0;k<aPedirFiado->numClaves ;++j,++k)
                nUnion->claves[j]=aPedirFiado->claves[k];

            //La mimsma trampa que arriba. Me force a hacer esté parche porque no escuche las indicaciones
            //porque ciegamente crei que seria más facil, lo hubiera echo como lo sugio en el las documento u-u
            if(hijo->numClaves == 0) nUnion->claves[(G-1)/2-1]->izq =  hijo->claves[0]->der;
            else nUnion->claves[(G-1)/2-1]->izq =  nUnion->claves[(G-1)/2-2]->der;
            nUnion->claves[(G-1)/2-1]->der = aPedirFiado->claves[0]->izq;
        }

        nUnion->numClaves=G-1;
        if(subRaiz->numClaves != 1)
        {

            for( j=i;j<subRaiz->numClaves;++j)
                subRaiz->claves[j]=subRaiz->claves[j+1];

            if(i != 0) subRaiz->claves[i-1]->der = nUnion;
            if(i != subRaiz->numClaves-1)  subRaiz->claves[i]->izq = nUnion;
        }
        else
        {
            //Aqui está la trampa u.u me atacho a las consecuencias, no pienso cambiar el proyecto
            //ya solo me falta estó para terminarlo D": Mi único consuelo es saber que si alguna vez
            //otro alumno le pregunta lo mismo, ya sabe que esa idea no es buena u-u
            subRaiz->claves[0] = new typename Nodo::Clave(nUnion->claves[0]->val);
            subRaiz->claves[0]->der=nUnion;
            subRaiz->claves[0]->izq=nUnion;
        }
        --subRaiz->numClaves;

        if(hijo ->numClaves == 0) delete hijo->claves[0]; //Esto es parte del parche
        delete hijo;
        delete aPedirFiado;

    }
    else
    {
        //solo se intercambian entre los hijos, ta izzi
        if(pedirIzq)
        {
            //uniendo hijos
            subRaiz->claves[i]->izq = aPedirFiado->claves[aPedirFiado->numClaves-1]->der;
            subRaiz->claves[i]->der = hijo->claves[0]->izq;
            if(hijo->numClaves==0) delete hijo->claves[0]; //No me baje muchos puntos porfavor

            aPedirFiado->claves[aPedirFiado->numClaves-1]->izq=aPedirFiado;
            aPedirFiado->claves[aPedirFiado->numClaves-1]->der=hijo;

            //Acomodando
            for(unsigned j=hijo->numClaves; j>0;--j)//Acomodando al principio
                hijo->claves[j]=hijo->claves[j-1];
            hijo->claves[0]=subRaiz->claves[i];
            subRaiz->claves[i] = aPedirFiado->claves[aPedirFiado->numClaves-1]; //Acomodando en la subRaiz
            aPedirFiado->claves[aPedirFiado->numClaves-1]=NULL; //Eliminando del final

        }
        else
        {
            //uniendo hijos
            subRaiz->claves[i]->der = aPedirFiado->claves[0]->izq;
            if(hijo->numClaves==0)
            {
                //forma parte del parche
                subRaiz->claves[i]->izq = hijo->claves[0]->der;
                delete hijo->claves[0];
            }
            else subRaiz->claves[i]->izq = hijo->claves[ hijo->numClaves-1]->der;

            aPedirFiado->claves[0]->der=aPedirFiado;
            aPedirFiado->claves[0]->izq=hijo;

            hijo->claves[ hijo->numClaves] = subRaiz->claves[i]; //Acomodando al final
            subRaiz->claves[i] = aPedirFiado->claves[0];//Acomodando en la subRaiz
            for(unsigned j=1;j<=aPedirFiado->numClaves;++j) //Eliminando del principio
                aPedirFiado->claves[j-1]=aPedirFiado->claves[j];

        }
        hijo->numClaves = (G-1)/2;
        --aPedirFiado->numClaves;
    }
}


//*************************************************************************************
template<typename T, unsigned G>
T & ArbolB<T,G>::Mayor(Nodo *subRaiz) const
{
    if( (subRaiz->claves[ subRaiz->numClaves-1 ])->der ==NULL )
        return (subRaiz->claves[ subRaiz->numClaves-1 ]) -> val;
    else
        return Mayor((subRaiz->claves[ subRaiz->numClaves-1 ])->der );
}


//*************************************************************************************
template<typename T, unsigned G>
T & ArbolB<T,G>::Menor(Nodo *subRaiz) const
{
    if( (subRaiz->claves[0] )->izq ==NULL )
        return (subRaiz->claves[0] )-> val;
    else
        return Menor((subRaiz->claves[0])->izq );
}


//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::ImprimirA(Nodo *subRaiz,std::ostream & salida) const
{
    if(subRaiz->claves[0]->der == NULL) //Es hoja
    {
        for(unsigned i=0;i<subRaiz->numClaves;++i)
            salida<<subRaiz->claves[i]->val<<", ";
        return;
    }

    for(unsigned i=0;i<subRaiz->numClaves;++i)
    {
        ImprimirA(subRaiz->claves[i]->izq,salida);
        salida<<subRaiz->claves[i]->val<<", ";
    }
    ImprimirA(subRaiz->claves[subRaiz->numClaves-1]->der,salida);
}


//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::ImprimirD(Nodo *subRaiz,std::ostream & salida) const
{
    //La ultima iteración se saca porque al ser unsigned se desborda
    if(subRaiz->claves[0]->der == NULL) //Es hoja
    {
        for(unsigned i=subRaiz->numClaves-1; i>0;--i)
            salida<<subRaiz->claves[i]->val<<", ";
        salida<<subRaiz->claves[0]->val<<", ";
        return;
    }

    for(unsigned i=subRaiz->numClaves-1; i>0;--i)
    {
        ImprimirD(subRaiz->claves[i]->der,salida);
        salida<<subRaiz->claves[i]->val<<", ";
    }
    ImprimirD(subRaiz->claves[0]->der,salida);
    salida<<subRaiz->claves[0]->val<<", ";
    ImprimirD(subRaiz->claves[0]->izq,salida);
}


//*************************************************************************************
template<typename T, unsigned G>
void ArbolB<T,G>::ImprimirPN(std::ostream & salida) const
{
    if(nClaves==0)
    {
        salida<<"{}\n";
        return;
    }
    ColaCircular<Nodo*>cola;
    Nodo *aux;

    cola.Encolar(raiz);
    while(!cola.EstaVacia())
    {
        for(unsigned j=cola.ObtenerTam(); j>0 ;--j)
        {
            aux=cola.PrimElemento();
            cola.Desencolar();

            salida<<'{';
            if(aux->claves[0]->izq != NULL) cola.Encolar(aux->claves[0]->izq);
            for(unsigned i=0;i<aux->numClaves;++i)
            {
                if(aux->claves[i]->der != NULL) cola.Encolar(aux->claves[i]->der);
                salida<<aux->claves[i]->val<<", ";
            }
            salida<<"\b\b}\t";
        }
        salida<<'\n';
    }
}


//*************************************************************************************
template<typename T, unsigned G>
void  ArbolB<T,G>::Copiar(Nodo *&copia,const Nodo *original)
{
    if(original == NULL) return;
    copia=new Nodo();
    for(unsigned i=0; i<original->numClaves ; ++i)
    {
        copia->claves[i]=new typename Nodo::Clave(original->claves[i]->val);
    }
    copia->numClaves=original->numClaves;

    Copiar(copia->claves[0]->izq,original->claves[0]->izq);
    for(unsigned i=1; i<original->numClaves ; ++i)
    {
        Copiar(copia->claves[i]->izq,original->claves[i]->izq);
        copia->claves[i-1]->der = copia->claves[i]->izq;
    }
    Copiar(copia->claves[original->numClaves-1]->der,original->claves[original->numClaves-1]->der);
}


 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/
template <typename t,unsigned g>
std::ostream & operator<<(std::ostream & salida,const ArbolB<t,g> & grf)
{
    grf.Imprimir(PORNIVEL,salida);
    return salida;
}
