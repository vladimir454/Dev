 
/* 
generar la sigueinte secuencia. tamano 5 se generara de acuerdo al tamano introducido el primer for para la fila y la segunda de la columna
1 1 1 1 1
2 2 2 2
3 3 3
4 4
5
*/
#include<iostream>

using namespace std;

int main()
{
    int n,i,f;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        for(f=1; f<=((n+1)-i);f++)
        {
            cout<<i<<" ";
        }
          cout<<"\n";
    }


    return 0;
}
