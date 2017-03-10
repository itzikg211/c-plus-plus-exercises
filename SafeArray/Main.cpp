#include "SafeArray.h"
//simple main function that demonstrates the SafeArray functionality
int main(void) {
	try {
		//create a new int safe array
		SafeArray<int> arr(3);
		//set it's values
		arr[2] = 4;
		*(++arr) = 2;
		*(arr) = 211;
		//a copy of array, using the copy c'tor 
		SafeArray<int> cpy = arr;
		cpy[0] = 10;
		//a copy of the copy. 
		SafeArray<int> cpy2 = cpy;
		*(cpy + 1) = 22;
		const int len = 2;
		//create a new char* array
		SafeArray<char*> array(len);
		array[0] = "millions";
		array[1] = "star";
		//print the safe arrays
		cout << arr << endl;
		cout << array << endl;
		//print the second 'array' value using pointers
		cout << *(array + 1) << endl;
		//trying out exceptions!
		array[2] = "fail";
		//another exception example
		array.setSize(-10);
	}
	//catching 'MyException' type of exception. 
	//One can just inherit this class and implement his own exception functionality.
	catch (MyException& err) {
		cout << err.what() << endl;
		return 1;
	}
	return 0;
}
