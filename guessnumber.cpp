#include <iostream>
#include <vector>

int main()
{
	int gn, n;
	n=10, gn=3;
	if (gn==n)
	{
		std::cout << "you guess is the correct number" << '\n';
	}
	else
	{
		if (gn<n)
		{
			std::cout << "your number is less " << '\n';
		}
		else {
			std::cout << "your numbes is greather " << '\n';
		}
	}
}