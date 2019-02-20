/*
## Matrix transpose

- Write a function that computes the transpose of a matrix. The matrix is represented by a simple `std::array<double,N>` where N is the total size of the matrix (i.e., number of rows times number of columns). The original array must be modified inside a function `transpose`.

*Hints*: 

- In C/C++, the matrices are accessed row-wise
- Don't try to use that for very big matrices, otherwise you go in stack overflow.
- You are not required to do the transpose *in place*
- Test with both square and rectangular matrices.
*/

#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>     //  srand
using namespace std;

template< typename T,size_t N> void printMatrix(array<T,N>& _matrix, int _row, int _col);
template<size_t N> array<int, N> randomMatrix(int row, int col);
template<size_t N> array<int, N> transposedMatrix(array<int, N>& _matrix, int _row, int _col);

int main()
{
	int random_element();

	const int row = 4;
	const int col = 6;
	const int size = row*col;

	array<int,size> matrix = randomMatrix<size>(row, col);
	printMatrix<int, size>(matrix, row, col);
	array<int, size> T_matrix = transposedMatrix(matrix, row, col);
	printMatrix<int, size>(T_matrix, col, row);
/*
	std::array<doulbe,N>* myMatrixpt = new std::array<double,sz>; //create a pointer to a matrix in the heap, of size sz
	printMatrix(myMatrixpt<doulbe,N>&, raw, column);
	return 0;
*/

	return 0;
}


template<typename T, size_t N>
void printMatrix(array<T,N>& _matrix, int _row, int _col)
{
	for(int i{0}; i<_row; i++)
	{
		for(int j{0}; j<_col; j++) cout << _matrix[i*_row+j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

template<size_t N>
array<int,N> randomMatrix(int _row, int _col)
{
		array<int,N> _matrix;
		srand((int)time(0)); //feed a srand function with current time as seed
		for(int i{0}; i<_row; i++)
			for(int j{0}; j<_col; j++) _matrix[i*_row+j] = rand()%100; 
		return _matrix;
}

template<size_t N>
array<int, N> transposedMatrix(array<int, N>& _matrix, int _row,int _col)
{
	array<int,N> _T_matrix;
	for(int i{0}; i<_row; i++)
		for(int j{0}; j<_col; j++) _T_matrix[j*_col + i] = _matrix[i*_row + j];
	return _T_matrix;
}

