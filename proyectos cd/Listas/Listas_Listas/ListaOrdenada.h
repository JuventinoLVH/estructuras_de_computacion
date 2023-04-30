#ifndef LISTADOBENLAZADA_H_INCLUDED
#define LISTADOBENLAZADA_H_INCLUDED

/* Nombre: ListaOrdenada.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 16/Mar/2021
   Descripción: Archivo de cabecera de la clase ListaOrdenada
*/

#include<iostream>
#include<stdexcept>

/** \brief Clase que simula una lista ordenada
 * \param T el tipo de la lista
 *
 */
template <typename T = int>
class ListaOrdenada
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief imprime una lista en un flujo de salida
    *
    * \param ls la lista a imprimir
    * \param salida el flujo de salida
    * \return El mismo flujo de salida
    *
    */
    template <typename t>
    friend std::ostream & operator<<(std::ostream & salida, const ListaOrdenada<t> & ls);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por defecto
    *
    */ListaOrdenada();


    //*************************************************************************************
    /** \brief Constructor de copias
    *
    */ListaOrdenada(const ListaOrdenada & ls);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~ListaOrdenada();



 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief sobrecarga del operador igual
    *
    * \param ls La lista a copiar
    * \return Una referencia a la lista
    * \exception std::bad_alloc no hay memoria para crear un elemento
    *
    */ListaOrdenada & operator= (const ListaOrdenada & ls);

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Agrega un elemento al principio de la lista
    *
    * \param val el elemento a agregar
    * \exception std::bad_alloc no hay memoria para crear un elemento
    *
    */void AgregarElemento(const T & val);

    //*************************************************************************************
    /** \brief Elimina el elemento al principio
    *
    */bool EliminarElemento(const T & val);

    //*************************************************************************************
    /** \brief Busca un elemento en la lista
    *
    * \param val el elemento a buscar
    * \return True si el elemento se encuentra en la lista, false de lo contrario
    *
    */bool Buscar(const T & val) const;


    //*************************************************************************************
    /** \brief Devuelve si la lista se encuentra vacia
    * \return true si no hay elementos en la lista, false de lo contrario
    *
    */bool EstaVacia() const;

    //*************************************************************************************
    /** \brief Devuelve el número de elementos en la lista
    *
    * \return el número de elementos en la lista
    *
    */unsigned int ObtenerTamano() const ;

    //*************************************************************************************
    /** \brief Elimina todos los elementos de la lista
    *
    */void Vaciar();

    //*************************************************************************************
    /** \brief Imprime la lista de forma ascendente(del menor al mayor)
    *
    */void ImprimirAscendente() const ;

    //*************************************************************************************
    /** \brief Imprime la lista de forma descendente(del mayor al menor)
    *
    */void ImprimirDescendente() const ;


 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/
    //*************************************************************************************
    class ListaVacia: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };

private:

    struct Elemento
    {
        T valor;
        Elemento * anterior;
        Elemento * siguiente;
        Elemento(T v, Elemento * sig=NULL, Elemento * ant=NULL);
    };

    Elemento * ultimo , * primero;
    unsigned int tam;

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Función que busca un elemento
    *
    * \param El indice del elemento
    * \return El elemento
    *
    */Elemento * ObtenerElemento(int pos);


};

#include "ListaOrdenada.tpp"

#endif // LISTADOBENLAZADA_H_INCLUDED
