// Hace tiempo implementamos un TRIE en C.
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include <unordered_map>

// Implementarlo a manera de mapa en C++:
using namespace std;


struct IterateTrie{
    char str;
    map<char, IterateTrie*> children;
};
using iterator = IterateTrie;

template <typename T>
class trie
{   
 map<T, trie> tries;
   
public:
    
  void insert(const string& key, const T& value)
  {
     
  }
  size_t size() const
  {

  }
  T& operator[](const string& key) //if does not find it, creates it.
  {

  }
  iterator find(const string& key)
  {
    if(*key==0)
    {

    }
   
  }
  iterator begin()
  {

  }
  iterator end()
  {

  }

  template <typename PROC>
  void iterate_by_prefix(const string& prefix, PROC p)
  {

  }
};

// La idea es que dada una clave (siempre como string, dada la naturaleza del Trie),
// se pueda almacenar un valor de cualquier tipo T en el nodo específico.

int main()
{

  trie<int> s;
  s.insert("diez", 10);
  s.insert("dieciocho", 18);
  s.insert("diecinueve", 19);
  s["veinte"] = 20;
  s["veintiuno"] = 21;

  auto it = s.find("veinte");
  if (it == s.end())
        cerr << "Not found\n";
    else 
        cout << it->second << "\n";

//   //should iterate diez, dieciocho and diecinueve
//   s.iterate_by_prefix("die", [](auto& p)
//   {
//     cout << "Key: " << p.first << "; Value: " << p.second << "\n";
//   });

//   cout << "****\n";

//   // should get all items as pairs
//   for (auto& i : s) { cout << i.second  << "\n"; }
}