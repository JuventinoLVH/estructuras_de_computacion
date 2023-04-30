#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include<stdexcept>
#include<iostream>

//#define MAXDIM 100 //<-------------------------

class Vector
{
public:

    /** \brief
    *
    *
    */
    Vector();
    /** \brief
     *
     * \param v const Vector&
     *
     */
    Vector(const Vector &v);
    /** \brief
     *
     * \param dim int
     *
     */
    Vector(int dim);
    /** \brief
    *
    * \param dim int
    * \param ValorIn double
    *
    */
    Vector(int dim, double valorIn);
    /** \brief
     *
     *
     */
    ~Vector();



    /** \brief
    *
    * \param i int
    * \param comp double
    * \return void
    *
    */
    void EstablecerComponente(int i,double comp);
    /** \brief
     *
     * \param dim int
     * \return void
     *
     * \exception std::logic_error Lo mismo<>>>><>><>>
     */
    void EstablecerDimension(int dim);



    /** \brief
    *
    * \return int
    *
    */
    int ObtenerDimencion() const;
    /** \brief
     *
     * \param i int
     * \return double
     *
     */
    double ObtenerComponente(int i) const;


    /** \brief
    *
    * \return void
    *
    */
    void Imprimir() const;
    /** \brief
     *
     * \return void
     *
     */
    void Captura();


    /** \brief
    *
    * \param v Vector
    * \return Vector
    *
    */
    Vector Sumar(const Vector &v) const;
    /** \brief
     *
     * \param v Vector
     * \return Vector
     *
     */
    Vector Resta(const Vector &v) const;
    /** \brief
    *
    * \param escalar double
    * \return Vector
    *
    */
    Vector Multiplicar(double escalar) const;
    /** \brief
     *
     * \return double
     *
     */
    double ObtenerMagnitud() const;




protected:


private:
    int dim;
    double *componente=NULL; //<-------------------------

};

#endif // VECTOR_H_INCLUDED
