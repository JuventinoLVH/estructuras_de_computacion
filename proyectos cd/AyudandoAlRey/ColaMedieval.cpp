/* Nombre: ColaMedieval.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 18/03/21
   Descripción: Archivo de implementación de la clase ColaMedieval
*/

#include"ColaMedieval.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
ColaMedieval::ColaMedieval(){}


//*************************************************************************************
ColaMedieval::ColaMedieval(const ColaMedieval & cc)
{
    *this = cc;
}


//*************************************************************************************
ColaMedieval::~ColaMedieval(){} //las colas se destruyen por si mismas


 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/

//*************************************************************************************
ColaMedieval & ColaMedieval::operator= (const ColaMedieval & cc)
{
    if(this == &cc) return *this;

    Vaciar();
    nobles=cc.nobles;
    vulgo=cc.vulgo;

    return *this;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/
//*************************************************************************************
bool ColaMedieval::Encolar (const PersonaMedieval & val)
{
    try
    {
        if(val.EsNoble())
            nobles.Encolar(val);
        else
            vulgo.Encolar(val);
    }
    catch(...)
    {
        return false;
    }
    return true;
}


//*************************************************************************************
bool ColaMedieval::Desencolar()
{
    if(EstaVacia() ) return false;

    if(NumeroDenobles() != 0)
    {
        atendidos.Encolar(nobles.PrimElemento());
        nobles.Desencolar();
    }
    else
    {
        atendidos.Encolar(vulgo.PrimElemento());
        vulgo.Desencolar();
    }
    return true;
}


//*************************************************************************************
const PersonaMedieval & ColaMedieval::PrimElemento() const
{
    if(NumeroDenobles() != 0)
        return nobles.PrimElemento();
    else
        return vulgo.PrimElemento();
}


//*************************************************************************************
const PersonaMedieval &  ColaMedieval::UltElemento() const
{
    if(NumeroDePlebeyos() != 0)
        return vulgo.UltElemento();
    else
        return nobles.UltElemento();
}

//*************************************************************************************
bool ColaMedieval::EstaVacia() const
{
    return vulgo.EstaVacia() && nobles.EstaVacia();
}


//*************************************************************************************
void ColaMedieval::Imprimir(std::ostream & salida/*=std::cout*/) const
{
    ColaCircular<PersonaMedieval> aux;
    aux = nobles;

    while(!aux.EstaVacia() )
    {
        salida<<aux.PrimElemento()<<'\n';
        aux.Desencolar();
    }

    aux=vulgo;
    while(!aux.EstaVacia() )
    {
        salida<<aux.PrimElemento()<<'\n';
        aux.Desencolar();
    }
}

//*************************************************************************************
void ColaMedieval::ImprimirAtendidos(std::ostream & salida/*=std::cout*/) const
{
    ColaCircular<PersonaMedieval> aux;
    aux = atendidos;

    salida<<'\n';
    while(!aux.EstaVacia() )
    {
        salida<<aux.PrimElemento()<<'\n';
        aux.Desencolar();
    }

}

//*************************************************************************************
void ColaMedieval::Vaciar()
{
    nobles.Vaciar();
    vulgo.Vaciar();
}


//*************************************************************************************
unsigned int ColaMedieval::NumeroDePlebeyos() const
{
    return vulgo.ObtenerTam();
}


//*************************************************************************************
unsigned int ColaMedieval::NumeroDenobles() const
{
    return nobles.ObtenerTam();
}


//*************************************************************************************
unsigned int ColaMedieval::NumeroDeCiudadanos() const
{
    return NumeroDenobles()+NumeroDePlebeyos();
}


 /*****************************************************************************************
 *********************************   Funciones Amigas  ************************************
 *****************************************************************************************/
//*************************************************************************************
std::ostream & operator<<(std::ostream & salida ,const ColaMedieval & cc )
{
    cc.Imprimir(salida);
    return salida;
}
