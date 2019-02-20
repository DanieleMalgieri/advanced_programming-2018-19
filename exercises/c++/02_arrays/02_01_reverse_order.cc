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


template <typename T>
T* inizialize_array(const int length)
{
	T* _myArray{new T[length]};
	int i = 0;
	while(i<length)
	{
		std::cout<<"insert v[" <<i<<"] : ";
		_myArray[i++] = getter<T>();
	}
	std::cout<<"end inizialization;";
	return _myArray;
}
	
template <typename T>
void reverse(T* array, const int length)
{
	std::cout<<"[ ";
	int index, i=1;
	while(i<=length)
	{	
		index = length-i;
		std::cout<<array[index];
		if (i!=length) 
			std::cout<<", ";
		i++;
	}	
	std::cout<<" ] \n";
}

int main()
{	
	int length;
	char elem_type;
	std::cout<<"Hi, pls instert the lenght of your array:";
	std::cin >>length;
	std::cout<<"array has " << length << "arguments \n";
	std::cout<<"select if you want an array of double[d] or an array of integers [i]\n";
	elem_type = getter<char>();

	if (elem_type=='d')
	{
		double* d_array;
		d_array = inizialize_array<double>(length);
		std::cout << "\n I reversed your array: \n";
		reverse(d_array, length);
		delete[] d_array;
	} 
	else if(elem_type=='i')
	{	
		int* i_array;
		i_array = inizialize_array<int>(length);
		std::cout << "I reversed your array: \n";
		reverse(i_array, length);
		delete[] i_array;
	}
	else
	{ 
		std::cout<<"wrong input. The program will terminate! \n";
	}

	return 0;
}
