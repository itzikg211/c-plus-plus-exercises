#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//An abstract class. Defines the functionality of every CalculatorOperation.
class CalculatorOperation {
public:
	//returns TRUE if the string is supported by the class, otherwise returns False.
	virtual bool supportsOperation(string op_string) = 0;
	//returns the number of required parameters for the operation.
	virtual int requiredParameters() const { return 0; };
	//returns the new result after applying the operation on the register(the number). 
	//Gets the current value of the register and a vector of strings representing the parameters for the operation.
	virtual double calcResult(double currVal, vector<string> parameters) const = 0;
};
