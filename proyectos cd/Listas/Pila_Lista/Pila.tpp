/* Nombre: Pila.tpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 21/02/21
   Descripción: Archivo de implementación de la clase pila
*/



 /*****************************************************************************************
 ********************************** Constructores *****************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
Pila<T>::Pila(){}

//*************************************************************************************
template <typename T>
Pila<T>::Pila(const Pila & p)
{
    *this = p;
}

//*************************************************************************************
template <typename T>
Pila<T>::~Pila(){}


 /*****************************************************************************************
 *****************************       Operadores      **************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
Pila<T> & Pila<T>::operator= (const Pila & p)
{
    if(this == &p) return *this;
    lista = p.lista;
    return *this;
}


 /*****************************************************************************************
 *********************************        Metodos      ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
void Pila<T>::Apilar(const T & val)
{
    lista.AgregarAlPrincipio(val);
}

//*************************************************************************************
template <typename T>
void Pila<T>::Desapilar()
{
    lista.EliminarDelFinal();
}

//*************************************************************************************
template <typename T >
const T & Pila<T>::ConocerElemento() const
{
    return lista.ObtenerUltimo();
}

//*************************************************************************************
template <typename T>
bool Pila<T>::EstaVacia() const
{
    return lista.EstaVacia();
}

//*************************************************************************************
template <typename T>
void Pila<T>::Vaciar()
{
    lista.Vaciar();
}

//*************************************************************************************
template <typename T>
int Pila<T>::Tamano()
{
    return lista.ObtenerTamano();
}

//*************************************************************************************
template <typename T>
void Pila<T>::Imprimir() const
{
    std::cout<<"Pila: ";
    std::cout<<lista;
}


 /*****************************************************************************************
 ******************        Funciones externas y amigas      *******************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T >
const char * Pila<T>::PilaVacia::what() const throw()
{
    return "No hay nada";
}


//*************************************************************************************
template <typename t>
std::ostream & operator<<(std::ostream & salida ,const Pila<t> & p )
{
    salida<<"Pila ";
    salida<<p.lista;
    return salida;
}

 /*****************************************************************************************
 *************************       Funciones Auxiliares      ********************************
 *****************************************************************************************/

