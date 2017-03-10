#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//The basic class that inherits exception class and defines its own action.
//It is an abstract class that forces one to implement what() method. 
class MyException : public exception {
public:
	MyException() {};
	~MyException() {};
	const char * what() const throw () = 0;
};

//This class inherits MyException class and sets it's own what() method.
//It triggers when one is trying so access an out of bound index.
class OutOfBoundsException : public MyException
{
public:
	OutOfBoundsException(){};
	~OutOfBoundsException() {};
	const char * what() const throw () {
		return "ERROR - Out Of Bounds Exception. It seems like you were trying to access an out of bounds index of your SafeArray";
	}
};

//This class inherits MyException class and sets it's own what() method.
//It triggers when one didn't set the size of the SafeArray.
class UndeclaredSizeException : public MyException
{
public:
	UndeclaredSizeException() {};
	~UndeclaredSizeException() {};
	const char * what() const throw () {
		return "ERROR - Undeclared Size Exception. You should declare the size of your SafeArray. Use setSize() method to do so.";
	}
};

//This class inherits MyException class and sets it's own what() method.
//It triggers when one is trying to change the size of the array or when one is setting up the size with a negative value.
class ChangeFixedSizeException : public MyException
{
public:
	ChangeFixedSizeException(){};
	~ChangeFixedSizeException(){};
	const char * what() const throw () {
		return "ERROR - Change Fixed Size Exception. Once declared the size of the array acts like a const," 
			"you can't change it's value. The size also must be positive integer.";
	}
};

