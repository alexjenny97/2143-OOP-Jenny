#include<fstream>
using namespace std;
/**
* Class uses arrays to imitate the vector class in the STL
*/
class MyVector
{

private:
	int numElements; //number of elements
	int *arr = nullptr; //dynamic array that holds elements
	int size; // capacity of array
	
public:
	/**
	* Default Constructor
	*
	* @return {MyVector}
	*/
	MyVector()
	{
		arr = new int[10]; // default size decided in class
		numElements = 0; 
		size = 10;

	}

	/**
	* Returns the number of elements in the vector
	*
	* @return {int} : The number of elements
	*/
	int NumElements()
	{
		return numElements;
	}

	/**
	* Returns the size or capacity of the array
	* 
	* @return {int} : The capacity of the array
	*/
	int Size()
	{
		return size;
	}

	/**
	* pushes element to end of MyVector
	* if full, creates new array with 1.5 * size of old array
	* 
	* @param {int} val : The value to be added.
	*/
	void pushBack(int val)
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
	void popBack()
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
	void Print(ofstream & outfile)
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

};