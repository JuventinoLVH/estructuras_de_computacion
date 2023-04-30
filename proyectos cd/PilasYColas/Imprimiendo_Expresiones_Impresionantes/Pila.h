/* Nombre: Pila.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 21/02/21
   Descripción: Archivo de cabezera de la clase pilal
*/

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


#include<iostream>
#include<stdexcept>

#define SIN_ELEMENTOS 0

/** \brief Clase que simula una pila
 *
 * \param T el tipo de daato que se guarda en la pila
 */
template <typename T=int>
class Pila
{
    //*************************************************************************************
    /** \brief imprime una pila en un flujo de salida
    *
    * \param salida el flujo de salida
    * \param p la pila a imprimir
    * \return El mismo flujo de salida
    *
    */
    template <typename t>
    friend std::ostream & operator<<(std::ostream & salida,const Pila<t> &p);

public:

 /*****************************************************************************************
 ********************************    Constructores     ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por defecto
    *
    * \exception std::bad_alloc no hay espacio en la memoria
    */explicit Pila();


    //*************************************************************************************
    /** \brief Constructor de copias
    *
    * \param pla la pila a copiar
    * \exception std::bad_alloc no hay espacio en la memoria
    */Pila(const Pila & pla);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~Pila();



 /*****************************************************************************************
 *********************************      Operadores     ************************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Sobrecarga del operador igual
    *
    * \param p la pila a copiar
    * \exception std::bad_alloc no hay espacio en la memoria
    */Pila & operator= (const Pila & p);


 /*****************************************************************************************
 *********************************        Metodos      ************************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Mete un elemento al tope de la pila
    *
    * \exception val El valor a meter
    * \exception std::bad_alloc no hay espacio en la memoria
    */void Apilar(const T & val);

    //*************************************************************************************
    /** \brief Función para conocer el tope de la pila
    *
    * \return El tope de la pila
    * \exception Pila::PilaVacia no hay elementos en la pila con los que trabajar
    */const T & ConocerElemento() const ;

    //*************************************************************************************
    /** \brief Recorre el tope de la pila
    *
    * \exception Pila::PilaVacia no hay elementos en la pila con los que trabajar
    */void Desapilar();

    //*************************************************************************************
    /** \brief Función para saber si la pila esta vacia
    *
    * \return true si el tamaño de la pila es 0, false de lo contrario
    */bool EstaVacia() const ;

    //*************************************************************************************
    /** \brief Función para conocer el tamaño de la pila
    *
    * \return el número de elementos en la pila
    */int Tamano();

    //*************************************************************************************
    /** \brief Función que quita todos los elementos de la pila
    *
    */void Vaciar();

    //*************************************************************************************
    /** \brief Imprime la pila (Solo par pruebas)
    *
    */void Imprimir() const;

  /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/
    //*************************************************************************************
    class PilaVacia: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };


private:


    struct Elemento
    {

        //*************************************************************************************
        /** \brief Constructor de dos parámetros
        *
        */Elemento(T val, Elemento * sig = NULL);

        T valor;
        Elemento *siguiente;
    };

    Elemento * tope;
    unsigned int tam;


};
#include"Pila.tpp"


#endif // PILA_H_INCLUDED
