#include <iostream>
#include <vector>
#include <string>
using namespace std;

int adjacentElementsProduct(std::vector<int>  inputArray) {
    int sum =0;
    for (size_t i = 0; i < inputArray.size(); i++)
    {
        sum +=inputArray[i];
        sum++;
    }
       
}
int main()
{   int res;
    int inputArray[3, 6, -2, -5, 7, 3];
    std::cout << sizeof(inputArray) << '\n';
    // res = adjacentElementsProduct(*inputArray);
    std::cout << res << '\n';
}