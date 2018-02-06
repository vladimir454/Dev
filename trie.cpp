#include <iostream>
#include <cstring>

using namespace std;


struct Node
{
    char* date;
    Node* children[26];


    Node():date{nullptr}
    {
        
        memset(children, 0, 26* sizeof(Node*));
    }
};
class Ar
{
    private:
  
    Node root;
    void set_Data(Node& n, const char* ss)
    {
        auto len = strlen(ss);
        auto ns = new char[len +1];
        memcpy(ns, ss, len+1);
        n.date=ns;
        // std::cout << len << '\n';
        // auto ns = 
    }
    void add(Node& n, const char* a, const char* ss)
    {
        if (*a == 0)
        {
            set_Data(n,ss);
            // std::cout << "ss" << '\n';
            return;
        }
        auto index = *a-'a';
        auto& e = n.children[index];
        if (e==nullptr)
        {
            e = new Node;
        }
        add(*e,a+1,ss);
    
        // std::cout << *a <<*ss<< '\n';
    }
    const char* find(const Node& n, const char *ss) const
    {
        if (*ss == 0)
        {
            return n.date;
        }
        auto index = *ss-'a';
        auto  e = n.children[index];
        if (e==nullptr)
        {
            return nullptr;
        }
        return find(*e,ss+1);
    }

    public:
    
    void print(const Node& n, char* ss)const 
    {
        if (n.date == nullptr)
        {
            std::cout << "traduccion" <<n.date<< '\n';
        }
        for (auto i = 0; i < 26; i++)
        {
            auto e = n.children[i];
            if (e !=nullptr)
            {
                char index =(char)(i+'a');
                char* letter = new char[2];
                letter[0]=index;
                letter[1]='\0';
                strcat(ss, (const char*)letter);
                std::cout << ss << '\n';
                delete []letter;
                print(*e,ss);
            }
        }
        return;
    }
   
     Ar()
    {

    }
    Ar& add(const char* k, const char* ss)
    {
        add(root, k,ss);
        return *this;
    }

    void print()const
    {
        char* ss;
        print(root, ss);
    }

    const char* find(const char* ss)const
    {
        return find(root, ss);
    }

    ~Ar()
    {
        delete[] root.date;
    }
};

int main()
{
    Ar x;
    x.add("one","uno");
    x.add("two","dos");
    x.add("thre","tres");
    x.add("four","cuatro");
    x.add("five","cinco");
    x.print();

    auto i= x.find("uno");
    if( i != nullptr)
    {
        cout<<"result->"<<i<<endl;
    }
        
    
}