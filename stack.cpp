#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include <unordered_map>

using namespace std;
//IDL

template <typename T, int MAXVALUE>
class Stack 
{
    int m_top;
    T data[MAXVALUE];
    
    public:

    Stack():m_top(-1){}

    void push(T value )
    {
        if (m_top>MAXVALUE)
        {
            throw "its full";
        }
        data[++m_top]=value;
    }
    
    T pop()
    {
        
        if (empty())
        {
            throw "empty";
        }
        
        --m_top;
    }
    int top()
    {
        
        return data[m_top];
    }
    bool empty()
    {
        
        return m_top<0;
    }


};

int main()
{
    Stack<int, 10> s;
    s.push(4);
    s.push(5);
    s.push(10);
    s.push(6);

    while (!s.empty())
    {
        std::cout << s.top() << '\n';
        s.pop();
    }

}


