#include <iostream>
#include "math.h"
#include "Utileria.h"

using namespace std;

int main()
{
    CambiaCursor(APAGADO);
    float A=0,B=0;
    float i,j;
    int k;
    float z[1760];
    char b [1760];

    float Mc[70000];
    float Md[70000];
    float Mf[70000];
    float Ml[70000];
    for(j=0;j<6.28;j+=0.07)
    {
            for(i=0;i<6.28;i+=0.02)
            {
                Mc[(int)(i*100)]=sin(i);
                Md[(int)(j*100)]=cos(j);
                Mf[(int)(j*100)]=sin(j);
                Ml[(int)(i*100)]=cos(i);
            }
    }

    while(true)
    {
        memset(b,32,1760);
        memset(z,0,7040);
        for(j=0;j<6.28;j+=0.07)
        {
            for(i=0;i<6.28;i+=0.02)
            {
                float c=Mc[(int)(i*100)];
                float d=Md[(int)(j*100)];
                float e=sin(A);
                float f=Mf[(int)(j*100)];
                float g=cos(A);
                float h=d+2;
                float D=1/(c*h*e+f*g+5);
                float l=Ml[(int)(i*100)];
                float m=cos(B);
                float n=sin(B);
                float t=c*h*g-f*e;
                int x=40+30*D*(l*h*m-t*n);
                int y=12+15*D*(l*h*n-t*m);
                int o=x+80*y;
                int N=8*((f*e-c*d*g)*m-c*d*e-f*g-l*d*n);
                if(22 > y && y>0 && x > 0 && 80>x && D>z[o])
                {
                    z[o]=D;
                    b[o]=".,-~:;=!*#$@"[N> 0 ? N : 0];
                }
            }
        }
        gotoxy(0,0);
        k=0;
        for(int L=0;L<22;L++)
        {
            for(int P=0;P<80;P++ )
            {
                cout<<b[k++];
                A+=0.00004;
                B+=0.00002;
            }
            cout<<'\n';
        }
    }
    return 0;
}
