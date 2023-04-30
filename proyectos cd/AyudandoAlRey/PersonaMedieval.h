/* Nombre: PersonaMedieval.h
   Autor: Luis Juventino Velasquez H.
   Fecha: 18/03/21
   Descripción: Archivo de cabecera de la clase PersonaMedieval
*/

#ifndef PERSONAMEDIEVAL_H_INCLUDED
#define PERSONAMEDIEVAL_H_INCLUDED

#include<iostream>
#include"Utileria.h"

#define NOMBRES 202 //El número de nombres
#define APELLIDOS 102 //El número de apellidos


/** \brief Clase que representa a una persona con un estrato social (Una idea muy medieval)
*
*/class PersonaMedieval
{

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/


    //*************************************************************************************
    /** \brief imprime una PersonaMedieval en un flujo de salida
    *
    * \param p La persona
    * \param salida el flujo de salida
    * \return El mismo flujo de salida
    *
    */friend std::ostream & operator<<(std::ostream & salida,const PersonaMedieval & p);

public:

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Constructor por def. Crea una persona con nombre, tiempo
    *            de espera y estrato social aleatorio
    *
    */PersonaMedieval();

    //*************************************************************************************
    /** \brief Constructor para inicializar los parametros de forma manual
    *
    */PersonaMedieval(std::string nom,int tAt, bool term,bool nob);

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

    //*************************************************************************************
    /** \brief Devuelve el nombre de la persona
    *
    */const std::string & ObtNombre() const;

    //*************************************************************************************
    /** \brief Devuelve el tiempo que requiere para terminar de que la atiendan
    *
    */const double ObtTAtencion() const;

    //*************************************************************************************
    /** \brief Si la persona tiene algo más que pedir (Si no, que se vaya o le cortan la cabeza)
    * \return true si ya atendieron a la persona;
    *
    */bool Termino() const;

    //*************************************************************************************
    /** \brief Si la persona la persona es un noble o pertenece al vulgo
    * \return true si es de la nobeza, false si es un plebeyo
    *
    */bool EsNoble() const;

    //*************************************************************************************
    /** \brief reduce el tiempo necesario para atender a la persona
    *  \param m el numero de minutos que pasan ( en un segundo )
    *
    */void DisminTAtencion(double m=2.5);

private:

    std::string nombre;
    double tAtencion;
    bool termino, esNoble;

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/
    /** \brief Genera un nombre aleatoreo
    * \return un nommbre
    *
    */std::string NombreAleatoria();
};


#endif // PERSONAMEDIEVAL_H_INCLUDED
