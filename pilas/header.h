#include <iostream>

using namespace std;

const int TAMPILA =   10;
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
    void push(int element);
    //para quitar(pop)
    int pop();
    void clearStuck();
    //operacion de acceso 
    int topStuck();
    // verificacion del estado de la pila
    bool emptyStuck();
    bool fullStuck();
};