#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/* Nombre: .h
   Autor:
   Fecha:
   Descripci�n:
*/

#include<iostream>
#include<stdexcept>

template<typename T>
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
    template <typename t>
    friend std::ostream & operator<<(std::ostream & salida,const Grafo<t> & grf);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor de dos par�metros
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
    */bool Buscar(const T & eNodo);

//*************************************************************************************
    /** \brief Sobrecarga de la funci�n 'Buscar' para buscar una arista de la grafica
    *
    * \param nodo1 La etiqueta del nodo 'inicio' de la arista
    * \param nodo2 La etiqueta del nodo 'final' de la arista
    * \return True S� la arista se encuentra en la grafica, false de lo contrario
    *
    */bool Buscar(const T & nodo1, const T & nodo2);

//*************************************************************************************
    /** \brief Devuelve el grado de un nodo (El n�mero de aristas que inciden en el)
    *
    * \param eNodo La etiqueta del nodo
    * \return El grado de 'eNodo'
    * \exception ElementoNoEncontrado Si el nodo no se encuentra en la grafica
    *
    */int GradoDe(const T & eNodo);

//*************************************************************************************
    /** \brief Devuelve el n�mero de nodos en la grafica
    * \return El n�mero de nodos en la grafica
    *
    */int NumeroDeNodos();

//*************************************************************************************
    /** \brief Devuelve el n�mero de aristas en la grafica
    * \return El n�mero de aristas en la grafica
    *
    */int NumeroDeAristas();

//*************************************************************************************
    /** \brief Elimina todas las aristas incidentes a un nodo
    *
    * \param eNodo La etiqueta del nodo a despellejar
    * \return True si la operaci�n fue exitosa, false de lo contrario
    *
    */bool VaciarNodo(const T & eNodo);

//*************************************************************************************
    /** \brief Elimina todas los nodos y aristas de la grafica
    * \return True si la operaci�n fue exitosa, false de lo contrario
    *
    */bool VaciarGrafica();

//*************************************************************************************
    /** \brief Imprime un Grafo en un flujo de salida
    * \param salida El flujo de salida
    *
    */void Imprimir(std::ostream & salida=std::cout);


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
    class ElementoNoEncontrado: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:
    };

private:

    struct Nodo
    {
        T valor;
        Nodo * anterior;
        Nodo * siguiente;
        Nodo(T v, Nodo * sig=NULL, Nodo * ant=NULL);
    };
    Nodo *inicio;
    int nNodos,nAristas;

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
    //*************************************************************************************
    /** \brief Obtiene la direcci�n de un nodo
    *
    * \param eNodo La etiqueta del nodo a buscar
    * \return la direcci�n del nodo, NULL si el nodo no se encontr�
    *
    */Nodo * ObtenerDir(const T & eNodo);

};
#include"Grafo.tpp"

#endif // GRAFO_H_INCLUDED
