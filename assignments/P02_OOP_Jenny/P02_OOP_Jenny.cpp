#include<iostream>
#include "myVector.h"

using namespace std;
int main()
{
	MyVector v1 = MyVector();
	MyVector v2 = MyVector();

	v1.pushBack(8);
	// v1 contains: [8]
	cout << "v1: " << v1 << "\n";

	v2.pushBack(10);
	v2.pushBack(20);
	v2.pushBack(30);
	// v2 contains: [10,20,30]
	cout << "v2: " << v2 << "\n";

	// Declare some int array
	int A[] = { 1,2,3,4,5 };


	v1.pushBack(A, 5);
	// v1 contains: [8,1,2,3,4,5]
	cout << "v1: " << v1 << "\n";

	v1 = v1 + v2;
	// v1 contains: [18,21,32,3,4,5]
	cout << "v1: " << v1 << "\n";
	// would print: [18,21,32,3,4,5] to standard out.

	cout << v1[2] << endl;
	// would print: 32 to standard out.


	v2 = v2 * 3;
	// v2 contains: [30,60,90]
	cout << "v2: " << v2 << "\n";

	v2 = v2 * v1;
	// v2 contains: [540,1260,2880]
	cout << "v2: " << v2 << "\n";

	v2[2] = 100;
	// v2 contains: [540,1260,100]
	cout << v2[2] << "\n";

	// What about strings??
	system("pause");
}