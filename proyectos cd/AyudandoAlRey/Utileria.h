/* Nombre: Utileria.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 18/03/21
   Descripción: Archivo de cabecera de las funciónes de utileria
*/
#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <limits>
#include <fstream>




//*************************************************************************************************************************
enum Color{
    NEGRO, /**< Color negro */
    AZUL, /**< Color azul fuerte */
    VERDE, /**< Color verde oscuro */
    AGUAMARINA, /**< Color azul verde */
    ROJO, /**< Color rojo oscuro */
    PURPURA, /**< Color morado */
    AMARILLO, /**< Color amarillo */
    GRISCLARO, /**< Color gris claro */
    GRIS, /**< Color gris oscuro */
    AZULCLARO, /**< Color azul cielo */
    VERDECLARO, /**< Color verde claro */
    AGUAMARINACLARO, /**< Color azul verde claro */
    ROJOCLARO, /**< Color rojo claro */
    MAGENTA, /**< Color rosa fuerte */
    AMARILLOCLARO, /**< Color amarillo claro */
    BLANCO /**< Color blanco */
};

//*************************************************************************************************************************
enum estadoCursor
{
    APAGADO, ENCENDIDO
};

//*************************************************************************************************************************
enum modoCursor
{
    MINI = 5, NORMAL = 20, SOLIDO = 80
};



//*************************************************************************************************************************
/** \brief Función que captura de forma segura un número entero
 *
 * \param solicitud Mensaje de solicitud para la captura
 *
 * \return Entero capturado
 */
int CapturaEntero(const char solicitud []);


//*************************************************************************************************************************
/** \brief Corrigue un caracter con tilde y otro tipo de caracteres
 * \param A la cadena a normalizar
 *
 */
void NormalizarCadena(char *cadena);

//*************************************************************************************************************************
/** \brief Corrigue las letras mayusculas de un nómbre
 * \param A una caracter
 */
void NormalizarNombre(std::string & nombre);

//*************************************************************************************************************************
/** \brief Establece el color de fondo y texto para impresi&oacute;n. Despu&eacute;s de establecer el color, lo que se imprima aparecer&aacute; con esta combinaci&oacute;n de colores.
 *
 * \param colorEst El color a establecer. Es una combinaci&oacute;n del color de fondo y texto
 *
 * \pre El color a establecer debe ser no negativo y una combinaci&oacute;n del color de fondo y texto que se obtiene con la f&oacute;rmula:
 *		(Color de fondo)(16) + (Color de texto). El color del fondo y texto son valores de la enumeraci&oacute;n tipo Color.
 */
void EstablecerColor(WORD colorEst);


//*************************************************************************************************************************
/** \brief Establece el color de fondo y texto para impresi&oacute;n. Despu&eacute;s de establecer el color, lo que se imprima aparecer&aacute; con esta combinaci&oacute;n de colores.
 *
 * \param colorFondo El color de fondo del texto a imprimir
 * \param colorTexto Color del texto a imprimir
 *
 * \pre Tanto el color del fondo y del texto deben ser no negativos. Son valores de la enumeraci&oacute;n tipo Color.
 */
 void EstablecerColor(Color colorFondo, Color colorTexto);


//*************************************************************************************************************************
/** \brief Obtiene el color de fondo y texto actual de la ventana de despliegue.
 *
 * \return Valor que combina el color de fondo y texto establecidos actualmente en la ventana de despliegue. Est&aacute; compuesto por: (Color de fondo)(16) + (Color de texto)
 *		   Para obtener los colores separados se divide en m&oacute;dulo el valor devuelto entre 16, este es el color de texto.
 * 		   Se divide entre 16 (divisi&oacute;n entera), este es el color de fondo.
 */
WORD ObtenerColorOriginal();


//*************************************************************************************************************************
/** \brief Mueve el cursor a la posici&oacute;n indicada
 *
 * \param x Posici&oacute;n en x a la que se mueve el cursor
 * \param y Posici&oacute;n en y a la que se mueve el cursor
 *
 * \pre Las posiciones (x,y) deben ser no negativas. La posici&oacute;n m&iacute;nima es cero.
 */
void gotoxy(SHORT x,SHORT y);


//*************************************************************************************************************************
/**
 * \brief Establece el tama&ntilde;o de la ventana de ejecuci&oacute;n.
 *
 * \param ancho Valor entero para el ancho de la ventana.
 * \param alto Valor entero para el alto de la ventana.
 **/
void EstablecerTamVentana(SHORT ancho, SHORT alto);


//*************************************************************************************************************************
/** \brief
 *
 * \param estado Si el cursor está apagado o encendido
 * \param NORMAL si es pequeño, grande o normal
 *
 */
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);


#endif // UTILERIA_H_INCLUDED
