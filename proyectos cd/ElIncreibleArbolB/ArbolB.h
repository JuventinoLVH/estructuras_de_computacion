/* Nombre: ArbolB.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 06/05/21
   Descripción: Archivo de cabecera de la clase 'ArbolB'
*/

#ifndef ArbolB_H_INCLUDED
#define ArbolB_H_INCLUDED

#include<iostream>
#include<stdexcept>
#include"ColaCircular.h"

//*************************************************************************************
enum Recorrido
{
    ASCENDENTE,
    DESCENDENTE,
    PORNIVEL,
};


//****************************************************************************************
/** \brief Clase que representa a una arbol balanceado
 *
 * \param T El tipo de las claves(Una clave es un subValor del nodo)
 * \param G el grado del arbol (No debe ser menor a 3)
 *
 */
template<typename T= int , int G= 5 >
class ArbolB
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Imprime un ArbolB en un flujo de salida
    *
    * \param Salida El flujo de salida
    * \return El mismo flujo de salida
    *
    */
    template <typename t,int g>
    friend std::ostream & operator<<(std::ostream & salida,const ArbolB<t,g> & grf);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por default
    *  \exception std::logic_error No se puede crear un arbol con grado menor a 3
    *
    */ArbolB();


    //*************************************************************************************
    /** \brief Constructor de copias
    * \exception std::bad_alloc No hay memoria para el ArbolB
    * \exception std::logic_error No se puede crear un arbol con grado menor a 3
    *
    */ArbolB(const ArbolB & grf);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~ArbolB();



 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Sobrecarga de operador '='
    *
    * \param grf El ArbolB a copiar
    * \return Una referencia al ArbolB
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */ArbolB & operator= (const ArbolB & grf);

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Agrega una clave al arbol(Pueden ser valores repetidos :D)
    *
    * \param eNodo La etiqueta de la clave
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */void Agregar(const T & eNodo);

    //*************************************************************************************
    /** \brief Elimina una clave del arbol
    *
    * \param eNodo La etiqueta de la clave a eliminar
    * \return True Sí borro algo, false de lo contrario
    *
    */bool Eliminar(const T & eNodo);

    //*************************************************************************************
    /** \brief Busca una clave en el arbol
    *
    * \param eNodo La etiqueta de la clave a buscar
    * \return True Sí la clave se encuentra en el arbol, false de lo contrario
    *
    */bool Buscar(const T & eNodo) const;

    //*************************************************************************************
    /** \brief Devuelve el número de claves del arbol
    * \return El número de claves en el arbol
    */unsigned NumeroDeClaves()const;

    //*************************************************************************************
    /** \brief Limpia el arbol
    * \return True si elimino algo, false de lo contrario
    *
    */bool Vaciar();

    //*************************************************************************************
    /** \brief Imprime un ArbolB en un flujo de salida
    * \param Salida El flujo de salida
    *
    */void Imprimir(Recorrido r=PORNIVEL,std::ostream & salida=std::cout)const;


/*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

    //*************************************************************************************
    class ArbolBVacio: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };

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
        struct Clave
        {
            /*****************************************************************************************
            **********************************   Constructores    ************************************
            *****************************************************************************************/
            //*************************************************************************************
            /** \brief Constructor de la estructura 'Nodo'
             *
             * \param e Etiqueta del nodo
             * \param de El hijo derecho
             * \param iz El hijo izquierdo
             *
             */Clave(const T &e, Nodo *de=NULL, Nodo *iz=NULL);

             T val;
             Nodo *der, *izq;
        };
        /*****************************************************************************************
        **********************************   Constructores    ************************************
        *****************************************************************************************/
        //*************************************************************************************
        /** \brief Constructor por defecto
         *
         */Nodo();

         //No se ocupa un destructor de la clase porque 'En teoria' solo se elimina un nodo cuando
         //los datos del arreglo ya se guardaron en otro

        /*****************************************************************************************
        **************************************   Atributos   *************************************
        *****************************************************************************************/
        Clave (*clavez)[G];
        unsigned numClaves;
    };

 /*****************************************************************************************
 **************************************   Atributos   *************************************
 *****************************************************************************************/
    Nodo *raiz;
    unsigned nClaves;

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Parte al hijo de un nodo(Esto solo pasa al agregar)
    *
    * \param subRaiz El padre del nodo a partir
    * \param hijo El hijo a partir (Ahora si se enojo el papa D: )
    * \param i Indice la clave con el hijo a partir
    * \exception std::bad_alloc No hay memoria para las operaciones
    *
    */void Partir(Nodo &subRaiz, Nodo & hijo, int i) const;

    //*************************************************************************************
    /** \brief Mezcla los hijos de un nodo(Esto solo pasa al eliminar)
    *
    * \param subRaiz El padre del nodo a partir
    * \param hijo El hijo a partir (Ahora si se enojo el papa D: )
    * \param i Indice la clave con el hijo a partir
    * \exception std::bad_alloc No hay memoria para las operaciones
    *
    */void Mezclar(Nodo &subRaiz, Nodo & hijo, int i) const;

    //*************************************************************************************
    /** \brief Agrega una clave al arbol(Pueden ser valores repetidos :D)
    *
    * \param eNodo La etiqueta de la clave
    * \param subRaiz la sub raiz en donde se agregará la clave
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */void Agregar(const T & eNodo, Nodo &subRaiz);

    //*************************************************************************************
    /** \brief Elimina una clave del arbol
    *
    * \param eNodo La etiqueta de la clave a eliminar
    * \param subRaiz la sub raiz en donde se eliminará la clave
    * \return True Sí borro algo, false de lo contrario
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */bool Eliminar(const T & eNodo,  Nodo &subRaiz);

    //*************************************************************************************
    /** \brief Busca el mayor de todos los elementos en un subArbol
    *
    * \param subRaiz la raiz del subArbol
    * \return El valor del mayor de los menores
    *
    */T & Mayor(Nodo &subRaiz);

    //*************************************************************************************
    /** \brief Busca el menor de todos los elementos en un subArbol
    *
    * \param subRaiz la raiz del subArbol
    * \return El valor del mayor de los menores
    *
    */T & Menor(Nodo &subRaiz);

    //*************************************************************************************
    /** \brief Imprime el arbol de forma ascendente
    *
    */void ImprimirA();

    //*************************************************************************************
    /** \brief Imprime el arbol de forma descendente
    *
    */void ImprimirD();

    //*************************************************************************************
    /** \brief Imprime el arbol por niveles
    *
    */void ImprimirPN();

};
#include"ArbolB.tpp"

#endif // ArbolB_H_INCLUDED
