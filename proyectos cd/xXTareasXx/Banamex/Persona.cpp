/* Nombre: .cpp
   Autor:
   Fecha:
   Descripción:
*/
#include"Persona.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
Persona::Persona()
{
    nombre = NombreAleatoria();
    termino = false;
    int r = rand()%100;
    //La mayoria solo van a cobrar cheques
    if(r >= 0 && r< 45)
        tAtencion = (rand()%5)+6;

    //Algunos retiran 2 veces
    if(r >= 45 && r< 75)
        tAtencion = (rand()%9)+11;

    //Otros hacen otro tipo de transacciones, o son un poco "especiales"
    if(r >= 75 && r< 85)
        tAtencion = (rand()%12)+20;

    //Pero es aun más raro que la persona tarde poco tiempo
    if(r >= 85 && r< 99)
        tAtencion = (rand()%2)+3;

    // Ohhhhh nNonONOnoNOnO un ladron, ayuda D:
    if(r == 99)
        tAtencion = (rand()%600)+1029;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
const std::string & Persona::getNombre() const
{
    return nombre;
}


const double Persona::getTAtencion() const
{
    return tAtencion;
}


//*************************************************************************************
bool Persona::getTermino() const
{
    return termino;
}


//*************************************************************************************
void Persona::disminTAtencion(double m/*=2.5*/)
{
    tAtencion-=m;
    if(tAtencion<=0) termino=true;
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/

std::string Persona::NombreAleatoria()
{
    //Dos nombres
    std::ifstream archivo("Nombre.txt");
    if(!archivo)
    {
        std::cout<<"El archivo no se encontr\242\n";
        archivo.close();
        return '\0';
    }
    char texto[100];
    std::string nombre;

    //Nombres
    //Ignorar los primeros r nombres
    int r= (rand()%NOMBRES);
    for(int i=0;i<r ;++i) archivo.getline(texto,100);

    archivo.getline(texto,100);
    NormalizarCadena(texto);
    nombre+=texto;
    archivo.close();

    bool segundoNomb = (rand()%2) == 1 ? true : false;
    if(segundoNomb)
    {
        archivo.open("Nombre.txt");
        r= (rand()%NOMBRES);
        for(int i=0;i<r ;++i) archivo.getline(texto,100);

        archivo.getline(texto,100);
        NormalizarCadena(texto);
        nombre+=' ';
        nombre+=texto;
        archivo.close();
    }

    //Apellidos
    archivo.open("Apellido.txt");
    if(!archivo)
    {
        std::cout<<"El archivo no se encontr\242\n";
        archivo.close();
        return '\0';
    }
    archivo.close();

    for(int i=0;i<2;++i)
    {
        archivo.open("Apellido.txt");
        r= (rand()%APELLIDOS);
        for(int j=0;j<r ;j++) archivo.getline(texto,100);

        archivo.getline(texto,100);
        NormalizarCadena(texto);
        nombre+=' ';
        nombre+=texto;
        archivo.close();
    }
    return nombre;
}

 /*****************************************************************************************
 *********************************   Funciones Amigas  ************************************
 *****************************************************************************************/
//*************************************************************************************
std::ostream & operator<<(std::ostream & salida ,const Persona & p )
{
    salida<<p.getNombre();
    return salida;

}
