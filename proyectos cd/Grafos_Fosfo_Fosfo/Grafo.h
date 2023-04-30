/* Nombre: Grafo.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 04/04/21
   Descripci�n: Archivo de cabecera de la clase 'Grafo'
*/

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include<iostream>
#include<stdexcept>

/** \brief Clase que representa a una grafica (No una digrafica)
 *
 * \param T El tipo de el nodo
 * \param A El tipo de el peso de la arista
 *
 */
template<typename T= std::string , typename A= std::string >
class Grafo
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Imprime un Grafo en un flujo de salida
    *
    * \param Salida El flujo de salida
    * \return El mismo flujo de salida
    *
    */
    template <typename t,typename a>
    friend std::ostream & operator<<(std::ostream & salida,const Grafo<t,a> & grf);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por default
    *
    */Grafo();


    //*************************************************************************************
    /** \brief Constructor de copias
    * \exception std::bad_alloc No hay memoria para el grafo
    *
    */Grafo(const Grafo & grf);


    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~Grafo();



 /*****************************************************************************************
 ************************************    Operadores    ************************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief Sobrecarga de operador '='
    *
    * \param grf El grafo a copiar
    * \return Una referencia al grafo
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */Grafo & operator= (const Grafo & grf);

 /*****************************************************************************************
 ********************************   Metodos y funci�nes   *********************************
 *****************************************************************************************/

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Agregar' para a�adir un nodo a la grafica(sin repeticiones)
    *
    * \param eNodo La etiqueta del nodo
    * \return True si el nodo no est� repetido, false de lo contario
    * \exception std::bad_alloc No hay memoria para el nodo
    *
    */bool Agregar(const T & eNodo);

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Agregar' para a�adir una arista(sin repeticiones)
    *
    * \param nodo1 La etiqueta del nodo 'inicio' de la arista
    * \param nodo2 La etiqueta del nodo 'final' de la arista
    * \return True si la arista no est� repetido, false de lo contario
    * \exception std::bad_alloc No hay memoria para la arista
    *
    */bool Agregar(const T & nodo1, const T & nodo2);

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Agregar' para a�adir una arista(con peso)
    *
    * \param nodo1 La etiqueta del nodo 'inicio' de la arista
    * \param nodo2 La etiqueta del nodo 'final' de la arista
    * \return True si la arista no est� repetido, false de lo contario
    * \exception std::bad_alloc No hay memoria para la arista
    *
    */bool Agregar(const T & nodo1, const T & nodo2,const A  &peso);

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Eliminar' para eliminar un nodo de la grafica
    *
    * \param eNodo La etiqueta del nodo a eliminar
    * \return True S� la operaci�n fue exitosa, false de lo contrario
    *
    */bool Eliminar(const T & eNodo);

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Eliminar' para eliminar una arista de la grafica
    *
    * \param nodo1 La etiqueta del nodo 'inicio' de la arista
    * \param nodo2 La etiqueta del nodo 'final' de la arista
    * \return True S� la operaci�n fue exitosa, false de lo contrario
    *
    */bool Eliminar(const T & nodo1, const T & nodo2);

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Buscar' para Buscar un nodo de la grafica
    *
    * \param eNodo La etiqueta del nodo a buscar
    * \return True S� el nodo se encuentra en la grafica, false de lo contrario
    *
    */bool Buscar(const T & eNodo) const;

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Buscar' para buscar una arista de la grafica
    *
    * \param nodo1 La etiqueta del nodo 'inicio' de la arista
    * \param nodo2 La etiqueta del nodo 'final' de la arista
    * \return True S� la arista se encuentra en la grafica, false de lo contrario
    *
    */bool Buscar(const T & nodo1, const T & nodo2)const;

//*************************************************************************************
    /** \brief Devuelve el grado de un nodo (El n�mero de aristas que inciden en el)
    *
    * \param eNodo La etiqueta del nodo
    * \return El grado de 'eNodo'
    * \exception ElementoNoEncontrado Si el nodo no se encuentra en la grafica
    *
    */unsigned GradoDe(const T & eNodo)const;

//*************************************************************************************
    /** \brief Devuelve el n�mero de nodos en la grafica
    * \return El n�mero de nodos en la grafica
    *
    */unsigned NumeroDeNodos()const;

//*************************************************************************************
    /** \brief Devuelve el n�mero de aristas en la grafica
    * \return El n�mero de aristas en la grafica
    *
    */unsigned NumeroDeAristas()const;

//*************************************************************************************
    /** \brief Elimina todas las aristas incidentes a un nodo
    *
    * \param eNodo La etiqueta del nodo a despellejar
    * \return True si elimino algo, false de lo contrario
    *
    */bool VaciarNodo(const T & eNodo);

//*************************************************************************************
    /** \brief Elimina todas los nodos y aristas de la grafica
    * \return True si elimino algo, false de lo contrario
    *
    */bool VaciarGrafica();

//*************************************************************************************
    /** \brief Imprime un Grafo en un flujo de salida
    * \param Salida El flujo de salida
    *
    */void Imprimir(std::ostream & salida=std::cout)const;

//*************************************************************************************
    /** \brief Imprime un Grafo(con todo y pesos) en un flujo de salida NOTA
    * \param Salida El flujo de salida
    *
    */void ImprimirConPesos(std::ostream & salida=std::cout)const;


/*****************************************************************************************
 ************************************   Excepci�nes   *************************************
 *****************************************************************************************/

    //*************************************************************************************
    class GrafoVacio: public std::exception
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
        struct Arista
        {
            /*****************************************************************************************
            **********************************   Constructores    ************************************
            *****************************************************************************************/

            //*************************************************************************************
            /** \brief Constructor para la estructura 'Arista'
            *
            * \param ad Nodo adyacente (el Nodo al otro lado de la arista)
            * \param p Peso de la arista
            * \param aSig Arista siguiente
            * \param aAnt Arista anterior
            *
            */Arista(Nodo *ad ,const A &p, Arista *aSig=NULL, Arista *aAnt=NULL );

            /*****************************************************************************************
            **************************************   Atributos   *************************************
            *****************************************************************************************/
            A peso;
            Nodo *adyacente;
            Arista *anterior;
            Arista *siguiente;
        };

        /*****************************************************************************************
        **********************************   Constructores    ************************************
        *****************************************************************************************/
        //*************************************************************************************
        /** \brief Constructor de la estructura 'Nodo'
         *
         * \param e Etiqueta del nodo
         * \param sig Nodo siguiente
         * \param ant Nodo anterior
         *
         */
        Nodo(const T &e, Nodo *sig=NULL, Nodo *ant=NULL);

        /*****************************************************************************************
        ********************************   Metodos y funci�nes   *********************************
        *****************************************************************************************/
        //*************************************************************************************
        /** \brief Funci�n que agrega una arista a un nodo
        *
        * \param ad El nodo al otro lado de la Arista
        * \param p El peso o etiqueta de la Arista
        *
        */void Agregar(Nodo *nAdy, const A &p);

        //*************************************************************************************
        /** \brief Funci�n que elimina una arista de un nodo
        * \param nAdy El nodo al otro lado de la arista
        *
        */void Eliminar(const Nodo *nAdy);

        //*************************************************************************************
        /** \brief Obtiene la direcci�n de una de las arista adyacente al nodo
        *
        * \param eNodo La etiqueta del nodo adyacente
        * \return La direcci�n de la arista, NULL si el nodo no se encontr�
        *
        */ Arista * ObtenerDir(const Nodo *ad) const;

        /*****************************************************************************************
        **************************************   Atributos   *************************************
        *****************************************************************************************/
        T ID;
        unsigned grado;
        Nodo * anterior;
        Nodo * siguiente;
        Arista * primero;
        Arista * ultimo;

    };

 /*****************************************************************************************
 **************************************   Atributos   *************************************
 *****************************************************************************************/
    Nodo *primero;
    Nodo *ultimo;
    unsigned nNodos,nAristas;

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Obtiene la direcci�n de un nodo
    *
    * \param eNodo La etiqueta del nodo a buscar
    * \return La direcci�n del nodo, NULL si el nodo no se encontr�
    *
    */Nodo * ObtenerDir(const T &eNodo) const;

};
#include"Grafo.tpp"

#endif // GRAFO_H_INCLUDED
