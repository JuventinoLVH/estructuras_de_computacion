/*
Nombre:         Cliente.h
Autor(es):      Aguilar H, Escobar R, Velazquez L y Villalba J.
Fecha:          19/05/21
Descripción:    Archivo que contiene la definición de la clase Cliente.
*/

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "ArbolBA.h"

/** \brief  Representan las opciones presentadas en el men&uacute;.
 */
enum OPCIONES {SALIR, AGREGAR, ELIMINAR, VACIAR, BUSCAR, OBT_CLAVES, COPIAR, IMPRIMIR};

/** \brief      Representa un cliente que permite probar los metodos de un arbol.
 *  \tparam     T   Tipo de datos que se almacenaran en el arbol.
 */
template <typename T, unsigned grado = 5>
class Cliente{
public:
    //-------------------------------------------------------------------------------
    /** \brief Constructor por default de la clase.
     *
     */
    Cliente();
    //-------------------------------------------------------------------------------
    /** \brief Se encarga de controlar el flujo de las pruebas que realizar&aacute; el usuario.
     *
     */
    void Ejecutar();
    //-------------------------------------------------------------------------------
private:
    //Grafica para pruebas.
    ArbolBA<T,grado> pruebas;
    //-------------------------------------------------------------------------------
    /** \brief Gestiona la opci&oacute;n de agregar.
     *
     */
    void GestionAgregarElemento();
    //-------------------------------------------------------------------------------
    /** \brief Gestiona la opci&oacute;n de eliminar.
     *
     */
    void GestionEliminarElemento();
    //-------------------------------------------------------------------------------
    /** \brief Gestiona la opci&oacute;n de buscar.
     *
     */
    void GestionBuscar() const;
    //-------------------------------------------------------------------------------
    /** \brief  Gestiona la opci&oacute;n de imprimir.
     *
     *
     */
    void GestionImprimir() const;
    //-------------------------------------------------------------------------------
};

#include "Cliente.tpp"
#endif // CLIENTE_H_INCLUDED
