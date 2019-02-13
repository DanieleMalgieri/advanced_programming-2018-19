#include <iostream>

bool isitPrime(const int n);

int main()
{
	int n = 3;
	int length = 100;
	int counter = 1;
	int Primes[length];
	Primes[0] = {2};
	while(counter<length)
	{	
		bool marker = isitPrime(n);
		if(marker==true) 
		{			
			Primes[counter]=n;
			counter++;			
			std::cout  << "("<< counter << "): "<< n<< "\n";
			}		
		n=n+2;
	}
	// std::cout<<counter;
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

