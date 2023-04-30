/* Nombre: .cpp
   Autor:
   Fecha:
   Descripción:
*/

#include"Banco.h"


 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
Banco::Banco()
{
    cLibre=true;
}


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
bool Banco::cajaLibre() const
{
    return cLibre;
}


//*************************************************************************************
const Persona & Banco::PersonaEnCaja() const
{
    if(cajaLibre() == true ) throw CajasVacias();
    return perEnCaja;
}


//*************************************************************************************
void Banco::ImpCola() const
{
    ColaCircular<Persona> aux = colaCaja;
    while(!aux.EstaVacia())
    {
        std::cout<<aux.PrimElemento()<<'\n';
        aux.Desencolar();
    }
}


//*************************************************************************************
void Banco::ImprAtendidos() const
{
    ColaCircular<Persona> aux = atendidos;
    while(!aux.EstaVacia())
    {
        std::cout<<aux.PrimElemento()<<'\n';
        aux.Desencolar();
    }
}


//*************************************************************************************
void Banco::FormarPersona(const Persona &p)
{
    colaCaja.Encolar(p);
}


//*************************************************************************************
void Banco::Siguiente()
{
    if(cajaLibre()==false) throw CajasLlenas();
    if(colaCaja.EstaVacia()) return;

    cLibre=false;
    perEnCaja  = colaCaja.PrimElemento();
    colaCaja.Desencolar();

}


void Banco::AtenderEnCaja(int m/*=2.5*/)
{
    if(cajaLibre()) throw CajasVacias();

    perEnCaja.disminTAtencion(m);
    if(perEnCaja.getTermino())
    {
        atendidos.Encolar(perEnCaja);
        cLibre=true;
    }
}


 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

//*************************************************************************************
const char * Banco::CajasVacias::what() const throw()
{
    return "No hay nadie en las cajas";
}

//*************************************************************************************
const char * Banco::CajasLlenas::what() const throw()
{
    return "No hay nadie en las cajas";
}

    class CajasVacias: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:
    };

