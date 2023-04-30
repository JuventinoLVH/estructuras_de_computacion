/* Nombre: main.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 18/03/21
   Descripción: Clase cliente para la cola medieval
*/
#include<iostream>
#include<ctime>
#include"ColaMedieval.h"

#define MINUTOS 2.5 //Cuantos minutos equivale un segundo de vida real

using namespace std;

//****************************************************************************************
/** \brief Imprime la hora en formato
*
* \param h la cantidad de horas
* \param m la cantidad de minutos
*
*/void ImprHora(int h, int m);

//****************************************************************************************
/** \brief Simula que el tiempo ha pasado
*
* \param h la cantidad de horas
* \param m la cantidad de minutos
*
*/void SimularTiempo(int & h, double & m);

//****************************************************************************************
/** \brief Imprime los datos de la cola
*
* \param b el cola a imprimir
* \param h la hora del día
*
*/void ImprEstado(const PersonaMedieval & p, int h, int hIn, int hFin);

//****************************************************************************************
/** \brief Añade una persona a la cola, la probabilidad de que aparezca varia segun la hora
*
* \param b la cola a la que entrará la persona
* \param h la hora del día
*
*/void AparecerPersona(ColaMedieval & cm ,int h);

 /*****************************************************************************************
 *************************************     Main     ***************************************
 *****************************************************************************************/
//****************************************************************************************
int main()
{
    cout<<"Buenos d\241as su majestad\n";

    int hIn,hFin;
    srand(time(NULL));
    ColaMedieval colaParaVerAlRey;
    PersonaMedieval personaAct("",0,true,false);

    do
    {
        hIn=CapturaEntero("\250A qu\202 hora desea empezar a atender a la multitud?: ");
        if(hIn>=24 || hIn < 0)
            cout<<"Su majestad.Creo que no es posible atender a esas horas...\n";
    }while(hIn>=24 || hIn < 0);
    do
    {
        hFin=CapturaEntero("\250A qu\202 hora terminar\240?: ");
        if(hFin<=hIn || hFin>= 24)
            cout<<"Su majestad.Creo que eso es imposible, incluso para un rey como usted...\n";
    }while(hFin<=hIn || hFin>= 24);

    if(hFin-hIn>=16)
        cout<<"Whow, su majestad, es usted un rey muy generoso. No por nada es el rey de reyes\n";
    system("pause");
    system("cls");
    CambiaCursor(APAGADO);

    double minutos=0;
    int horas=(hIn > 4 ? 4 : hIn); //Las personas empiezan a acudir al rey a partir de las 4
    while(horas < hFin || !personaAct.Termino())
    {
        ImprHora(horas,minutos);

        cout<<"\n\n\t";
        ImprEstado(personaAct , horas,hIn,hFin);

        if(horas>=hIn)
        {
            if(!colaParaVerAlRey.EstaVacia() && personaAct.Termino())
            {
                personaAct=colaParaVerAlRey.PrimElemento();
                colaParaVerAlRey.Desencolar();
            }
        }
        personaAct.DisminTAtencion(MINUTOS);
        try
        {
            cout<<"\nPersonas esperando para hablar con el rey...\n";
            colaParaVerAlRey.Imprimir();
            AparecerPersona(colaParaVerAlRey,horas);
            SimularTiempo(horas,minutos);
            system("cls");
        }
        catch(...)
        {
            cout<<"Error, algo raro paso, posiblemente un golpe de estado...\n";
            return -1;
        }
    }

    try
    {
        ImprHora(horas,minutos);
        cout<<"\n\n\t";
        ImprEstado(personaAct,horas,hIn,hFin);
        cout<<"\nPersonas que quedaron esperando...\n";
        colaParaVerAlRey.Imprimir();
        cout<<"\n\nHoy se atendi\242 a: \n";
        colaParaVerAlRey.ImprimirAtendidos();
    }
    catch(...)
    {
        cout<<"Error, algo raro paso, posiblemente un golpe de estado...\n";
        return -1;
    }
    system("pause");
    return 0;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//****************************************************************************************
void ImprEstado(const PersonaMedieval & p, int h, int hIn, int hFin)
{
    if(h>=hFin)
    {
        if(p.Termino())
            cout<<"El rey descansar\240 por hoy, vuelvan otro d\241oha...";
        else
            cout<<"Despues de est\240 atender a: "<<p.ObtNombre()<<" el rey cortar\240 "<<
                    "la cabeza de la siguiente persona que le pida algo...";
        return;
    }
    if(h >= hIn)
    {
        if(p.Termino())
            cout<<"Esperando a que alguien acuda ante el rey...";
        else
            cout<<"El rey est\240 atendiendo las suplicas de: "<<p.ObtNombre()<<
                "\t\tel tiempo estimado para terminar de atenderlo/a es: "<<p.ObtTAtencion();
    }
    else
    {
        cout<<"Las personas esperan pacientemente a que el rey escuche sus suplicas...";
    }
}


//****************************************************************************************
void AparecerPersona(ColaMedieval & b ,int h)
{
    PersonaMedieval nuevaP;
    //A quien madruga dios le ayuda
    if(h >= 4 && h<6)
    {
        if(rand()%100 < 45)
            b.Encolar(nuevaP);
    }
    //Los no madrugadores se esperan
    if(h >= 6 && h<10)
    {
        if(rand()%100 < 30)
            b.Encolar(nuevaP);
    }
    //A medio dia la gente pierde esperanza
    if(h >= 10 && h<14)
    {
        if(rand()%100 < 16)
            b.Encolar(nuevaP);
    }
    //A partir de las 2 la gente solo hace fila por diverción...
    if(h >= 14 )
    {
        if(rand()%100 < 4)
            b.Encolar(nuevaP);
    }
}


//****************************************************************************************
void SimularTiempo(int & h, double & m)
{
    //escala de tiempo 1 seg. : 2.5 min.  =  4 min. : 10 h.
    Sleep(1000);
    m+=MINUTOS;
    if(m>=60)
    {
        ++h;
        if(h > 24) h =0;
        m-=60;
    }
}


//****************************************************************************************
void ImprHora(int h, int m)
{
    bool mat = h <= 12 ? true : false;
    cout<< (mat ? h : h-12) <<':';
    if(m<10) cout<<'0';
    cout<<m<<' ';
    cout<< (mat ? "AM" : "PM");
}
