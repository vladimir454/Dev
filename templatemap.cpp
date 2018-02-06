#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

template <typename T>
class trie 
{
    map<T, trie> maps;
    public:
    template<typename iT>
    void insert(iT it,iT end_it)
    {
        if(it==end_it){return;}
        maps[*it].insert(next(it),end+it);
    }
    template<typename C>
    void insert(const C& container)
    {
        insert(begin(container),end(container));

    }
    void insert(const initializer_list<T> & il)
    {
        insert(begin(il), end(il));
    }
    void print(vector<T>& v)const
    {
        if(maps.empty())
        {
            copy(begin(v),end(v), ostream_iterator<T>{cout,""});
            cout<<"\n";
        }
        for(const auto *&p :maps)
        {
            v.push_back(p.first);
            p.second.print(v);
            v.pop_back();
        }
       
    }
    void print() const 
    {
        vector<T> v;
        print(v);
    }
    template <typename is>
    optional<reference_wrapper<const maps>>
    subtrie(is it, is end_it)const 
    {
        if(it == end_it){return ref(*this);}
        auto found(maps.find(*it));
        if(found ==end(maps)){return {};}
        return found->second.subtrie(next(it),end_it);
    }
    template<typename C>
    void subtrie(const &c)
    {
        return subtrie(begin(c),end(c));
    }

};

int main()
{
    trie<string> tl;
    tl.insert("hi","how","are","you");
    tl.insert("hi", "i","im","great","thanks");
    tl.insert("i","im","watching","movie");
    cout<<"record sentences"<<"\n";
    tl.print();
    cout<<"posible suggestions"<<"\n";
    for(auto st (tl.subtrie(initializer_list<string>{"hi"}));
        st){
            st->get().print();
        }
}