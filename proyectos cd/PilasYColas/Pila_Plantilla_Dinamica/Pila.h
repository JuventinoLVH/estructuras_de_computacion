/* Nombre:.cpp
   Autor:
   Fecha:
   Descripci�n:
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
 *********************************   Metodos y funci�nes   ********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Agrega un elemento a la pila
    *
    * \param val El elemento a a�adir
    */void AgregarElemento(T val);


    //*************************************************************************************
    /** \brief Elimina el �ltimo elemento agregado a la pila
     *
     */void EliminarElemento();


    //*************************************************************************************
    /** \brief funci�n que vac�a toda la pila
    *
    */void Vaciar();


    //*************************************************************************************
    /** \brief Funci�n que devuelve el numemro de elementos en la pila
    *
    */int Tamano()const;


    //*************************************************************************************
    /** \brief Devuelve el �ltimo elemento agregado a la pila
    *
    * \return el �ltimo elemento agregado a la pila
    */const T & ConocerElemento()const;


    //*************************************************************************************
    /** \brief Funci�n para saber si hay elementos en la pila
    *
    * \return true si no hay ningun elemento en la pila, false en cualquier otro caso
    *
    */bool EstaVacia()const;


    //*************************************************************************************
    /** \brief Funci�n para imprimir la pila (Solo para pruebas)
    *
    */void Imprimir()const;


    //*************************************************************************************
    /** \brief Funci�n para saber cuantos elementos le caben a la pila(Solo de prueba)
    *
    * \return el tama�o del arreglo
    */int Capacidad()const;


 /*****************************************************************************************
 ************************************   Excepci�nes   *************************************
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
    /** \brief Funci�n para saber si el arreglo est� lleno
     * \return S� el arreglo esta lleno
     *
     */bool EstaLlena()const;

    //*************************************************************************************
    /** \brief Dobla el tama�o del arreglo
    *
    */void Redimensionar();


};

#include"Pila.tpp"

#endif // PILA_H_INCLUDED
