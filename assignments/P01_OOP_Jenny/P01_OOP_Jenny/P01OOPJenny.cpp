/**
* Course: CMPS- 2143- OOP
*
* Purpose: MyVector class using arr as storage

* @author Alex Jenny
* @version 1.1 09/14/17
*/

#include "MyVector.cpp"
#include<fstream>

using namespace std;

int main()
{
	ofstream outfile;
	outfile.open("outfile.txt");
	
	// create empty vector 
	MyVector V;
	outfile << "current numElements " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\nelements: ";
	V.Print(outfile);

	// fill vector, numElements grows but size stays constant
	for (int i = 0; i < 10; i++)
	{
		V.pushBack(i);
	}
	outfile << "current numElements: " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\nelements: ";
	V.Print(outfile);

	// add element (10) to back of full vector, size grows 1.5 times
	V.pushBack(10);
	outfile << "current numelements: " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\n";
	outfile << "elements: ";
	V.Print(outfile);

	// remove num from back of vector, numElements decreases by one but size stays constant
	V.popBack();
	outfile << "current numElements: " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\nelements: ";
	V.Print(outfile);

	// adds 10 elements, size is now 22, numElements is 15
	for (int i = 0; i < 10; i++)
	{
		V.pushBack(V.NumElements() +i);
	}
	outfile << "current numElements: " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\nelements: ";
	V.Print(outfile);

	// removes 5 elements, size doesnt change
	for (int i = 0; i < 5; i++) // 
	{
		V.popBack();
	}
	outfile << "current numElements: " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\nelements: ";
	V.Print(outfile);


	// removes 10 elements,  numElements = 5, size = 11
	for (int i = 0; i < 10; i++)
	{
		V.popBack();
	}

	outfile << "current numElements: " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\nelements: ";
	V.Print(outfile);

	// removes one element, size set back to default (10) size
	V.popBack();
	outfile << "current numElements: " << V.NumElements() << "\n";
	outfile << "current size: " << V.Size() << "\nelements: ";
	V.Print(outfile);

	outfile.close();

	system("pause");
	
    return 0;
}

