/* Nombre: Expresion.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 28/Feb/2020
   Descripción: Archivo de cabecera de la clase Expresion
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

/** \brief Clase que represnta una expresión aritmética(Los números solo pueden tener números y punto décimal)

*/
class Expresion
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief imprime la expresión aritmética
    *
    * \param e la expresón a imprimir
    * \param salida el flujo de salida
    * \return El mismo flujo de salida
    *
    */friend std::ostream & operator<<(std::ostream & salida,const Expresion & e);

    //*************************************************************************************
    /** \brief Lee una expresión aritmetica
     *
     * \param e la expresión a leer
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
    /** \brief Constructor que convierte una cadena en una expresión
    *
    * \param cad la cadena a convertir
    */Expresion(const std::string & cad);



 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Captura la expresión aritmética
    *
    *  \param entrada el flujo de entrada
    *
    */void Capturar();

    //*************************************************************************************
    /** \brief Imprime la expresión aritmética
    *
    *  \param salida el flujo de salida
    *
    */void Imprimir(std::ostream & salida= std::cout) const;

    //*************************************************************************************
    /** \brief Imprime la expresión en notación pos fija( o polaco Inversa). Los números
    *           tienen una ',' al final
    *
    * \exception Pila::SyntaxError si la sintaxis de la expresión no es correcta
    *
    */void ImprimirPolacoInverso() const;

    //*************************************************************************************
    /** \brief Devuelve el valor el valor de la expresión aritmética
    *
    * \return El valor de la expresión aritmética
    * \exception Pila::SyntaxError si la sintaxis de la expresión no es correcta
    * \exception Pila::logic_error si se divide entre 0
    *
    */double Evaluar() const;

    //*************************************************************************************
    /** \brief Verifica que la sintaxis de la expresión sea correcta
    *
    * \return true si la expresión esta bien escrita, false de lo contrario
    */bool EsValida() const;


  /*****************************************************************************************
 *************************************   Excepciones   ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Error que expresa un error en la sintaxis de la expresión
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
    /** \brief Verifica si la expresión fija tiene los corchetes balanceados
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
    /** \brief Verifica si un caracter es el signo de una operación ( +, -, /, *, ^)
    *
    * \param c el caracter a verificar
    * \return true si 'c' es un operador, false de lo contrario
    *
    */bool simbOperador(char c) const;

    //*************************************************************************************
    /** \brief Verifica si un caracter es un número
    *
    * \param c el caracter a verificar
    * \return true si 'c' es un número, false de lo contrario
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
    /** \brief Realiza una operación con 2 números
    *
    * \param  n1 el número a la derecha
    * \param  n2 el número a la izquierda
    * \param op el caracter correspondiente al operando
    * \return El resultado de la operación
    *
    */double RealizarOperacion(double n1, double n2, char op) const;

};


#endif // EXPRESION_H_INCLUDED
