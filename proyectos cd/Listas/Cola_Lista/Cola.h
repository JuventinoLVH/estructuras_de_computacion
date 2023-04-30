/* Nombre: Cola.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 02/03/21
   Descripción: Archivo de cabecera de la clase Cola
*/
#ifndef Cola_H_INCLUDED
#define Cola_H_INCLUDED


#include<iostream>
#include<stdexcept>


/** \brief Clase que representa una cola
*  \param T el tipo de datos que guarda la cola
*/
template <typename T=int>
class Cola
{
    //*************************************************************************************
    /** \brief sobrecarga del operador <<
     *
     * \param salida el flujo de salida
     * \param cc la cola a imprimir
     * \return el mismo flujo de salida
     *
     */
    template <typename t>
    friend std::ostream & operator<< (std::ostream & salida , const Cola<t> & cc);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor de dos parámetros
    *
    */Cola();


    //*************************************************************************************
    /** \brief Constructor de copias
    *
    *  \param cc la cola a copiar
    *
    */Cola(const Cola & cc);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~Cola();



 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Sobrecarga del operador '='
    *
    * \param cc La cola a copiar
    * \return la cola circular
    *
    */Cola<T> & operator= (const Cola<T> & cc);


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Mete un elemento al final de la cola
    *
    * \exception std::bad_alloc ya no hay mas memoria
    *
    */void Encolar (const T & val);

    //*************************************************************************************
    /** \brief Saca el elemento al final de la cola
    *
    *  \exception Cola::ColaVacia no hay elementos en la cola
    *
    */void Desencolar();

    //*************************************************************************************
    /** \brief Devuelve el primer elemento que llego a la cola
    *
    *  \return el valor del ultimo elemento
    *  \exception Cola::ColaVacia no hay elementos en la cola
    *
    */const T & PrimElemento() const;

    //*************************************************************************************
    /** \brief Devuelve el ultimo elemento que llego a la cola
    *
    *  \return el valor del ultimo elemento
    *  \exception Cola::ColaVacia no hay elementos en la cola
    *
    */const T &  UltElemento() const;

    //*************************************************************************************
    /** \brief Sirve para saber si hay elementos en la cola
    *
    *  \return true si no hay elementos en la cola, false de lo contrario
    *
    */bool EstaVacia() const;

    //*************************************************************************************
    /** \brief Imprime la cola(Solo para pruebas)
    *
    */void Imprimir() const;

    //*************************************************************************************
    /** \brief Limpia la cola
    *
    */void Vaciar();

    //*************************************************************************************
    /** \brief Da el tamaño de la cola
    *
    *  \return el número de elementos en la cola
    *
    */unsigned int ObtenerTam() const;

 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/
    //*************************************************************************************
    class ColaVacia: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };

private:

    ListaDobEnlazada<T> lista;
 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/


};
#include "Cola.tpp"

#endif // Cola_H_INCLUDED
