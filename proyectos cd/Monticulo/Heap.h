/* Nombre: heap.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 25/04/21
   Descripción: Archivo de cabecera de la clase Heap
*/

#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include<iostream>
#include<stdexcept>

//*************************************************************************************
/** \brief Criterio para un heap mínimo
*
* \param a Un elemento
* \param b Otro elemento
* \return Si el elemento a es menor al elemento b
*
*/template <typename T>
bool minimo(const T &a, const T &b)
{
    return a <= b;
}
//*************************************************************************************
/** \brief Criterio para un heap máximo
*
* \param a Un elemento
* \param b Otro elemento
* \return Si el elemento a es mayor al elemento b
*
*/template <typename T>
bool maximo(const T &a, const T &b)
{
    return a >= b;
}


//*************************************************************************************
/** \brief Clase que representa a un heap
 *
 * \param criterio Si el heap es máximo o mínimo
 * \param T El tipo de el nodo
 *
 */
template<typename T=int, bool (*criterio)(const T &a, const T &b) = &minimo>
class Heap
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Imprime una heap en un flujo de salida
    *
    * \param hp El heap a imprimir
    * \param salida El flujo de salida
    * \return El mismo flujo de salida
    *
    */
    template<typename t , bool (*cr)(const t &a, const t &b)>
    friend std::ostream & operator<<(std::ostream & salida, const Heap<t,cr> &hp);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor de copias
    * \exception std::bad_alloc No hay memoria para el heap
    *
    */Heap();


    //*************************************************************************************
    /** \brief Constructor de copias
    * \exception std::bad_alloc No hay memoria para el heap
    *
    */Heap(const Heap & hp);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~Heap();



 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Sobrecarga de operador '='
    *
    * \param hp El heap a copiar
    * \return Una referencia al heap
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */Heap & operator= (const Heap & hp);


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
    /** \brief Agrega un nodo al heap
    *
    * \param eNodo La etiqueta del nodo
    * \return True si ls operación fue exitosa
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */bool Agregar(const T & eNodo);

//*************************************************************************************
    /** \brief Elimina el elemento menor del heap
    * \return True Sí la operación fue exitosa, false de lo contrario
    *
    */bool Eliminar();

//*************************************************************************************
    /** \brief Devuelve el frente del heap
    *
    * \return El elemento al frente
    * \exception std::bad_alloc::HeapVacio No hay elementos
    *
    */T ObtenerFrente() const;

//*************************************************************************************
    /** \brief Función para conocer el estado del heap
    * \return True si no hay elementos en el heap, false de lo contrario
    *
    */bool EstaVacio()const;

//*************************************************************************************
    /** \brief Devuelve el número de nodos en el heap
    * \return El número de nodos en el heap
    *
    */int NumeroDeNodos()const;

//*************************************************************************************
    /** \brief Elimina todas los nodos en el heap
    * \return True si elimino algo, false de lo contrario
    *
    */bool Vaciar();

//*************************************************************************************
    /** \brief Imprime un heap en un flujo de salida (Solo para pruebas)
    *
    * \param tipo criterio con el cual se imprimirá el heap
    * \param Salida El flujo de salida
    *
    */void Imprimir( std::ostream & salida=std::cout)const;


//*************************************************************************************
    /** \brief Devuelve el número de nodos en el heap (Solo para pruebas)
    * \return La capacidad del heap
    *
    */int ObtenerCap()const;


 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/
//**************************************************************************************
    class HeapVacio: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };


private:

    T *monticulo;
    int tope;
    int capacidad;

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
    /** \brief Empuja un nodo hacia arriba
    *
    */void EArriba();

//*************************************************************************************
    /** \brief Redimencion el arreglo
    *
    */void Red();

//*************************************************************************************
    /** \brief Empuja un nodo hacia abajo
    *
    */void EAbajo();

};
#include "Heap.tpp"

#endif // HEAP_H_INCLUDED
