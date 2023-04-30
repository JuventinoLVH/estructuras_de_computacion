/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/


template <typename T,unsigned S >
Pila<T,S>::Pila()
{
    tope=-1;
}

template <typename T,unsigned S >
const T & Pila<T,S>::ConocerElemento()const
{
    if(EstaVacia() ) throw PilaVacia();
    return elemento[tope];
}

template <typename T,unsigned S >
void Pila<T,S>::AgregarElemento(T val)
{
    if( EstaLlena() )   throw PilaLlena();

    elemento[++tope]=val;
}

template <typename T,unsigned S >
bool Pila<T,S>::EstaLlena() const
{
    return (tope == S-1);
}

template <typename T,unsigned S >
bool Pila<T,S>::EstaVacia() const
{
    return tope == -1;
}

template <typename T,unsigned S >
void Pila<T,S>::EliminarElemento()
{
    if(EstaVacia() ) throw PilaVacia();
}

template <typename T , unsigned S>
void Pila<T,S>::Imprimir() const
{
    std::cout<<"<";
    for(int i=0;i<=tope;++i)
        std::cout<<elemento[i]<<", ";
    std::cout<<"\b\b>";
}

template <typename T ,unsigned S>
const char * Pila<T,S>::PilaLlena::what() const throw()
{
    return "Pila llena";
}

template <typename T ,unsigned S>
const char * Pila<T,S>::PilaVacia::what() const throw()
{
    return "No hay nada";
}


template <typename t,unsigned s>
std::ostream & operator <<(std::ostream & salida, const Pila<t,s> &pila )
{
    std::cout<<"<";
    for(int i=0;i<=pila.tope;++i)
        std::cout<<pila.elemento[i]<<", ";
    std::cout<<"\b\b>";
    return salida;
}

