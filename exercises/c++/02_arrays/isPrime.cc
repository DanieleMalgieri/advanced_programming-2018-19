#include <iostream>

template <typename T>
T getter()
{
	T i;
	while(!(std::cin>>i))
	{
		std::cin.clear();
		std::cin.ignore();
	}
	return i;
}

bool isitPrime(const int n);

int main()
{
	int n = 0;
	std::cout << "insert test number: \n";
	n = getter<int>();
	bool marker = isitPrime(n);
	std::cout << "Is the number prime? " << marker <<"\n";
	return 0;	
}

bool isitPrime(const int n){
	bool marker = true;
	int i{2};
	for(i=2; i<n; i++)
	{	
		int reminder = n%i;
		if (reminder == 0) 
		{ 
			marker = false;
			break;
		}
	}	
	return marker;
}

