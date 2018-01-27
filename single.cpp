#include <iostream>
using namespace std;
int centuryFromYear(int year)
{   if(year % 100 != 0) 
    {
        return (year / 100) + 1;
    }else
    {
        return year / 100;
    }
}
int main()
{
  int n,y;
    cin>>n;
  y=centuryFromYear(n);
    cout<<y<<endl;
  return 0;   
}