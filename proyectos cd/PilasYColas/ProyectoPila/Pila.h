#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include<iostream>
#include<exception>

/** \brief
 */

/*template <typename T >
class Pila;

template <typename T >
std::ostream & operator <<(std::ostream & salida, const Pila<T> &pila )
{
    std::cout<<"<";
    for(int i=0;i<=pila.tope;++i)
        std::cout<<pila.elemento[i]<<", ";
    std::cout<<"\b\b>";
}*/

template <typename T=int, unsigned S=10 >
class Pila
{
    template <typename t,unsigned s>
    friend std::ostream & operator <<(std::ostream & salida, const Pila<t,s> &pila );
public:

    Pila();


    void AgregarElemento(T val);

    void EliminarElemento();

    void Vaciar();

    int Tamano()const;

    const T & ConocerElemento()const;

    bool EstaVacia()const;

    bool EstaLlena()const;

    void Imprimir()const;

    class PilaLlena: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };

     class PilaVacia: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };

private:
    int tope;
    T elemento[S];
};

#include"Pila.tpp"

#endif // PILA_H_INCLUDED
