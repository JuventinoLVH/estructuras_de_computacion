/* Nombre: ColaMedieval.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 18/03/21
   Descripción: archivo de cabecera de la clase ColaMedieval
*/

#ifndef COLAMEDIEVAL_H_INCLUDED
#define COLAMEDIEVAL_H_INCLUDED


#include<iostream>
#include"ColaCircular.h"
#include"PersonaMedieval.h"


/** \brief Clase que representa una cola donde los nobles tienen prioridad y el
 *            vulgo se puede tiene que esperar(si tienen hambre pues que no nazcan pobres)
 */
class ColaMedieval
{
    //*************************************************************************************
    /** \brief sobrecarga del operador <<
     *
     * \param salida el flujo de salida
     * \param cc la cola a imprimir
     * \return el mismo flujo de salida
     *
     */
    friend std::ostream & operator<< (std::ostream & salida , const ColaMedieval & cc);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por default
    *
    */ColaMedieval();


    //*************************************************************************************
    /** \brief Constructor de copias
    *  \param cc la cola a copiar
    *
    */ColaMedieval(const ColaMedieval & cc);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~ColaMedieval();



 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Sobrecarga del operador '='
    *
    * \param cc La cola a copiar
    * \return la cola circular
    * \exception std::bad_alloc ya no hay mas memoria
    *
    */ColaMedieval & operator= (const ColaMedieval & cc);


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Mete una persona al final de la cola
    * \return si se pudo encolar con exito
    *
    */bool Encolar (const PersonaMedieval & val);

    //*************************************************************************************
    /** \brief Saca la persona al final de la cola
    *  \return true si la cola no esta vacia, false de lo contrario
    *
    */bool Desencolar();

    //*************************************************************************************
    /** \brief Devuelve la primera persona que llego a la cola
    *
    *  \return la persona al inicio de la cola
    *  \exception exception::ColaCircular::ColaVacia no hay personas en la cola
    *
    */const PersonaMedieval & PrimElemento() const;

    //*************************************************************************************
    /** \brief Devuelve la ultima persona que llego a la cola
    *
    *  \return La persona al final de la cola
    *  \exception exception::ColaCircular::ColaVacia no hay personas en la cola
    *
    */const PersonaMedieval &  UltElemento() const;

    //*************************************************************************************
    /** \brief Sirve para saber si hay personas en la cola
    *
    *  \return true si no hay personas en la cola, false de lo contrario
    *
    */bool EstaVacia() const;

    //*************************************************************************************
    /** \brief Imprime la cola (De forma descendente)
    *
    * \param salida el flujo de salida
    * \exception std::bad_alloc No hay memoria para la variable aux
    */void Imprimir(std::ostream & salida=std::cout) const;

    //*************************************************************************************
    /** \brief Imprime a las personas que fueron atendidas (De forma descendente)
    *
    * \param salida el flujo de salida
    * \exception std::bad_alloc No hay memoria para la variable aux
    *
    */void ImprimirAtendidos(std::ostream & salida=std::cout) const;

    //*************************************************************************************
    /** \brief Limpia la cola(El rey se enfado de tantas peticiones D:)
    *
    */void Vaciar();

    //*************************************************************************************
    /** \brief Devuelve el total de personas en la cola
    *
    *  \return el número de personas en la cola
    *
    */unsigned int NumeroDeCiudadanos() const;

    //*************************************************************************************
    /** \brief Devuelve el total de nobles en la cola
    *
    *  \return el número de nobles en la cola
    *
    */unsigned int NumeroDenobles() const;

    //*************************************************************************************
    /** \brief Devuelve el totall de plebeyos en la cola
    *
    *  \return el número de plebeyos en la cola
    *
    */unsigned int NumeroDePlebeyos() const;

private:

    ColaCircular<PersonaMedieval> nobles,vulgo;
    ColaCircular<PersonaMedieval> atendidos;
};


#endif // COLAMEDIEVAL_H_INCLUDED
