#pragma once
#include "Operations.h"
#include <map>
#include <algorithm>
//The calculator class, contains the register (the number) and a map between every string opcode to it's CalculatorOperation.
class MyCalc {
private:
	//The number itself (the register).
	double m_register;
	//A map which maps between a vector of strings (operation opcodes) and a CalculatorOperation. 
	map<vector<string>, CalculatorOperation*> m_map;
public:
	//The c'tor of MyCalc class. It initializes the map that contains the strings and their matching calculator operation.
	MyCalc();
	//The d'tor, deletes the CalculatorOperations that were allocated. 
	~MyCalc();
	//returns the value of the register (the number).
	double getReg() { return this->m_register; }
	//sets the value of the register (the number).
	void setReg(double val) { this->m_register = val; }
	//returns the 'CalculatorOperation' according the string.
	CalculatorOperation* getOperation(string str) { 
		//iterate through the map and check if 'str' string is in the vector of strings.
		for (map<vector<string>, CalculatorOperation*>::iterator it = this->m_map.begin(); it != this->m_map.end(); ++it) {
			if(it->second->supportsOperation(str)){
				return it->second;
			}
		}
		return NULL;
	}
	//returns TRUE if the opcode is defined in the map, otherwise it returns FALSE.
	bool checkOp(string opcode) {
		//iterate through the map and check if the opcode exist.
		for (map<vector<string>, CalculatorOperation*>::iterator it = this->m_map.begin(); it != this->m_map.end(); ++it) {
		//finds the 'opcode' string in the vector 
			if(find(it->first.begin(),it->first.end(),opcode) != it->first.end()) {
				return true;
			}
		}
		return false;
	}
};
