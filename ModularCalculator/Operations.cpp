#pragma once
#include "Operations.h"
#include <string.h>

//calculates the factorial of a number. It is not recursive for more efficiency
static double fac(double val);

bool AddOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() > 3 || op_string.length() < 1)
		return false;
	if (strncmp("+", op_string.c_str(), strlen("+")) == 0)
		return true;
	if (strncmp("+=", op_string.c_str(), strlen("+=")) == 0)
		return true;
	if (strncmp("add", op_string.c_str(), strlen("add")) == 0)
		return true;
	if (strncmp("Add", op_string.c_str(), strlen("Add")) == 0)
		return true;
	return false;

}

bool SubOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() > 3 || op_string.length() < 1)
		return false;
	if (strncmp("-", op_string.c_str(), strlen("-")) == 0)
		return true;
	if (strncmp("-=", op_string.c_str(), strlen("-=")) == 0)
		return true;
	if (strncmp("sub", op_string.c_str(), strlen("sub")) == 0)
		return true;
	if (strncmp("Sub", op_string.c_str(), strlen("Sub")) == 0)
		return true;
	return false;

}


bool MulOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() > 3 || op_string.length() < 1)
		return false;
	if (strncmp("*", op_string.c_str(), strlen("*")) == 0)
		return true;
	if (strncmp("*=", op_string.c_str(), strlen("*=")) == 0)
		return true;
	if (strncmp("mul", op_string.c_str(), strlen("mul")) == 0)
		return true;
	if (strncmp("Mul", op_string.c_str(), strlen("Mul")) == 0)
		return true;
	return false;

}

bool DivOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() > 3 || op_string.length() < 1)
		return false;
	if (strncmp("/", op_string.c_str(), strlen("/")) == 0)
		return true;
	if (strncmp("/=", op_string.c_str(), strlen("/=")) == 0)
		return true;
	if (strncmp("div", op_string.c_str(), strlen("div")) == 0)
		return true;
	if (strncmp("Div", op_string.c_str(), strlen("Div")) == 0)
		return true;
	return false;

}

bool SqrtOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() != strlen("sqrt"))
		return false;
	if (strncmp("sqrt", op_string.c_str(), strlen("sqrt")) == 0)
		return true;
	if (strncmp("Sqrt", op_string.c_str(), strlen("Sqrt")) == 0)
		return true;
	return false;

}

bool PowOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() > 3 || op_string.length() < 1)
		return false;
	if (strncmp("^", op_string.c_str(), strlen("^")) == 0)
		return true;
	if (strncmp("^=", op_string.c_str(), strlen("^=")) == 0)
		return true;
	if (strncmp("pow", op_string.c_str(), strlen("pow")) == 0)
		return true;
	if (strncmp("Pow", op_string.c_str(), strlen("Pow")) == 0)
		return true;
	return false;

}

bool FactorialOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() == 1 || op_string.length() == 3)
	{
		if (strncmp("fac", op_string.c_str(), strlen("fac")) == 0)
			return true;
		if (strncmp("Fac", op_string.c_str(), strlen("Fac")) == 0)
			return true;
		if (strncmp("!", op_string.c_str(), strlen("!")) == 0)
			return true;
	}
	return false;
}

double FactorialOperation::calcResult(double currVal, vector<string> parameters) const {
	//if too many parameters
	if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
	//if the current value is negative
	if (currVal < 0) throw negativeNumber;
	//if the current value is 0 or 1 
	if (currVal == 0 || currVal == 1) return currVal;
	//do the factorial operation on the current value
	return fac(currVal);
}

//calculates the factorial of a number
static double fac(double val) {
	//init the first value
	double facVal = 1;
	//run until the the number 'val' and multiply each iteration
	for (int i = 2; i < val; ++i) {
		facVal *= i;
	}
	return facVal*val;
}

bool IntOperation::supportsOperation(string op_string)
{
	//check the string - if matches the operation
	if (op_string.length() != 3)
		return false;
	if (strncmp("int", op_string.c_str(), strlen("int")) == 0)
		return true;
	if (strncmp("Int", op_string.c_str(), strlen("Int")) == 0)
		return true;
	return false;
}

bool ModuloOperation::supportsOperation(string op_string) {
	//check the string - if matches the operation
	if (op_string.length() > 3 || op_string.length() < 1)
		return false;
	if (strncmp("%", op_string.c_str(), strlen("%")) == 0)
		return true;
	if (strncmp("%=", op_string.c_str(), strlen("%=")) == 0)
		return true;
	if (strncmp("mod", op_string.c_str(), strlen("mod")) == 0)
		return true;
	if (strncmp("Mod", op_string.c_str(), strlen("Mod")) == 0)
		return true;
	return false;

}
