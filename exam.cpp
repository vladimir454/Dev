#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

const int MAX = 100;
struct Stuck
{
    int top;
    int list[MAX];
    double data;
    int count;

    Stuck()
    {
        top = -1;
    }
    // para insertar (push)
    void push(int element)
    {
          if(fullStuck())
        {
            throw "its full";
        }
        top++;
        list[top]= element;
    }
    //para quitar(pop)
    int pop()
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
    void clearStuck()
    {
          top=-1;
    }
    //operacion de acceso 
    int topStuck()
    {
        if(emptyStuck())
       {
           throw "none of the elements can found";
       }
       return list[top];
    }
    // verificacion del estado de la pila
    bool emptyStuck()
    {
        return top ==-1;
    }
    bool fullStuck()
    {
         return top == MAX -1;
    }
};
enum CalculatorType
{
    RPN
    
};

struct ICalculator 
{   
    int a;
    int b;
    const char * op;
    void eval(int a, int b, const char *op)
    {

    }

	// virtual double create_Calculator(const ICalculator&) const = 0;
};
struct  CalculatorFactory :public Stuck
{
    
     ICalculator* create_calculator(CalculatorType tpye)
     {
        return nullptr;
     } 
         void show()
    {
        
    }

};



// struct CalculatorType
// {
//         static int RPN();
// };
// struct RPN
// {

// };



int main()
{
        CalculatorFactory cf;
        ICalculator* calc = cf.create_calculator(CalculatorType::RPN);

        // show(calc->eval2 3 +")); // 5
        // show(calc->eval("100 12.5 13.7 * -")); // 67.825
        // show(calc->eval("5 6 7 8 + - * 5 +")); // 50
        // show(calc->eval("6 inc")); // [Error: operator 'inc' unknown]
        // show(calc->eval("7 2 max")); // [Error: operator 'max' unknown]
        // show(calc->eval("7 *")); // [Error: no operand found for '*']
        // show(calc->eval("+")); // [Error: no operand found for '+']
        // show(calc->eval("abc")); // [Error: operator 'abc' unknown]
        // show(calc->eval("12x6")); // [Error: syntax error]

        // calc->add_operator("inc", new IncOperator());
        // calc->add_operator("max", new MaxOperator());
        // calc->add_operator("sqrt", new SqrtOperator());

        // show(calc->eval("10 5 max inc")); // 11
        // show(calc->eval("25.8 63 max inc sqrt")); // 8
}
