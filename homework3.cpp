#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <memory>
#include <array>

template<typename T, typename P>
void iterate(const T&x, P p)
{
    for (typename T::const_iterator i = x.begin(); i!=x.end(); ++i)
    {
        p(*i);   
    }
}

struct X{
    int n;
    X(int n):n(n)
    {
        std::cout << "hello"<< '\n';
    }
    ~X()
    {
        std::cout << "bye" << '\n';
    }

    X(const X&x):n(x.n)
    {
        std::cout << "copies" <<n<< '\n';
    }
    X(X&&x):n(x.n)
    {
        std::cout << "moved" <<n<< '\n';
    }

    X& operator=(const X&x)
    {
        n= x.n;
        return *this;
    }
};
struct Animal 
{
    virtual  void say() const  
    {
        std::cout << "xxx" << '\n';
    }
    virtual ~Animal()
    {
        std::cout << "chau" << '\n';
    }
};

struct Dog:Animal 
{
   void say() const override
   {
       std::cout << "gau" << '\n';
   }
};

struct Cat:Animal
{
    void say() const override
    {
        std::cout << "main" << '\n'; 
    }
}; 

//utilizar el == 
template <typename T, typename Comp>
bool is_palindrome(const T&x, Comp c)
{

}
template<typename T>
bool is_palindrome(const T&x)
{   
    
    return is_palindrome(x, [] (auto &a, auto &b )
    {
        return a==b
    });
}
// template<typename T, > //podria ser comparador clas Comp >

// bool is_palindrome(const T& _x) //qie sepa comparar casos seria otra funcion 
// {
//     auto p=_x;
//     reverse(p.begin(),p.end());
//     return p==_x;
//     string res ="";
//     for(auto i=_x.length()+1; i=0;--i)
//     {
//        return res == _x;    
//     }
    
// }
int main()
{
    list<int> x;

    x.push_back(6);
    x.push_back(8);
    x.push_front(5);
    std::cout << x.size() << '\n';
    std::cout << x.front() << '\n';
    // iterate(x, [](auto x){
        // std::cout << x << '\n';});
    int sum =0;
    iterate(x, [&sum](auto i)
    {
        sum+=i;
    });
    std::cout << sum << '\n';

    list<string> s={"one","two","three", "four", "five", "six", "seven", "eight"};
    s.push_back("nine");
    s.push_back("ten");

    for (auto i = s.begin(); i!=s.end();) 
        {
            if ((*i)[0]=='t')
            {
                i=s.erase(i);
            }
            else 
          ++i;
        }
    for (auto &p:s )
    {
        std::cout << p << '\n';        
    }

    // vector<int> q { 9,7,8,5,4,6};
    // q.push_back(0);
    // //no se puede hacer aqui el push front por que es ineficiente
    // iterate(q,[](auto i)
    // {
    //     std::cout << i << '\n';
    // });
    // std::cout << q[5] << '\n';
    // std::cout << q.at(14) << '\n';
    // auto i = q.begin();
    // std::cout << *i << '\n';

    // sort(q.begin(), q.end());
    // for (auto i:q)
    // {
    //     std::cout << i << '\n';
    // }

    vector< string> r(3);
    r.push_back("hello");

    vector<X> X={9,8,7,6,5,44,3};

    std::cout << "eeeeeeeee" << '\n';
    x.emplace_back(18);
    std::cout << "xxxxxxxxxx" << '\n';
    // sort(x.begin().x.end()
    // sort(x.begin(), x.end(),[](auto &a, auto & b)
    // {
    //     return a.n<b.n;
    // });
    
    // for (auto i:x)
        // std::cout << i.n << '\n';    

    // vector<unique_ptr<Animal>> ss;
    // ss.push_back(unique_ptr<Dog>());
    // ss.push_back(unique_ptr<Cat>());
    // for(auto &i:ss)
    // i->say();
    // for (auto &i:ss)
    // i->say();

    // auto & ps = ss[1];
    // ps->say();
    // std::cout<< ps->say() << '\n';
    
    array<int ,4>d; //desde el standar c++11
    d[0]=5;
    d[1]=6;
    d[2]=10;
    d[3]=3333;
    sort(d.begin(), d.end());
    iterate(d,[](auto n)
    {
        std::cout<<"last->" << n << '\n';
    });


    string x ="amiguitos";
    string y = "abacadacaba";
    
    std::cout << is_palindrome(x) << '\n';
    std::cout << is_palindrome(y) << '\n';

}