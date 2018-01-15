#include "pila.h"

    // para insertar (push)
    void StuckArray::push(int element)
    {
        if(fullStuck())
        {
            throw "its full";
        }
        top++;
        list[top]= element;
    }
    //para quitar(pop)
    int StuckArray::pop()
    {
        int aux;
        if (emptyStuck())
        {
            throw " its none of the elements can delete";
        }
        aux =list[top];
        top--;
        return aux;
    }
    void StuckArray::clearStuck()
    {
        top=-1;
    }   
    //operacion de acceso 
    int StuckArray::topStuck()
    {
       if(emptyStuck())
       {
           throw "none of the elements can found";
       }
       return list[top];
    }
    // verificacion del estado de la pila
    bool StuckArray::emptyStuck()
    {
        return top ==-1;
    }
    bool StuckArray::fullStuck()
    {
        return top == TAMPILA -1;
    }
