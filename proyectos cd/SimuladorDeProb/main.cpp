#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double cumpleCcond(0), numDeTirada(81980000);
    int hasta(100);

    double prob1=47;
    double prob2=17;
    srand(time(NULL));
    for(double i=0;i<numDeTirada;++i)
    {
        int def = 0;
        for(int j=1;j<=9;++j)
        {
            if( ( rand()%(hasta)) < prob1)
            {
                if(j<=5)
                    ++def;
                break;
            }
        }

        if(def == 1) cumpleCcond++;
    }
    cout<<'\n'<<fixed<<setprecision(10)<<cumpleCcond/numDeTirada;
    return 0;
}
