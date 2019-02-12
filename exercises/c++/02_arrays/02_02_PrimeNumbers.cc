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
	int lenght = 10;
	std::cout << "insert test number: \n";
	n = getter<int>();
	int counter = 1;
	int Primes[n];
	Primes[0] = {2};
	forwhile(counter<lenght)
	{	
		bool marker = isitPrime(n);
		if(marker==true) Primes[counter++]=n;
		std::cout << n;
	}
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

