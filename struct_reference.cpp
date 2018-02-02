#include<iostream>

using namespace std;

struct Traslator{ //recuerden que en constructor todo es public

int dx; 
int  dy;

Traslator(int& ud, int& ad)
{
    dx=ud; //la ude para por referencia el valor 3 a->dx  y manda a int dx;
    dy=ad;
}


Traslator& aplicar() //aqui estoy pasando por refenrecia ente mismo con *this; para q el poderoso c++ puieda llamar tantas veces quieras 
{
    std::cout << dx<< '\n'; //aqui se puede llamar a dx 
    std::cout << dy << '\n';
    return *this;
}
void end()

{
   std::cout << "end" << '\n';
}

};


int main()
{
    int x =20;
    int y=7;
    Traslator t(x,y);
    t.aplicar().aplicar().aplicar().aplicar();
    t.end();
    return 0;
}