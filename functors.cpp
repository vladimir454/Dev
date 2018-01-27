// function objects 

#include <iostream>
#include <algorithm>
// struct S
// {
    
//     int operator() (int a,int b) const 
//     {
//         return a+b;
//     }
// };

struct S
{   
    template<typename  T>
    
    T operator()(T a,T b) const 
    {
        return a+b;
    }
};
int main()
{
    S s;
    std::cout<<s(2,3)<<"\n"; //busca este parentisis y  pasa el objeto a operator()
    std::cout<<s(6.4,3.2)<<"\n";

    int p[] = {2,3,0,1,5,4};
        qsort(p,6,sizeof(int), 
        [](const void*a,const void*b ) //para que no redusca  retornar flecha ->int 
        //desde standar 14 auto en ves de cost void *a
        {
            int* pa=(int*)a;
            int* pb=(int*)a;
            return *pa-*pb;
//c++ 11  funcion anonima  llamada expresion  
/* qsort(void *a, size_t 4, size_t s,) int (*c) (const void *, const void &*/
        });

    // for (auto i:p){std::cout<<i<<"\n";}

    int q[] = { 6,7,5,4,2,9,0};
    // std::sort(q, q+7);
    bool ascending =true;
    std::sort(q,q+7,[&](int a,int b) //este se llama predicado int a, int b esois  devuelve true 
    {
        if(ascending)
            return a<b;
             ascending!=ascending;
        return b<a;
    });
    puts("--------sort reverse------------");
    for (int i:q){std::cout<<i<<"\n";}


    auto f = [](auto a)

    {
        std::cout<<a<<"\n";
    };
puts("--------------muy extrano------------");
    f(2);
    f(3.4);
    f("hello");
}