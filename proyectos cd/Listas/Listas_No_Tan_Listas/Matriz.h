/* Nombre:Matriz.h
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 5/2/21
   Descripción: Archivo de cabecera de la clase matriz
*/
#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include<iostream>
#include<stdexcept>

class Matriz
{
    //*************************************************************************************
    /** \brief Multiplica un escalar por un vector
    *
    * \param n un escalar
    * \param mtz la matriz a multiplicar
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */friend Matriz operator*(double n,const Matriz & mtz);

    //*************************************************************************************
    /** \brief imprime una matriz en un flujo de salida
    *
    * \param salida el flujo de salida
    * \param mtz la matriz que se quiere mostrar en el flujo de salida
    * \return El mismo flujo de salida
    *
    */friend std::ostream & operator<<(std::ostream & salida, const Matriz &mtz);

    //*************************************************************************************
    /** \brief Lee una matriz mediante un flujo de entrada
     *
     * \param entrada el flujo de entrada
     * \param mtz la matriz que se quiere leer
     * \return El mismo flujo de entrada
     *
     */friend std::istream & operator>>(std::istream & entrada, Matriz &mtz);

public:

 /*****************************************************************************************
 ********************************** Constructores *****************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor de dos parámetros
    *
    * \param r Número de renglones
    * \param c Número de columnas
    * \exception std::Logic_error Si se intenta crear una matriz de dimensiones invalidas
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */explicit Matriz(int r=1,int c=1);

    //*************************************************************************************
    /** \brief Constructor de copias
    * \param mtz la matriz a copiar
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */Matriz(const Matriz & mtz);

    //*************************************************************************************
    /** \brief Destructor de la clase
    *
    */~Matriz();



 /*****************************************************************************************
 *****************************       Operadores      **************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Operador sobrecargado que iguala dos matrices
    *
    * \param mtz la matriz a copiar
    * \return Una referencia a la matriz a la cual se le asigno el valor (Esto permite asignacion en cascada)
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */Matriz & operator= (const Matriz & mtz);


    //*************************************************************************************
    /** \brief Operador sobrecargado que compara dos matrices
    *
    * \param mtz la matriz a comparar
    * \return Si las dos matrices son iguales
    *
    */bool operator== (const Matriz & mtz);


    //*************************************************************************************
    /** \brief Operador sobrecargado que compara dos matrices
    *
    * \param mtz la matriz a comparar
    * \return Si las dos matrices son diferentes
    *
    */bool operator!= (const Matriz & mtz);


    //*************************************************************************************
    /** \brief Suma el componente [i][j] de dos matrices
    *
    * \param mtz una de las matrices a sumar
    * \return una copia de la matriz mtz más la matriz a la cual se le aplica el operador
    * \exception std::Logic_error Si se intenta sumar dos matrices de diferentes tamaños
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */Matriz operator+(const Matriz & mtz) const ;

    //*************************************************************************************
    /** \brief Resta el componente [i][j] de dos matrices
    *
    * \param mtz una de las matrices a restar
    * \return una copia de la matriz a la cual se le aplica el operador menos la matriz 'mtz'
    * \exception std::Logic_error Si se intenta restar dos matrices de diferentes tamaños
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */Matriz operator-(const Matriz & mtz) const;

    //*************************************************************************************
    /** \brief Multiplica dos matrices
    *
    * \param mtz una de las matrices a multiplicar
    * \return una copia de el producto de la matriz a la cual se le aplica el operador por la matriz 'mtz'
    * \exception std::Logic_error Si las matrices no tienen las dimenciones correctas
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */Matriz operator*(const Matriz & mtz) const;

    //*************************************************************************************
    /** \brief Multiplica una matriz por un escalar
    *
    * \param n Un escalar
    * \return una copia de la matriz a la cual se le aplica el operador por el escalar 'n'
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */Matriz operator*(double n) const;

    //*************************************************************************************
    /** \brief regresa un arreglo de punteros
    *
    * \param i un indice
    * \return una referencia constante al arrego correspondiente al renglon 'i' de la matriz(R value)
    * \exception std::Out_of_range Si el indice esta fuera del tamaño de la matriz
    *
    */const double * operator[](int i) const;

    //*************************************************************************************
    /** \brief regresa el arreglo de punteros indicado
    *
    * \param i un indice
    * \return una referencia al arrego correspondiente al renglon 'i' de la matriz(L value)
    * \exception std::Out_of_range Si el indice esta fuera del tamaño de la matriz
    *
    */double * operator[](int i);



 /*****************************************************************************************
 *********************************        Metodos      ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief calcula la matriz transpuesta de la matriz
    *
    * \return una copia del resultado
    * \exception std::bad_alloc si no se queda espacio para la matriz
    *
    */Matriz Tranpuesta() const;

    //*************************************************************************************
    /** \brief Calcula la matriz inversa de la matriz
    *
    * \return una copia del resultado
    * \exception std::bad_alloc si no se queda espacio para la matriz
    * \exception std::logic_error si no tiene inversa
    *
    */Matriz Inversa() const;

    //*************************************************************************************
    /** \brief cambia la dimension de la matriz, trunca el resultado o rellena con 0 dependiendo
    *
    * \param r el nuevo numero de renglones
    * \param c el nuevo numero de columnas
    * \return Una copia de la matriz a la cual se le aplico la función
    * \exception std::bad_alloc si no se queda espacio para la matriz
    * \exception std::Logic_error Si las dimenciones de la matriz son negativas
    *
    */
    Matriz CambiarDimension(unsigned int r,unsigned int c);

private:

    unsigned int reng,col;
    double **matriz;

};


#endif // MATRIZ_H_INCLUDED
