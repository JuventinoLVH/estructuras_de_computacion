#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

/* Nombre: .h
   Autor:
   Fecha:
   Descripción:
*/


#include<iostream>
#include"Utileria.h"

#define NOMBRES 202 //El número de nombres
#define APELLIDOS 102 //El número de apellidos

class Persona
{
    //*************************************************************************************
    /** \brief sobrecarga del operador <<
    *
    * \param salida el flujo de salida
    * \param p la persona a imprimir
    * \return el mismo flujo de salida
    *
    */friend std::ostream & operator<<(std::ostream & salida ,const Persona & p );

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por defaúlt, le asigna un nombre aleatorio y un tiempo de espera
    *
    */Persona();

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Devuelve el nombre de la persona
    *
    */const std::string & getNombre() const;

    //*************************************************************************************
    /** \brief Devuelve el tiempo que requiere para terminar de que la atiendan
    *
    */const double getTAtencion() const;

    //*************************************************************************************
    /** \brief Si la persona tiene algo más que hacer en el banco (Si no, que se vaya)
    * \return true si ya atendieron a la persona;
    *
    */bool getTermino() const;

    //*************************************************************************************
    /** \brief reduce el tiempo necesario para atender a la persona
    *  \param m el numero de minutos que pasan ( en un segundo )
    *
    */void disminTAtencion(double m=2.5);

private:
    std::string nombre;
    double tAtencion;
    bool termino;
 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
    std::string NombreAleatoria();
};

#endif // PERSONA_H_INCLUDED
