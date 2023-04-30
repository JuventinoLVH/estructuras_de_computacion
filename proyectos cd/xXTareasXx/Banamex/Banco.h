#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

/* Nombre: .h
   Autor:
   Fecha:
   Descripción:
*/

#include<stdexcept>
#include<iostream>
#include "ColaCircular.h"
#include "Persona.h"

class Banco
{

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por defaúlt
    *
    */Banco();


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Devuelve el estado de la caja
    * \return true si la caja está libre, false de lo contrario
    *
    */bool cajaLibre() const;

    //*************************************************************************************
    /** \brief Devuelve la persona en la caja
    * \return la persona en la caja
    *
    */const Persona & PersonaEnCaja() const;

    //*************************************************************************************
    /** \brief Imprime a las personas en la cola (De forma descendente )
    *
    */void ImpCola() const;

    //*************************************************************************************
    /** \brief Imprime a las personas atendidas (De forma descendente )
    *
    */void ImprAtendidos() const;

    //*************************************************************************************
    /** \brief Forma a un persona en la cola por atender
    * \param p la persona a formar
    *
    */void FormarPersona(const Persona &p);

    //*************************************************************************************
    /** \brief Mueve una persona de 'colaCaja' a 'perEnCaja'
    *
    */void Siguiente();

    //*************************************************************************************
    /** \brief Atiende a la persona que está en la caja
    *  \param m el numero de minutos que pasan ( en un segundo )
    *
    */void AtenderEnCaja(int m=2.5);


 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/
    //*************************************************************************************
    class CajasLlenas: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:
    };

    //*************************************************************************************
    class CajasVacias: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:
    };


private:

    Persona perEnCaja;
    ColaCircular<Persona> colaCaja;
    ColaCircular<Persona> atendidos;
    bool cLibre;
};


#endif // BANCO_H_INCLUDED
