#ifndef LISTADOBENLAZADA_H_INCLUDED
#define LISTADOBENLAZADA_H_INCLUDED

/* Nombre: .h
   Autor:
   Fecha:
   Descripción:
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

    //*************************************************************************************
    /** \brief sobrecarga del operador corchetes para R value
    *
    * \param pos la posición del elemento a obtener
    * \return una referencia constante al elemento
    * \exception ListaDobEnlazada::ListaVacia no hay elementos en la lista
    * \exception std::out_of_range índice invalido
    *
    */const T & operator[] (int pos) const ;

    //*************************************************************************************
    /** \brief sobrecarga del operador corchetes para L value
    *
    * \param pos la posición del elemento a obtener
    * \return una referencia al elemento
    * \exception ListaDobEnlazada::ListaVacia no hay elementos en la lista
    * \exception std::out_of_range índice invalido
    *
    */T & operator[] (int pos);


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
    */bool EliminarDelPrincipio();

    //*************************************************************************************
    /** \brief Elimina el elemento al final
    *
    */bool EliminarDelFinal();

    //*************************************************************************************
    /** \brief Elimina el elemento en una posición especifica
    * \param pos la posición del elemento a eliminar
    *
    */bool EliminarDePos(int pos);

    //*************************************************************************************
    /** \brief Busca un elemento en la lista
    *
    * \param val el elemento a buscar
    * \return True si el elemento se encuentra en la lista, false de lo contrario
    *
    */bool Buscar(const T & val) const;

    //*************************************************************************************
    /** \brief Busca la posición de un elemento en la lista
    *
    * \param val el elemento a buscar
    * \return la posición del elemento en la lista, -1 si no se encuentra
    *
    */int BuscarPos(const T & val) const;

    //*************************************************************************************
    /** \brief Devuelve si la lista se encuentra vacia
    * \return true si no hay elementos en la lista, false de lo contrario
    *
    */bool EstaVacia() const;

    //*************************************************************************************
    /** \brief Devuelve el primer elemento de la lista (como R value)
    *
    * \return una referencia constante al elemento
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    *
    */const T & ObtenerPrimero() const ;

    //*************************************************************************************
    /** \brief Devuelve el primer elemento de la lista (como L value)
    *
    * \return una referencia al elemento
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    *
    */T & ObtenerPrimero();

    //*************************************************************************************
    /** \brief Devuelve el último elemento de la lista (como R value)
    *
    * \return una referencia constante al elemento
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    *
    */const T & ObtenerUltimo() const ;

    //*************************************************************************************
    /** \brief Devuelve el último elemento de la lista (como L value)
    *
    * \return una referencia al elemento
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    *
    */T & ObtenerUltimo();

    //*************************************************************************************
    /** \brief Devuelve un elemento en una posición especifica (Como R value)
    *
    * \param pos la posición del elemento a obtener
    * \return una referencia constante al elemento
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    * \exception std::out_of_range índice invalido
    *
    */const T & ObtenerPos(int pos) const ;


    //*************************************************************************************
    /** \brief Devuelve un elemento en una posición especifica (Como L value)
    *
    * \param pos la posición del elemento a obtener
    * \return una referencia al elemento
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    * \exception std::out_of_range índice invalido
    *
    */T & ObtenerPos(int pos);

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
    /** \brief Imprime la lista
    *
    */void Imprimir() const ;


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

#include "ListaDobEnlazada.tpp"

#endif // LISTADOBENLAZADA_H_INCLUDED
