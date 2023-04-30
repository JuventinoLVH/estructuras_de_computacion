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
Pila<T>::Pila()
{
    tam= 0;
    tope= NULL;
}

//*************************************************************************************
template <typename T>
Pila<T>::Pila(const Pila & p)
{
    tam=0;
    tope=NULL;
    *this = p;
}

//*************************************************************************************
template <typename T>
Pila<T>::~Pila()
{
    Vaciar();
}


 /*****************************************************************************************
 *****************************       Operadores      **************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
Pila<T> & Pila<T>::operator= (const Pila & p)
{
    if(this == &p) return *this;

    this->Vaciar();
    tam= p.tam;
    Elemento * aux =p.tope, ** auxCopia = &tope;
    while(aux != NULL)
    {
        *auxCopia = new Elemento(aux->valor);
        auxCopia = &((*auxCopia)->siguiente);
        aux = aux->siguiente;
    }

    return *this;
}


 /*****************************************************************************************
 *********************************        Metodos      ************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T>
void Pila<T>::Apilar(const T & val)
{
    Elemento * nuevo = new Elemento(val, tope);
    tope = nuevo;
    ++tam;
}

//*************************************************************************************
template <typename T>
void Pila<T>::Desapilar()
{
    if(EstaVacia()) throw PilaVacia();
    Elemento * aux= tope;
    tope=tope->siguiente;
    delete aux;
    --tam;
}

//*************************************************************************************
template <typename T >
const T & Pila<T>::ConocerElemento() const
{
    if(EstaVacia()) throw PilaVacia();
    return tope->valor;
}

//*************************************************************************************
template <typename T>
bool Pila<T>::EstaVacia() const
{
    return tam==0;
}

//*************************************************************************************
template <typename T>
void Pila<T>::Vaciar()
{
    while(!EstaVacia())
    {
        Desapilar();
    }
}

//*************************************************************************************
template <typename T>
int Pila<T>::Tamano()
{
    return tam;
}

//*************************************************************************************
template <typename T>
void Pila<T>::Imprimir() const
{
    Elemento *aux = tope;
    if(EstaVacia()) {
        std::cout << "Pila Vac\241a" << std::endl;
        return;
    }
    std::cout << "Tope -> ";
    while(aux != NULL){
        std::cout << aux -> valor << ", ";
        aux = aux -> siguiente;
    }
    std::cout << "\b\b";
}


 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T >
const char * Pila<T>::PilaVacia::what() const throw()
{
    return "No hay nada";
}


 /*****************************************************************************************
 ******************        Funciones externas y amigas      *******************************
 *****************************************************************************************/

//*************************************************************************************
template <typename T >
Pila<T>::Elemento::Elemento(T val, Elemento * sig /*= null*/)
{
    valor = val;
    siguiente = sig;
}

//*************************************************************************************
template <typename t>
std::ostream & operator<<(std::ostream & salida ,const Pila<t> & p )
{
    p.Imprimir();
    return salida;

}


