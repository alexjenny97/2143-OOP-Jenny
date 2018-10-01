/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Vector class with overloaded functions
*
*  @author Alex Jenny
*  @version 1.1 10/01/18
*  @github repo: https://github.com/2143_OOP_Jenny
*/

#include<fstream>
#include<iostream>
#include "myVector.h"
using namespace std;

/**
* Class uses arrays to imitate the vector class in the STL
*/

	// Default Constructor
	MyVector::MyVector()
	{
		arr = new int[10]; // default size decided in class
		numElements = 0; 
		size = 10;

	}

	// Destructor
	/*MyVector::~MyVector()
	{
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}
	}*/

	/**
	* Overloads [] so a vector can be treated like an array
	*/
	int& MyVector::operator[](int n)
	{
		if (n < 0 || n >= size) // then index is out of bounds
		{
			cout << "Index out of bounds   ";
			return *arr; // must return something
		}

		else // index is accessible
		{
			return arr[n];
		}
	}

	/**
	* overloads << so vector prints without a new line
	*/
	ostream& operator<< (ostream &out, const MyVector &V)
	{
		if (V.numElements == 0) // then vector is empty
		{
			out << "No elements to print";
		}

		else // print vector
		{
			out << "{";
			for (int i = 0; i < V.numElements - 1; i++) 
			{
				out << V.arr[i] << ", ";
			}
			out << V.arr[V.numElements - 1];
			out << "}";
		}

		return out;
	}

	/**
	* Overloads the + to add vectors element wise
	*/
	MyVector operator+(const MyVector &V,const MyVector &V1)
	{
		int iMax = 0; // size of Sum
		MyVector Sum = MyVector();

		if (V1.numElements <= V.numElements)
		{
			iMax = V.numElements;
		}

		else
		{
			iMax = V1.numElements;
		}

		// fill array
		for (int i = 0; i < iMax; i++)
		{
			if (i < V.numElements && i < V1.numElements) // then both vectors have an element
			{
				Sum.pushBack(V.arr[i] + V1.arr[i]);
			}

			else if (i < V.numElements) // then only V has an element and V1 is treated as 0
			{
				Sum.pushBack(V.arr[i]);
			}

			else if (i < V1.numElements) // then only V1 has an element and V is treated as 0
			{
				Sum.pushBack(V1.arr[i]);
			}
		}

		return Sum;
	}

	/**
	* Overloads the - operator
	*/
	MyVector operator-(const MyVector &V,const MyVector &V1)
	{
		MyVector Diff = MyVector();
		int iMax = 0;

		if (V1.numElements <= V.numElements)
		{
			iMax = V.numElements;
		}

		else
		{
			iMax = V1.numElements;
		}

		for (int i = 0; i < iMax; i++)
		{
			if (i < V.numElements && i < V1.numElements) // then both have elements
			{
				Diff.pushBack(V.arr[i] - V1.arr[i]);
			}

			else if (i < V.numElements) // then V1 is 0
			{
				Diff.pushBack(V.arr[i]);
			}

			else if (i < V1.numElements) // then V is 0
			{
				Diff.pushBack(-1 * V1.arr[i]);
			}
		}
		return Diff;
	}

	/**
	* Overloads * to do scalar vector multiplication
	*/
	MyVector operator*(const MyVector &V, int scalar)
	{
		MyVector product = MyVector();
		for (int i = 0; i < V.numElements; i++)
		{
			product.pushBack(scalar * V.arr[i]);
		}
		return product;
	}

	/**
	* Overloads * to multiply vectors
	*/
	MyVector operator*(const MyVector &V, const MyVector &V1)
	{
		int iMin = 0;
		MyVector Pro = MyVector();

		if (V.numElements <= V1.numElements)
		{
			iMin = V.numElements;
		}
		else
		{
			iMin = V1.numElements;
		}

		for (int i = 0; i < iMin; i++)
		{
				Pro.pushBack(V.arr[i] * V1.arr[i]);
			
		}
		return Pro;

	}

	/**
	* Overloads / to divide vectors
	*/
	MyVector operator/(const MyVector &V, const MyVector &V1)
	{
		int iMax = 0;
		MyVector Quo = MyVector();

		if (V.numElements <= V1.numElements)
		{
			iMax = V1.numElements;
		}
		else
		{
			iMax = V.numElements;
		}

		for (int i = 0; i < iMax; i++)
		{
			if (V.numElements < V1.numElements) // then V is 0
			{
				Quo.pushBack(0); 
			}

			if (V.numElements == V1.numElements)
			{
				if (V1.arr[i] == 0)
				{
					Quo.pushBack(0);
				}
				else
				{
					Quo.pushBack(V.arr[i] / V1.arr[i]);
				}
			}

			if (V.numElements > V1.numElements) // then V1 is 0
			{
				Quo.pushBack(0); // just push 0 instead of an error message
			}
		}
		return Quo;
	}

	/**
	* Overloads == to equate vectors
	*/
	bool operator==(const MyVector &V, const MyVector &V1)
	{
		bool equ = true; // true until found false

		if (V.numElements != V1.numElements) // then the sets cannot be equal
		{
			return false;
		}

		else // number of elements is the same
		{
			for (int i = 0; i < V.numElements; i++)
			{
				if (V.arr[i] != V1.arr[i]) // then we have found different elements
				{
					equ = false;
				}
			}
		}
		return equ;
	}


	/**
	* Overloads = so one vector can take on the values of another
	*/
	void MyVector::operator=(MyVector V)
	{
		if (numElements == V.numElements) // then just overwrite values
		{
			for (int i = 0; i < V.size; i++)
			{
				arr[i] = V.arr[i];
			}
		}

		else if (numElements < V.numElements) // then values will be added
		{
			for (int i = 0; i < numElements; i++) // overwrite spaces available
			{
				arr[i] = V.arr[i];
			}

			for (int i = numElements; i < V.numElements; i++) // add values
			{
				pushBack(V.arr[i]);
			}
		}

		else // values will be subtracted
		{
			for (int i = 0; i < V.numElements; i++) // overwrite available values
			{
				arr[i] = V.arr[i];
			}

			for (int i = V.numElements; i < numElements; i++) // pop off extra values
			{
				popBack();
			}
		}
	}

	/**
	* Overloads pushBack to accept/append an array
	*/
	void MyVector::pushBack(int *array, int numEls)
	{
		for(int i = 0; i < numEls; i++) // push each value of the array
		{
			pushBack(array[i]);
		}
	}



	/**
	* Returns the number of elements in the vector
	*
	* @return {int} : The number of elements
	*/
	int MyVector::NumElements()
	{
		return numElements;
	}

	/**
	* Returns the size or capacity of the array
	* 
	* @return {int} : The capacity of the array
	*/
	int MyVector::Size()
	{
		return size;
	}

	/**
	* pushes element to end of MyVector
	* if full, creates new array with 1.5 * size of old array
	* 
	* @param {int} val : The value to be added.
	*/
	void MyVector::pushBack(int val)
	{

		if (numElements ==size) 
		// then arr is full, need bigger one
		{
			// size must be int
			size = static_cast<int>(1.5 *size); 
			int* newArr = new int[size];

			// copy old array into new one
			for (int i = 0; i < numElements; i++)
			{
				newArr[i] = arr[i];
			}

			// delete old array
			delete []arr;
			arr = newArr;
			
			// add value to new array
			arr[numElements] = val;
			numElements++;
		}
		else
		{
			arr[numElements] = val;
			numElements++;
		}
	}

	/**
	* removes element from end of array
	* if empty does nothing
	*/
	void MyVector::popBack()
	{
		
		if (numElements > 0)
		// then act like the last value does not exist 
		// no need to create new array
		{
			numElements--;
		}

		if (numElements < .4 * size && numElements > 0)
		// then capacity should decrease to .5 * size
		{
			if (.5 * size > 10)
			// then capacity will no go below default
			{
				size = .5 * size;
			}

			else
			{
				// default size
				size = 10;
			}

			// create new array, copy values, delete old array
			int *newarr = new int[size];
			for (int i = 0; i < numElements; i++)
			{
				newarr[i] = arr[i];
			}
			delete arr;
			arr = newarr;
		}

	}

	/**
	* prints vector
	*
	* @param{ofstream} outfile: The outfile to print to
	*/
	void MyVector::Print(ostream & outfile)
	{
		if (numElements != 0)
			// then there are elements to print
		{
			for (int i = 0; i < numElements; i++)
			{
				outfile << arr[i] << " ";
			}
		}
		else // no elements to print
		{
			outfile << "No elements to print.";
		}
		outfile << "\n";
	}

	