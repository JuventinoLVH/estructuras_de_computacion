/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


#include<iostream>
#include<exception>

#define SIN_ELEMENTOS -1

/** \brief Clase que simula una pila
*
* \param T el tipo de datos de la pila
*/template <typename T=int >
class Pila
{
 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief imprime una pila en un flujo de salida (Solo para pruebas)
    *
    * \param salida el flujo de salida
    * \param pila la pila que se quiere mostrar en el flujo de salida
    * \return El mismo flujo de salida
    *
    */
    template <typename t>
    friend std::ostream & operator<<(std::ostream & salida, const Pila<t> &pila );

public:

 /*****************************************************************************************
 ********************************** Constructores *****************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por defecto
    *
    */Pila();

    //*************************************************************************************
    /** \brief Constructor de copias
    *
    * \param p la pila a copiar
    */Pila(const Pila<T> & p);


    //*************************************************************************************
    /** \brief Destructor
    */
    ~Pila();


 /*****************************************************************************************
 *************************************   Operadores   *************************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Sobrecarga del operador '='
    *
    * \param p La pila que se quiere copiar
    * \return Una referencia a la pila a la cual se le aplica el operador '='
    *
    */Pila<T> & operator= (const Pila<T> & p);


 /*****************************************************************************************
 *********************************   Metodos y funciónes   ********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Agrega un elemento a la pila
    *
    * \param val El elemento a añadir
    */void AgregarElemento(T val);


    //*************************************************************************************
    /** \brief Elimina el último elemento agregado a la pila
     *
     */void EliminarElemento();


    //*************************************************************************************
    /** \brief función que vacía toda la pila
    *
    */void Vaciar();


    //*************************************************************************************
    /** \brief Función que devuelve el numemro de elementos en la pila
    *
    */int Tamano()const;


    //*************************************************************************************
    /** \brief Devuelve el último elemento agregado a la pila
    *
    * \return el último elemento agregado a la pila
    */const T & ConocerElemento()const;


    //*************************************************************************************
    /** \brief Función para saber si hay elementos en la pila
    *
    * \return true si no hay ningun elemento en la pila, false en cualquier otro caso
    *
    */bool EstaVacia()const;


    //*************************************************************************************
    /** \brief Función para imprimir la pila (Solo para pruebas)
    *
    */void Imprimir()const;


    //*************************************************************************************
    /** \brief Función para saber cuantos elementos le caben a la pila(Solo de prueba)
    *
    * \return el tamaño del arreglo
    */int Capacidad()const;


 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/
    //*************************************************************************************
    class PilaLlena: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };

    //*************************************************************************************
    class PilaVacia: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };

private:

    T * elemento;
    int tamano;
    int tope;


 /*****************************************************************************************
 ***********************************   Metodos privados   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Función para saber si el arreglo está lleno
     * \return Sí el arreglo esta lleno
     *
     */bool EstaLlena()const;

    //*************************************************************************************
    /** \brief Dobla el tamaño del arreglo
    *
    */void Redimensionar();


};

#include"Pila.tpp"

#endif // PILA_H_INCLUDED
