/* Nombre: ArbolDeBB.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 14/04/21
   Descripción: Archivo de cabecera de la clase ArbolDeBB
*/

#ifndef ARBOLDEBB_H_INCLUDED
#define ARBOLDEBB_H_INCLUDED

#include<iostream>
#include<stdexcept>
#include"ColaCircular.h"


//*************************************************************************************
enum Recorrido
{
    ASCENDENTE,
    DESCENDENTE,
    PORNIVEL,
    PREORDEN,
    POSORDEN
};

//*************************************************************************************

/** \brief Clase que representa a un arbol (Sin elementos repetidos)
 * \param T El tipo de el nodo
 */
template<typename T=int>
class ArbolDeBB
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Imprime una arbol en un flujo de salida
    *
    * \param abb El arbol a imprimir
    * \param salida El flujo de salida
    * \return El mismo flujo de salida
    *
    */
    template<typename t>
    friend std::ostream & operator<<(std::ostream & salida, const ArbolDeBB<t> &abb);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor de copias
    *
    */ArbolDeBB();


    //*************************************************************************************
    /** \brief Constructor de copias
    * \exception std::bad_alloc No hay memoria para el arbol
    *
    */ArbolDeBB(const ArbolDeBB & abb);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~ArbolDeBB();



 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Sobrecarga de operador '='
    *
    * \param abb El arbol a copiar
    * \return Una referencia al arbol
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */ArbolDeBB & operator= (const ArbolDeBB & abb);


 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

 //*************************************************************************************
    /** \brief Agrega un nodo al arbol
    *
    * \param eNodo La etiqueta del nodo
    * \return True si el nodo no está repetido, false de lo contario
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */bool Agregar(const T & eNodo);

//*************************************************************************************
    /** \brief Elimina un nodo de el arbol
    *
    * \param eNodo La etiqueta del nodo a eliminar
    * \return True Sí la operación fue exitosa, false de lo contrario
    *
    */bool Eliminar(const T & eNodo);

//*************************************************************************************
    /** \brief Busca un nodo en el arbol
    *
    * \param eNodo La etiqueta del nodo a buscar
    * \return True Sí el nodo se encuentra en el arbol, false de lo contrario
    *
    */bool Buscar(const T & eNodo) const;

//*************************************************************************************
    /** \brief Devuelve el número de nodos en el arbol
    * \return El número de nodos en el arbol
    *
    */unsigned NumeroDeNodos()const;

//*************************************************************************************
    /** \brief Devuelve la altura del arbol
    * \return La altura del arbol
    *
    */unsigned ObtenerAltura()const;

//*************************************************************************************
    /** \brief Elimina todas los nodos y también elimina a toda su descendencia
    *
    * \param eNodo la etiqueta del nodo a podar
    * \return True si elimino algo, false de lo contrario
    *
    */bool PodarNodo(const T & eNodo);

//*************************************************************************************
    /** \brief Elimina todas los nodos en el arbol
    * \return True si elimino algo, false de lo contrario
    *
    */bool Vaciar();

//*************************************************************************************
    /** \brief Imprime un arbol en un flujo de salida
    *
    * \param tipo criterio con el cual se imprimirá el arbol
    * \param Salida El flujo de salida
    *
    */void Imprimir(Recorrido tipo = POSORDEN , std::ostream & salida=std::cout)const;


/*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

    //*************************************************************************************
    class NodoNoEncontrado: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:
    };
private:

    struct Nodo
    {
        //*************************************************************************************
        /** \brief Constructor de la estructura 'Nodo'
        *
        * \param e Etiqueta del nodo
        * \param tam altura del subArbol con raiz en el nodo
        * \param izq hijo izquierdo
        * \param der hijo derecho
        *
        */Nodo(const T &e, Nodo *iz=NULL, Nodo *de=NULL);
        T val;
        unsigned tam;
        Nodo *der,*izq;

        //*************************************************************************************
        /** \brief Actualiza la altrua del subArbol con raiz en el nodo
        *
        */void ActAltura();


        //*************************************************************************************
        /** \brief Devuelve el tipo de el nodo
        * \return 0 si el nodo es hoja, 1 si solo tiene hijo izquierdo, 2 si tiene hijo
        *            derecho y 3 si tiene 2 hijos
        *
        */int TNodo();

    };
    Nodo *raiz;
    unsigned nNodos;
 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
//*************************************************************************************
    /** \brief Agrega un nodo al arbol
    *
    * \param subRaiz La raiz del subArbol en donde se realizará la operación
    * \param eNodo La etiqueta del nodo
    * \param A La altura de la subRaiz
    * \return True si el nodo no está repetido, false de lo contario
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */bool Agregar(Nodo *&subRaiz,const T & eNodo);

//*************************************************************************************
    /** \brief Elimina la raiz de un subArbol (NOTA: está función solo se llama en un solo caso)
    * \param subRaiz la raiz del subArbol
    *
    */void Eliminar(Nodo *& subRaiz);

//*************************************************************************************
    /** \brief Devuelve el mayor elemento de un subArbol con raiz en el nodo
    * \param subRaiz raiz del subArbol
    * \return una referencia al nodo mayor de un subArbol con raiz en el nodo
    *
    */Nodo *& Mayor(Nodo *&subRaiz);

//*************************************************************************************
    /** \brief Elimina todas los nodos y también elimina a toda su descendencia
    * \param subRaiz la raiz del subArbol a podar
    *
    */void PodarNodo(Nodo *& subRaiz);

//*************************************************************************************
    /** \brief Función para obtener un nodo
    *
    * \param subRaiz la raiz del sub arbol
    * \param eNodo La etiqueta del hijo
    * \return Una referencia al padre de el nodo
    * \exception std::exception::NodoNoEncontrado
    *
    */Nodo *& ObtNodo(Nodo *&subRaiz,const T & eNodo);

//*************************************************************************************
    /** \brief Imprime un arbol de forma ascendente
    *
    * \param subRaiz La raiz del subArbol en donde se realizará la operación
    * \param Salida El flujo de salida
    *
    */void ImprAscendente(Nodo *subRaiz, std::ostream & salida=std::cout)const;

//*************************************************************************************
    /** \brief Imprime un arbol de forma descendente
    *
    * \param subRaiz La raiz del subArbol en donde se realizará la operación
    * \param Salida El flujo de salida
    *
    */void ImprDescendente(Nodo *subRaiz, std::ostream & salida=std::cout)const;

//*************************************************************************************
    /** \brief Imprime un arbol por niveles
    *
    * \param subRaiz La raiz del subArbol en donde se realizará la operación
    * \param Salida El flujo de salida
    *
    */void ImprPorNivel(Nodo *subRaiz, std::ostream & salida=std::cout)const;

//*************************************************************************************
    /** \brief Imprime un arbol en preOrden
    *
    * \param tipo criterio con el cual se imprimirá el arbol
    * \param Salida El flujo de salida
    *
    */void ImprPreOrden(Nodo *subRaiz, std::ostream & salida=std::cout)const;

//*************************************************************************************
    /** \brief Imprime un arbol en posOrden
    *
    * \param tipo criterio con el cual se imprimirá el arbol
    * \param Salida El flujo de salida
    *
    */void ImprPosOrden(Nodo *subRaiz, std::ostream & salida=std::cout)const;
};
#include "ArbolDeBB.tpp"

#endif // ARBOLDEBB_H_INCLUDED
