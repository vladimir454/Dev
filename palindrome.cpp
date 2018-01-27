
#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(std::string inputString) {
   
//    inputString = false;
    string res = "";
    for (int i=inputString.length()-1;i>=0; i--)
    {
        res +=inputString[i];
    }
    return res == inputString;

}

int main()
{
    int n;
    string str;
    std::cin>>str;
    cout<<checkPalindrome(str)<<endl;

    return 0;
}