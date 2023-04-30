#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED



#include<iostream>
#include<stdexcept>

#define SIN_ELEMENTOS 0

template <typename T=int>
class Pila
{



public:

    explicit Pila();
    Pila(const Pila & pla);
    ~Pila();



    Pila & operator= (const Pila & p);


    void Apilar(const T & val);

    const T & ConocerElemento() const ;

    int Tamano();
    bool EstaVacia() const ;
    void Imprimir() const;
    void Desapilar();
    void Vaciar();





    class PilaVacia: public std::exception
    {
        public:
            virtual const char * what() const throw();
        private:

    };


private:


    struct Elemento
    {

        Elemento(T val, Elemento * sig = NULL);

        T valor;
        Elemento *siguiente;
    };

    Elemento * tope;
    unsigned int tam;


};
#include"Pila.tpp"


#endif // PILA_H_INCLUDED
