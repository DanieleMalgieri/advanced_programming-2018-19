#include <iostream>
#include <cmath>

/* used functions */
void SieveOfEratosthenes(const int n);
template<typename T> T getter();


/* MAIN*/
int main() 
{ 
	std::cout << "please, insert the number up to which you want to extract prime numbers. \n";	
	int n = getter<int>(); 
	std::cout << "Prime numbers up to " << n << ":\n";
	SieveOfEratosthenes(n); 
	return 0; 
} 

void SieveOfEratosthenes(const int n) 
{ 
	bool prime[n+1];
	std::fill_n(prime,n+1,true);	
	for (int i=2; i<=std::sqrt(n); i++) 
		if (prime[i]) 
			for (int j=i*2; j<=n; j += i) prime[j] = false; 
	for (int i=2; i<=n; i++) if (prime[i]) std::cout << i << " ";
} 

template<typename T> T getter()
{
	T i;
	while(!(std::cin>>i))
	{
		std::cin.clear();
		std::cin.ignore();
	}
	return i;
}

