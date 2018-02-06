
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include <unordered_map>
using namespace std;
//IDL
// un millon de elementos cvan a encotnrar un 20 for s  es para especializacion y para acceder  *o(log N)

struct CarId
{
    string placa;
    int anio;
};

struct carComp
{
    bool operator() (const CarId& a, const CarId&b)const  ///tien que ser constantre
    {
    // return a.anio <b.anio; solo para el ano 
    // para diferenes anios se importa tie 
    return tie(a.anio,a.placa)<tie(b.anio,b.placa);
    }
};
bool strcomp (const string& a, const string&b)
{
    return a<b;
}
struct CI
{
    int n;
    string c;

};
struct CIHash
{
    size_t operator()(const CI&c)const 
    {
        return c.n;
    }
};
struct CIEq //si no tienes operador hay que aumentar  O(1)
{
    bool operator()(const CI&a, const CI&b)const
    {
        return a.n==b.n && a.c ==b.c;
    }
};
int main()
{
    map<int, string>m; //clave y valor 
    m.insert(pair<int,string>{123456, "juan marcos"}); //estpy creando un temporal  como es moroso 
    m.insert(make_pair(546456546, " susa castro")); //esta es la mas factible  make pair es una funcion 
    m[23423434]="migure inojosa";  //utilizenlo para insertar 
    std::cout << m[12321323] << '\n';

 map <int, string>::iterator  it = m.find(65656560); //0 es para
    if (it==m.end())
    {
        cerr<<"not found\n";
    }else
    {
        std::cout << it->second << '\n';
        std::cout << "****" << '\n';
    } 
    for (auto & p:m)

    {
        std::cout << p.first << '\n';
        std::cout << p.second << '\n';   
    }

    map<CarId, string, carComp>m2;
    m2.insert(make_pair(CarId{"3234RF",1001},"vm ORLAND"));
    m2[CarId{"23423424", 20187}] = "TESLA A5";
    m2[CarId{"100aaa", 1932}]="ford 34";

    for (auto &i : m2)
    {
        std::cout << i.second << '\n';
    }
//unordered map  manana vamos avanzar
    // map<string, int > m3; //el tipo de strcomp 
//  map<string, int, decltype(&strcomp)> m3{strcomp};
//     m3["dos"]=2;
//     m3["cinco"]=5;
//     m3["cuatro"]=4;
//     m3["ocho"]=8;
    
//     for (auto & i : m3)
//     {
//         std::cout << i.first << '\n';
//     }

    // bool(*)()

    unordered_map<CI,string,CIHash,CIEq>s;
    s.insert(make_pair(CI{3434545,"CBBA"},"juan lopez"));
    s[CI{23434234, "lp"}]="ramiro perez";
    s[CI{2343435, "lp"}]="ARIANA GOMEZ";
    s[CI{3434545, "PT"}]="ADRINA LAZO";
    for(auto& i:s)
    {
        cout<<i.first.n<<"" <<i.first.c<<" " <<i.second<<"\n";
    }
}