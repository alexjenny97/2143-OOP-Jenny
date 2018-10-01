/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Overload varoius member functions
*
*  @author Alex Jenny
*  @version 1.1 10/01/18
*  @github repo: https://github.com/2143_OOP_Jenny
*/

#pragma once
#include<iostream>

using namespace std;


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
	MyVector();
	
	/**
	* Destructor
	*/
	// ~MyVector();

	/**
	* Overloads [] so a vector can be treated like an array
	*
	* @param{int} n : the index
	* @return{int&} : the address of the value
	*/
	int& operator[](int n);

	/**
	* overloads << so vector prints without a new line
	*
	* @param{ostream, MyVector} &out,const &V : standard output and Vector being printed
	* @return{ostream&} : output stream
	*/
	friend ostream& operator<< (ostream &out, const MyVector &V);

	/**
	* Overloads the + to add vectors element wise
	* 
	* @param{MyVector, MyVector} V, V1 : the two addens
	* @return{MyVector} : sum
	*/
	friend MyVector operator+(const MyVector &V,const MyVector &V1);

	/**
	* Overloads the - operator
	*
	* @param{MyVector, MyVector} V, V1 : minuend, subtrahend
	* @return {MyVector} : difference
	*/
	friend MyVector operator-(const MyVector &V, const MyVector &V1);

	/**
	* Overloads * to do scalar vector multiplication
	* 
	* @param{MyVector, int} V, scalar : vector, scalar
	* @return{MyVector} : product
	*/
	friend MyVector operator*(const MyVector &V, int scalar);

	/**
	* Overloads * to multiply vectors
	*
	* @param{MyVector, MyVector} V, V1 : the two factors
	* @return{MyVector} : product
	*/
	friend MyVector operator*(const MyVector &V, const MyVector &V1);

	/**
	* Overloads / to divide vectors
	*
	* @paran{MyVector, MyVector} V, V1 : divadned, divisor
	* @return{MyVector} : quotient
	*/
	friend MyVector operator/(const MyVector &V, const MyVector &V1);

	/**
	* Overloads == to equate vectors
	*
	*@param{MyVector, MyVector} V, V1 : two vectors
	* @return{bool} : true if each elemnt is the same
	*/
	friend bool operator==(const MyVector &V, const MyVector &V1);

	/**
	* Overloads = so one vector can take on the values of another
	* 
	* @param{MyVector} V : new vector
	*/
	void operator=(MyVector V);
	
	/**
	* Overloads pushBack to accept/append an array
	* 
	* @param{int *, int} array, numEls : new array of values, numElements
	*/
	void pushBack(int *array, int numEls);
	
	/**
	* Returns the number of elements in the vector
	*
	* @return {int} : The number of elements
	*/
	int NumElements();

	/**
	* Returns the size or capacity of the array
	*
	* @return {int} : The capacity of the array
	*/
	int Size();

	/**
	* pushes element to end of MyVector
	* if full, creates new array with 1.5 * size of old array
	*
	* @param {int} val : The value to be added.
	*/
	void pushBack(int val);

	/**
	* removes element from end of array
	* if empty does nothing
	*/
	void popBack();

	/**
	* prints vector
	*
	* @param{ofstream} outfile: The outfile to print to
	*/
	void Print(ostream & outfile);

	/**
	* removes duplicates
	* 
	* @param{MyVector, int} V, val : vector, value about to be inserted
	*/
	void remove(MyVector V, int val);
};
