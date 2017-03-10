#pragma once
#include "MyCalc.h"
#define INT_MAX 2147483647
using namespace std;
//clears the input
void clear();

int main(void) {
	//the main object that contains the mapping between strings and operation and of course the register itself (the number).
	MyCalc calc;
	string opCode;
	vector<string> params;
	//printing hello message
	cout << "Welcome to the modular calculator." << endl;
	cout << "Supported commands: set,+,-,*,/,sqrt,pow,!,%,int(cast)" << endl;
	cout << ">>";
	cin >> opCode;
	//if got exit command
	if (opCode == "exit") return 0;
	//don't start until user sets the first value
	while (opCode != "set" && opCode != "Set") {
		cout << "First, you must set the register. Use 'set [number]' command." << endl;
		//clear input
		clear();
		cout << ">>";
		cin >> opCode;
		//if got exit command
		if (opCode == "exit") return 0;
	}
	string number_s;
	cin >> number_s;
	//convert the string to double and set the register's value
	calc.setReg(stod(number_s));
	cout << "Current value is: " << calc.getReg() << endl;
	cout << ">>";
	cin >> opCode;
	//run until user asks to exit
	while (opCode != "exit") {
		//set the register's value
		if (opCode == "set" || opCode == "Set") {
			cin >> number_s;
			calc.setReg(stod(number_s));
			cout << "Current value is: " << calc.getReg() << endl;
			//clear input
			clear();
			continue;
		}
		//if operation doesn't exist
		if (calc.checkOp(opCode) == false) {
			clear();
			cout << "'" << opCode << "' is an unknown operation. Please insert a valid operation (+,-,*,/,sqrt,pow,int,!)." << endl;
			cout << ">>";
			cin >> opCode;
			continue;
		}
		//get the right operation from the opcode the user entered
		CalculatorOperation *co = calc.getOperation(opCode);
		int reqParam = co->requiredParameters();
		vector<string> s(reqParam);
		//read the required parameters for the operation
		for (int i = 0; i < reqParam; ++i) {
			cin >> s[i];
		}
		//check if the Operation supports the opcode
		if (co->supportsOperation(opCode)) {
			try {
				//calculate the value of the register with using the operation with the parameters sent
				double result = co->calcResult(calc.getReg(), s);
				//update the register's value
				calc.setReg(result);
			}
			//catch error if occured
			catch (errors err) {
				switch (err)
				{
					//if wrong opcode
					case wrongOpCode:
						cout << "'" << opCode << "' is an unknown operation. Please insert a valid operation (+,-,*,/,sqrt,pow,int,!)." << endl;
						break;
					//if too many parameters
					case tooMuchParam:
						cout << "You inserted too many parameters to the " << opCode << " operation. There should be only " <<reqParam << " parameters" << endl;
						break;
					//if not enough parameters
					case notEnoughParam:
						cout << "You didn't insert enough parameters to the " << opCode << " operation. There should be " << reqParam << " parameters" << endl;
						break;
					//if tried to divide by zero
					case divisionZero:
						cout << "ERROR - You tried to divide by zero!" << endl;
						break;
					//if the number is negative
					case negativeNumber:
						cout << "Factorial (!) operation is not defined for negative numbers." << endl;
						break;
					default:
						break;
				}
			}
		}
		//print the current value of the register
		cout << "Current value is: " << calc.getReg() << endl;
		//clear input
		clear();
		cout << ">>";
		//read the next opcode
		cin >> opCode;
	}
	return 0;
}

//clear the input
void clear() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
