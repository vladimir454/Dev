#include<iostream>
using namespace std;
class P{
    int n;

    public: 

        P(int n=0):n(n)
        {
            std::cout<<"primero"<<n<<"\n";

        }
        P(const P&p):n(p.n) //constructor copia
        {
            std::cout<<"copy"<<n<<"\n";
        }
        P& operator = (const P&p)
        {
            n = p.n; // de asignacion 
            std::cout<<"class"<<n<<"\n";
            return *this;

        } 
        P(P &p):n(p.n){ //semantica 
        std::cout<<"move"<<n<<"\n";
        }
        P& operator = (P&& p) // semantica de asignacion 
        {
            n= p.n;
            cout<<"move"<<"\n";
            return *this;
        }
};  

int main()
{   
    //ejemplos
    P aa(10);
    P b(aa); //constr
    P c(20);
    aa=c; 
    P d;
    d=move(aa);
}
