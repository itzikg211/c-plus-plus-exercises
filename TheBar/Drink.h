#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
//An interface of a drink
class Drink {

public:
	//C'tor
	Drink() {}
	//D'tor
	virtual ~Drink() {}
	//pure virtual function, shows how a drink was prepared
	virtual char* prepare() const = 0;
	//return the name of the drink
	virtual char* getName() const { return "drink"; }



};