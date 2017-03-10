#pragma once
#include "CalculatorOperation.h"
#include <string>

//the errors that may occur using the operations.
enum errors {
	wrongOpCode,//wrong opcode
	tooMuchParam,//too many parameters were delivered to the operation
	notEnoughParam,//not enough parameters were delivered to the operation
	divisionZero,//trying to divide by zero
	negativeNumber//negative number - won't run the factorial on it.
};

//+ (add) operation
class AddOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 1; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
		//if there are no parameters
		if (parameters.size() == 0) throw notEnoughParam;

		//convert string parameter to double
		double param = (double)stod(parameters[0]);
		//do the + operation
		return currVal + param;
	}
};

//- (sub) operation
class SubOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 1; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
		//if there are no parameters
		if (parameters.size() == 0) throw notEnoughParam;
		//convert string parameter to double
		double param = (double)stod(parameters[0]);
		//do the - operation
		return currVal - param;
	}
};

//* (multiply) operation.
class MulOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 1; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
		//if there are no parameters
		if (parameters.size() == 0) throw notEnoughParam;
		//convert string parameter to double
		double param = (double)stod(parameters[0]);
		//do the * operation
		return currVal * param;
	}
};

// / (divide) operation.
class DivOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 1; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
		//if there are no parameters
		if (parameters.size() == 0) throw notEnoughParam;
		//convert string parameter to double
		double param = (double)stod(parameters[0]);
		//do the / operation
		return (param == 0) ? throw divisionZero: (currVal / param);
	}
};

//sqrt operation.
class SqrtOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 0; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() != this->requiredParameters()) throw tooMuchParam;
		//do the sqrt operation
		return sqrt(currVal);
	}
};

//^ (power) operation.
class PowOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 1; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
		//if there are no parameters
		if (parameters.size() == 0) throw notEnoughParam;
		//convert string parameter to double
		double param = (double)stod(parameters[0]);
		//do the power operation
		return pow(currVal, param);
	}
};

//! (factorial) operation.
class FactorialOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 0; }
	virtual double calcResult(double currVal, vector<string> parameters) const;
};

//% (modulo) operation.
class ModuloOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 1; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
		//if there are no parameters
		if (parameters.size() == 0) throw notEnoughParam;
		//convert string parameter to double
		double param = (double)stod(parameters[0]);
		//returns the modulo of floats (built in math library)
		return fmod(currVal, param);
	}
};

//int (casting to integer) operation.
class IntOperation : public CalculatorOperation {
public:
	virtual bool supportsOperation(string op_string);
	virtual int requiredParameters() const { return 0; }
	virtual double calcResult(double currVal, vector<string> parameters) const {
		//if too many parameters
		if (parameters.size() > this->requiredParameters()) throw tooMuchParam;
		//do the casting to integer operation
		return (double)((int)currVal);
	}
};
