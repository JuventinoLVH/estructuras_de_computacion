/* Nombre: Expresion.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 28/Feb/2020
   Descripci�n: Archivo de cabecera de la clase Expresion
*/

#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

#include<cstdlib>
#include<iostream>
#include<stdexcept>
#include<math.h>
#include<string>
#include<limits>
#include <conio.h>
#include <stdio.h>

#include"Pila.h"

/** \brief Clase que represnta una expresi�n aritm�tica(Los n�meros solo pueden tener n�meros y punto d�cimal)

*/
class Expresion
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief imprime la expresi�n aritm�tica
    *
    * \param e la expres�n a imprimir
    * \param salida el flujo de salida
    * \return El mismo flujo de salida
    *
    */friend std::ostream & operator<<(std::ostream & salida,const Expresion & e);

    //*************************************************************************************
    /** \brief Lee una expresi�n aritmetica
     *
     * \param e la expresi�n a leer
     * \param entrada el flujo de entrada
     * \return El mismo flujo de entrada
     *
     */friend std::istream & operator>>(std::istream & entrada, Expresion & e);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por default
    *
    */Expresion();

    //*************************************************************************************
    /** \brief Constructor que convierte una cadena en una expresi�n
    *
    * \param cad la cadena a convertir
    */Expresion(const std::string & cad);



 /*****************************************************************************************
 ********************************   Metodos y funci�nes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Captura la expresi�n aritm�tica
    *
    *  \param entrada el flujo de entrada
    *
    */void Capturar();

    //*************************************************************************************
    /** \brief Imprime la expresi�n aritm�tica
    *
    *  \param salida el flujo de salida
    *
    */void Imprimir(std::ostream & salida= std::cout) const;

    //*************************************************************************************
    /** \brief Imprime la expresi�n en notaci�n pos fija( o polaco Inversa). Los n�meros
    *           tienen una ',' al final
    *
    * \exception Pila::SyntaxError si la sintaxis de la expresi�n no es correcta
    *
    */void ImprimirPolacoInverso() const;

    //*************************************************************************************
    /** \brief Devuelve el valor el valor de la expresi�n aritm�tica
    *
    * \return El valor de la expresi�n aritm�tica
    * \exception Pila::SyntaxError si la sintaxis de la expresi�n no es correcta
    * \exception Pila::logic_error si se divide entre 0
    *
    */double Evaluar() const;

    //*************************************************************************************
    /** \brief Verifica que la sintaxis de la expresi�n sea correcta
    *
    * \return true si la expresi�n esta bien escrita, false de lo contrario
    */bool EsValida() const;


  /*****************************************************************************************
 *************************************   Excepciones   ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Error que expresa un error en la sintaxis de la expresi�n
    *
    */class SyntaxError: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:
    };

private:

    std::string exprFija,exprPosFija;
    bool exprValida;
    double valExpr;

 /*****************************************************************************************
 *******************************  Metodos/Funciones privados  *****************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Revisa si la sintaxsis es correcta y guarda el resultado en 'exprValida'
    *
    */void Validar();

    //*************************************************************************************
    /** \brief Calcula la forma en pos fijo y guarda el resultado en 'exprPosFija'
    *
    */void Polacolizar();

    //*************************************************************************************
    /** \brief Verifica si la expresi�n fija tiene los corchetes balanceados
    *
    * \return true si los corchetes estan balanceados, false de lo contrario
    */bool CorchetesValanceados() const;

    //*************************************************************************************
    /** \brief Verifica si un caracter es un signo de apertura
    *
    * \param c el caracter a verificar
    * \param true si 'c' es un signo de apertura, false de lo contrario
    *
    */bool simbAgrAb(char c) const;

    //*************************************************************************************
    /** \brief Verifica si un caracter es un signo de cierre
    *
    * \param c el caracter a verificar
    * \return true si 'c' es un signo de cierre, false de lo contrario
    *
    */bool simbAgrCer(char c) const;

    //*************************************************************************************
    /** \brief Verifica si un caracter es el signo de una operaci�n ( +, -, /, *, ^)
    *
    * \param c el caracter a verificar
    * \return true si 'c' es un operador, false de lo contrario
    *
    */bool simbOperador(char c) const;

    //*************************************************************************************
    /** \brief Verifica si un caracter es un n�mero
    *
    * \param c el caracter a verificar
    * \return true si 'c' es un n�mero, false de lo contrario
    *
    */bool simbNumero(char c) const;

    //*************************************************************************************
    /** \brief Verifica si un caracter es el simboo '+' o '-'
    *
    * \param c el caracter a verificar
    * \return true si 'c' es '+' p '-', false de lo contrario
    *
    */bool simbMasMenos(char c) const;

    //*************************************************************************************
    /** \brief Devuelve la prioridad de un simbolo
    *
    * \param c el caracter a evaluar
    * \return La prioridad del operador
    *
    */int  Prioridad(char c) const;

    //*************************************************************************************
    /** \brief Verifica si un signo de abertura es del mismo tipo que el de cierre
    *
    * \param abertura un caracter de apertur ( (,[ o { )
    * \param cerradura un caracter de cierre ( ),] o } )
    * \return true si 'abertura' es del mismo grupo que 'cerradura', false de lo contrario
    *
    */bool mismoGrupo(char abertura , char cerradura) const;

    //*************************************************************************************
    /** \brief Realiza una operaci�n con 2 n�meros
    *
    * \param  n1 el n�mero a la derecha
    * \param  n2 el n�mero a la izquierda
    * \param op el caracter correspondiente al operando
    * \return El resultado de la operaci�n
    *
    */double RealizarOperacion(double n1, double n2, char op) const;

};


#endif // EXPRESION_H_INCLUDED
