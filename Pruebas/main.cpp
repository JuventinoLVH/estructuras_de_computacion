#include <bits/stdc++.h>

using namespace std;

stack<bool>Operacion;
int num,mi,mj;

class Solution {
public:

    bool EsCorchete(char c)
    {
        if(c=='(' )
            return true;
        return false;
    }


    int scoreOfParentheses(string S) {
        int tam=S.size();
        stack<bool>Operacion;
        for(int i=0;i<tam;++i)
        {

        }
    }
};

struct Punto
    {
        int i;
        int j;

        Punto(int X=-1, int Y=-1)
        {
            i=X;
            j=Y;
        }
    };

struct DosPuntos
    {
        Punto p1;
        Punto p2;

        DosPuntos(){}

        DosPuntos(Punto P1, Punto P2)
        {
            p1=P1;
            p2=P2;
        }

    };

struct TernaMat
    {
        DosPuntos mat1,mat2,mat3;

        TernaMat(){}


        TernaMat(DosPuntos p1, DosPuntos p2, DosPuntos p3)
        {
            mat1=p1;
            mat2=p2;
            mat3=p3;
        }
    };

TernaMat SepararMat(DosPuntos &mat, bool mayor, Punto & mitad)
    {

        DosPuntos mat1;
        DosPuntos mat2;
        DosPuntos mat3;
        if(mitad.j+1 <= mat.p2.j)
             mat1 = DosPuntos( Punto(mat.p1.i , mitad.j+1 ) , Punto( mitad.i , mat.p2.j) );

        if(mitad.i+1 <= mat.p2.i)
            mat2=DosPuntos( Punto(mitad.i+1 , mat.p1.j) , Punto(mat.p2.i ,mitad.j)   );

        if(mayor)
        {
            if(mitad.i != mat.p1.i || mitad.j != mat.p1.j)
                mat3=DosPuntos( mat.p1 , Punto(mitad.i,mitad.j) );
        }
        else
        {
            if(mitad.i+1 <= mat.p2.i && mitad.j+1 <= mat.p2.j)
                mat3=DosPuntos( Punto(mitad.i+1,mitad.j+1) , mat.p2);

        }

        return TernaMat(mat1,mat2,mat3);
    }

bool SiEsta(vector<vector<int> >& matrix, int n,DosPuntos &mat)
    {
        int iter = ++num;
        cout<<"Aqui inicia la iteracion: "<<iter<<"PrimerPunto: ("<<mat.p1.i<<" , "<<mat.p1.j<<")  "<<"SegundoPunto: ("<<mat.p2.i<<" , "<<mat.p2.j<<") "<<'\n';
        Punto mitad( (mat.p2.i+mat.p1.i)/2 ,(mat.p2.j+mat.p1.j)/2 );

        for(int i=mat.p1.i;i<=mat.p2.i;++i)
        {
            for(int j=mat.p1.j;j<=mat.p2.j;++j)
                cout<<matrix[i][j]<<'\t';
            cout<<'\n';
        }
        cout<<"Mitad: ("<<mitad.i<<" , "<<mitad.j<<") = "<<matrix[mitad.i][mitad.j]<<'\n';

        int valMit=matrix[mitad.i][mitad.j];
        if(valMit==n)
        {
            cout<<" Aqui muere\n";
            return true;
        }

        if(mat.p1.i == mat.p2.i && mat.p1.j == mat.p2.j)
        {
            cout<<" Aqui muere\n";
            return false;
        }

        TernaMat subMat;
        subMat=SepararMat(mat, valMit >= n ,mitad);
        if(subMat.mat1.p1.i !=-1 && SiEsta(matrix,n,subMat.mat1))
            return true;
        if(subMat.mat2.p1.i !=-1 && SiEsta(matrix,n,subMat.mat2))
            return true;
        return (subMat.mat3.p1.i !=-1 && SiEsta(matrix,n,subMat.mat3));
    }

bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        Punto p1(0,0);
        Punto p2(matrix.size()-1, matrix[0].size()-1);
        DosPuntos mat(p1,p2);
        return SiEsta(matrix, target,mat);
    }

    bool EsAb(char c)
    {
        return c=='(' ;
    }


    int scoreOfParentheses(string S)
    {
        int tam=S.size();
        stack<bool>operacion;
        stack<int>val;
        int n1,n2;
        for(int i=0;i<tam;++i)
        {
            if(EsAb(S[i]))
            {
                if(EsAb(S[i+1]))
                {
                    operacion.push(false);// false = *
                    val.push(2);
                }
                else
                    val.push(1);
            }
            else
            {
                if(!EsAb(S[i-1]))
                {
                    do
                    {
                        n2=val.top();
                        val.pop();
                        n1=val.top();
                        val.pop();
                        if(operacion.top())
                            val.push(n1+n2);
                        else
                            val.push(n2*n1);

                        operacion.pop();

                    }while(!operacion.empty() && operacion.top() );

                    do
                    {
                        n2=val.top();
                        val.pop();
                        n1=val.top();
                        val.pop();
                        if(operacion.top())
                            val.push(n1+n2);
                        else
                            val.push(n2*n1);

                        operacion.pop();

                    }while(!operacion.empty() && operacion.top() );
                }
                if(i<tam-1 && EsAb(S[i+1]) )
                    operacion.push(true); // true = +
            }
        }

        return val.top();
    }

int main()
{
    char c;
    cin>>c;
    if(c>='a') c-=' ';
    cout<<'\n'<<c;
    /*
    Operacion.o
    int mattz[10][10]= {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    vector<vector<int> > mat;
    vector<int> aux;

    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
            aux.push_back(mattz[i][j]);
        mat.push_back(aux);
        aux.clear();
    }

    if(searchMatrix(mat,2))
    {
        cout<<"Si esta";
    }
    else
    {
        cout<<"No esta :(";
    }
    string s; */


    return 0;
}
