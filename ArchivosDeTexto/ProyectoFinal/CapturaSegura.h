/*
Nombre:         CapturaSegura.tpp
Autor(es):      Aguilar H, Escobar R, Velazquez L y Villalba J.
Fecha:          19/05/21
Descripción:    Archivo que contiene la función plantilla para caturar un dato.
*/
#ifndef CAPTURASEGURA_H_INCLUDED
#define CAPTURASEGURA_H_INCLUDED

//***************************************************************************************************
/** \brief  Funci&oacute;n (plantilla) que captura el valor de una variable de forma segura.
 *
 * \param &a        Direcci&oacute;n en memoria de la variable a la que se le desea asignar un valor proporcionado por el usuario.
 * \param mensaje   Mensaje que vera el usuario para la captura del dato.
 * \tparam T1  Tipo del valor a capturar.
 * \exception  std::runtime_error   En caso de que ocurra un flujo del programa.
 */
template <typename T1>
void CapturaSegura(T1 &a, const char mensaje[] = "");
//***************************************************************************************************

#include "CapturaSegura.tpp"
#endif // CAPTURASEGURA_H_INCLUDED
