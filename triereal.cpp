#include <iostream>
#include <cstring>

using namespace std;

/*
La velocidad de iteracoin es de O(N), donde n es el numero maxiomo de letras
*/

struct trienode
{
	char* data;
	trienode* children[26];
	trienode() : data{nullptr}
	{
		memset(children, 0, 26 * sizeof(trienode*));//pone la cantidad de bytes, del tamanho especificado, del array al valor que se le especifique
	}
};

class trie
{
	trienode root;
	static void set_data(trienode& n, const char* v)
	{
		auto len = strlen(v);
		auto ns = new char[len + 1];
		memcpy(ns, v, len + 1);
		n.data = ns;
	}
	void add(trienode& n, const char* k, const char* v)
	{
		if(*k == 0)
		{
			set_data(n, v);
			return;
		}
		auto index = *k - 'a';
		auto& e = n.children[index]; ///auto& = trie*&
		if(e == nullptr)
		{
			e = new trienode();
		}
		add(*e, k+1, v);
	}
	const char* find(const trienode& n, const char* s) const
	{
		if(*s == 0)
		{
			return n.data;
		}
		auto index = *s - 'a';
		auto e = n.children[index];
		if(e == nullptr) return nullptr;
		return find(*e, s+1);
	}
	/*void print(const trienode& n, char* esp) const
	{
		if (n.data != nullptr)
		{
			//cout << "Palabra: " << esp << endl;
			//cout << endl;
			cout << "Traduccion: " << n.data << endl << endl;
		}
		for (int i = 0; i < 26; ++i)
		{
			auto e = n.children[i];
			if(e != nullptr)
			{
				char index = (char)(i + 'a'); 
				char* letter = new char[2];
				letter[0] = index;
				letter[1] = '\0';
				strcat(esp, (const char*)letter);
				cout << esp << endl;
				delete [] letter;
				print(*e, esp);
			}
		}
		if(*esp != '\0')
		{
			char* aux;
			auto len = strlen(esp);
			memcpy(aux, esp, len-1);
			aux[len-1] = '\0';
			strcpy(esp, aux);
		}
	}*/
public:
	trie()
	{

	}
	trie& add(const char* k, const char* v)
	{
		add(root, k, v);
		return *this;
	}
	void print() const
	{
		char* s;
		print(root, s);
	}
	const char* find(const char* s) const
	{
		return find(root, s);
	}
	~trie()
	{
		delete [] root.data;
	}
	
};

int main()
{
	trie x;
	x.add("perro", "dog")
	.add("gato", "cat")
	.add("pato", "duck")
	.add("gallo", "rooster")
	.add("gallina", "chicken")
	.add("raton", "mice")
	.add("tortuga", "turtle")
	.add("tortugaterrestre", "tortoise");
	x.print();
	if (auto n = x.find("gallina");  n != nullptr)
	{
		cout << n << endl;
	}
	//x.print_prefix("gall");
}