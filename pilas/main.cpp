#include <iostream>
using namespace std;
const int TAMPILA =   10;
//tenemos entrada de 1,2,3,4..48 
class StuckArray
{
    int top;
    int list[TAMPILA];

    public:

    StuckArray()
    {
        top = -1;
    }
    // para insertar (push)
    void push(int element){
        if (fullStuck())
        {
            throw "desbordamiento de pila\n";
        }
        top++;
        list[top]=element;
    }
    //para quitar(pop)
    int pop(){
        int aux;
        if (empyStuck())
        {
            throw "pila vacia no se puede extraer";
        }
        //guarda elementos en la cima
        aux = list[top];
        top--;
        return aux;

    }
    void clearStuck()
    {
        top = -1;
    }

    //operacion de acceso 
    int topStuck()
    {
        if (empyStuck())
        {
            throw " la pila esta vacia, any elements";
        }
        return list[top];
    }
    // verificacion del estado de la pila
    bool empyStuck()
    {   
        return top ==-1;

    }
    bool fullStuck()
    {
        return top == TAMPILA-1;
    }

};

int main()
{
    StuckArray pila; //crear pila vacia
    int x;
    const int CLAVE = -1;
    std::cout << "input element not (-1)" << '\n';
    try
    {
         do
        {
            cin>>x;
            pila.push(x);
        } while(x!=CLAVE);
        std::cout << "elements of a stuck" << '\n';
        while (!pila.empyStuck())
        {
            x = pila.pop();
            cout<<x<<"\n";
        }
    }
    catch (const char*error)
    {
        std::cout << "exception " <<error<< '\n';
    }
   return 0;
}