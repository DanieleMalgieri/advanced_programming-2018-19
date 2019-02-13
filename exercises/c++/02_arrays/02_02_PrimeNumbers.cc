#include <iostream>

/*
Since the length of the array is known (fixed to 100), 
	i found correct to implement one big array in the heap, 
	without changing it's dimension.
Array dimension is kept constant.
*/

/* used function */
bool isitPrime(const int n);							//evaluate if a number is prime or not.
void print_array(const unsigned int* array, const std::size_t length);		//print an array
void findPrimes(unsigned int* array, const std::size_t length);			//iterate untill the n-th prime number is found


/* MAIN */
int main()
{
	std::size_t length = 100; //could easily become an input variable...
	
	//allocation of a const length array in the heap
	unsigned int* Primes{new unsigned int[length]}; //there are no real benifts in use of unsigned in this case...
	findPrimes(Primes, length);
	print_array(Primes, length);	
	delete[] Primes;
	return 0;	
}


/* FUNCTIONs DEFINITION */

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

void print_array(const unsigned int* array, const std::size_t length)
{
	std::cout<<"[ ";
	int index, i=0;
	while(i<length)
	{	
		std::cout<<array[i];
		if (i!=length-1) 
			std::cout<<", ";
		i++;
	}	
	std::cout<<" ] \n";
}

void findPrimes(unsigned int* Primes, const std::size_t length)
{	
	Primes[0] = {2};
	int i = 1;
	int n = 3;	
	while(i<length)
	{	
		bool marker = isitPrime(n);
		if(marker==true) 
		{			
			Primes[i]=n;
			i++;			
			}		
		n=n+2;  //i only need to evaluate even numbers
	}
}

