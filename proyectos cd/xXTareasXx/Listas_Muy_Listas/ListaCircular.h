/* Nombre: ListaCircular.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 24/03/2021
   Descripción: Archivo de implementación de la clase ListaCircular
   (Note que el proyecto que llama Listas_Muy_listas porque esta listra trabaja con cabeza)
*/

#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include<iostream>
#include<stdexcept>

/** \brief Clase que simula una lista circular
 * \param T el tipo de dato a guardar
 */
template <typename T=int>
class ListaCircular
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
    friend std::ostream & operator<<(std::ostream & salida, const ListaCircular<t> & ls);



public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por defecto
    *
    */ListaCircular();


    //*************************************************************************************
    /** \brief Constructor de copias
    *
    */ListaCircular(const ListaCircular & ls);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~ListaCircular();



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
    */ListaCircular & operator= (const ListaCircular & ls);


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Agrega un elemento adelante de la cabeza
    *
    * \param val el elemento a agregar
    * \exception std::bad_alloc no hay memoria para crear un elemento
    *
    */void Agregar(const T & val);

    //*************************************************************************************
    /** \brief Elimina el elemento adelante de  la cabeza
    *
    * \return El elemento eliminado
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    *
    */T Eliminar(); //No debe ser una referencia

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
    /** \brief Mueve la cabeza a la derecha
    * \return true si la operación fue exitosa, false de lo contrario
    *
    */bool Avanzar();

    //*************************************************************************************
    /** \brief Mueve la cabeza a la izquierda
    * \return true si la operación fue exitosa, false de lo contrario
    *
    */bool Retroceder();

    //*************************************************************************************
    /** \brief Devuelve el elemento en la cabeza
    *
    * \return una referencia constante al elemento
    * \exception ListaSimple::ListaVacia no hay elementos en la lista
    *
    */const T & ObtenerCabeza() const ;

    //*************************************************************************************
    /** \brief Devuelve el número de elementos en la lista
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
    */void Imprimir(std::ostream & salida=std::cout) const ;

    //*************************************************************************************
    /** \brief Elimina la primera ocurrencia de un elemento
    *
    * \param val el elemento a eliminar
    * \return True si la función eliminó un elemento
    *
    */bool EliminarPriOcurrencia(const T & val);

    //*************************************************************************************
    /** \brief Elimina la primera ocurrencia de un elemento
    *
    * \param val el elemento a eliminar
    * \return True si la función eliminó por lo menos un elemento
    *
    */bool EliminarTodaOcurrencia(const T & val);


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

    Elemento * cabeza;
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

    //*************************************************************************************
    /** \brief Elimina el elemento en la cabeza y avanaza la cabeza a la derecha
    *
    */void EliminarCab();
};

#include"ListaCircular.tpp"


#endif // LISTACIRCULAR_H_INCLUDED
