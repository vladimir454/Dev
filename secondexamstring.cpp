#include<iostream>
#include<cstring>

using namespace std;
 
class text_processor
{ 
    
    const char* texto;
    char* text = new char[2000];

public:

text_processor( const char* t){
    texto = t;
    int characters = strlen(texto);
     memcpy(text, t, characters + 1);
}

// int get_most_frequent_words(){
void print()
{   
    // char str[] ="- This, a sample string.";
    
    char * pch;
//   printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (text," ,.-");
  while (pch != NULL)
  {
   std::cout<<pch<<"\n";
    pch = strtok (NULL, " ,.-");
  }
    // cout<<"res"<<texto<<"\n";
}
 
// int get_char_count(){
    
//     return index;
 
// }
 
// void get_letter_count(){}
 
// void get_digit_count() {} //esto es para get contar digitos
 
// void get_word_count() {} // esto es para contar
 
// void add_word(){}// esto es para agregar palabras
 


};
 


int main()
 
{
    
    text_processor ts{"hp and asus have announced the first windows 10 pcs running on arm - snapdragon 835 - and they're boasting about instant-on, 22 hour battery life, and gigabit lte. these machines run full windows 10 - so not some crippled windows rt nonsense - and support 32bit x86 applications. microsoft hasn't unveiled a whole lot just yet about their x86-on-arm emulation, but ars did compile some information. "
    "the emulator runs in a just-in-time basis, converting blocks of x86 code to equivalent blocks of arm code. this conversion is cached both in memory (so each given part of a program only has to be translated once per run) and on disk (so subsequent uses of the program should be faster, as they can skip the translation). moreover, system libraries - the various dlls that applications load to make use of operating system feature - are all native arm code, including the libraries loaded by x86 programs. calling them compiled hybrid portable executables (or 'chippie' for short), these libraries are arm native code, compiled in such a way as to let them respond to x86 function calls."
    "while processor-intensive applications are liable to suffer a significant performance hit from this emulation - photoshop will work in the emulator, but it won't be very fast - applications that spend a substantial amount of time waiting around for the user - such as word - should perform with adequate performance. as one might expect, this emulation isn't available in the kernel, so x86 device drivers won't work on these systems. it's also exclusively 32-bit; software that's available only in a 64-bit x86 version won't be compatible. " };   


// ts.get_most_frequent_words().print();
 
ts.print();

// ts.get_least_frequent_words().print();
 


// cout << ts.get_char_count() << "\n";
 
// cout << ts.get_letter_count() << "\n";
 
// cout << ts.get_digit_count() << "\n";
 
// cout << ts.get_word_count() << "\n";
 


// cout << ts.get_frequency_by_word("emulator") << "\n";
 
// cout << ts.get_frequency_by_word("atari") << "\n";
 


// ts.print_all_frequencies();
 
// ts.add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus");
 
cout << "*****************\n";
 
// ts.print_all_frequencies();
 
/* should print something like:
 
hp: 2 occurrence(s)
 
asus: 6 occurrence(s)
 
while: 1 occurrence(s)
 
...
 
*/
 
 
return 0;
 
}
