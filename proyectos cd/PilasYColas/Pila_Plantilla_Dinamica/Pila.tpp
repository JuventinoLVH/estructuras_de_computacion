/* Nombre: Pila.tpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 14/02/21
   Descripción: Archivo de implementacion de la clase Pila
*/


//*************************************************************************************
template <typename T >
Pila<T>::Pila()
{
    tope=-1;
    tamano=2;
    elemento= new T[tamano];
}

//*************************************************************************************
template <typename T >
Pila<T>::Pila(const Pila<T> & p)
{
    tope=-1;
    elemento=NULL;
    tamano=0;
    *this=p;
}

//*************************************************************************************
template <typename T >
void Pila<T>::Vaciar()
{
    tope=-1;
}

//*************************************************************************************
template <typename T >
Pila<T>::~Pila()
{
    delete [] elemento;
}

//*************************************************************************************
template <typename T >
Pila<T> & Pila<T>::operator= (const Pila<T> & p)
{
    if(&p == this) return *this;

    if(elemento != NULL)
        delete [] elemento;

    tope = p.tope;
    tamano = p.tamano;
    elemento = new T[tamano];
    for(int i=0;i<=tope; ++i)
        elemento[i]=p.elemento[i];

    return *this;
}

//*************************************************************************************
template <typename T >
const T & Pila<T>::ConocerElemento()const
{
    if(EstaVacia() ) throw PilaVacia();
    return elemento[tope];
}

//*************************************************************************************
template <typename T >
void Pila<T>::AgregarElemento(T val)
{
    if( EstaLlena() ) Redimensionar();

    elemento[++tope]=val;
}

//*************************************************************************************
template <typename T >
bool Pila<T>::EstaLlena() const
{
    return (tope == tamano-1);
}

//*************************************************************************************
template <typename T >
bool Pila<T>::EstaVacia() const
{
    return tope == SIN_ELEMENTOS;
}

//*************************************************************************************
template <typename T >
int Pila<T>::Tamano()const
{
    return tope+1;
}

//*************************************************************************************
template <typename T >
void Pila<T>::EliminarElemento()
{
    if(EstaVacia() ) throw PilaVacia();
    tope--;
}

//*************************************************************************************
template <typename T >
void Pila<T>::Imprimir() const
{
    std::cout<<"<";
    for(int i=0;i<=tope;++i)
        std::cout<<elemento[i]<<", ";

    if(tope != SIN_ELEMENTOS) std::cout<<"\b\b";
    std::cout<<'>';
}

//*************************************************************************************
template <typename T >
const char * Pila<T>::PilaLlena::what() const throw()
{
    return "Pila llena";
}

//*************************************************************************************
template <typename T >
const char * Pila<T>::PilaVacia::what() const throw()
{
    return "No hay nada";
}

//*************************************************************************************
template <typename t >
std::ostream & operator<<(std::ostream & salida, const Pila<t> &pila )
{
    std::cout<<"<";
    for(int i=0;i<=pila.tope;++i)
        std::cout<<pila.elemento[i]<<", ";
    if(pila.tope != SIN_ELEMENTOS) std::cout<<"\b\b";
    std::cout<<'>';

    return salida;
}

//*************************************************************************************
template <typename T >
void Pila<T>::Redimensionar()
{
    T * aux = elemento;
    tamano *=2;
    elemento = new T [tamano];
    for(int i=0;i<=tope;++i)
        elemento[i] = aux[i];
    delete [] aux;
}

//*************************************************************************************
template <typename T >
int Pila<T>::Capacidad()const
{
    return tamano;
}

