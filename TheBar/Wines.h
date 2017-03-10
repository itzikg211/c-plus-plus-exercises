#pragma once
#include "Wine.h"
#include <string>

static char* int2string(int num);

//Carmel Emerald Riesling Wine
class CarmelEmeraldRiesling : public Wine{
public :
	//C'tor, calling wine C'tor with the year and serving temperature
	CarmelEmeraldRiesling(int year) :Wine(year, 10) { this->setName("Carmel Emerald Riesling"); }
	//D'tor
	virtual ~CarmelEmeraldRiesling() {}
	//how to prepare the glass of wine
	virtual char* prepare() const {
		string op = "Just take the ";
		op = op + this->getName() + " and pour it into a glass. Serve it at the temperature of: " + int2string(this->getTemperature());
		char *to_ret = strdup(op.c_str());
		return to_ret;

	};
	//returning the name of the wine (contains the year)
	virtual char* getName() const {
		string name;
		name = name + Wine::getName() + " (year " + int2string(this->getYear()) + ")";
		char* to_ret = strdup(name.c_str());
		return to_ret;
	}
};
//Golan Smadar Wine
class GolanSmadar : public Wine {
public:
	//C'tor, calling wine C'tor with the year and serving temperature
	GolanSmadar(int year) :Wine(year, 8) { this->setName("Golan Smadar"); }
	//D'tor
	virtual ~GolanSmadar() {}
	//how to prepare the glass of wine
	virtual char* prepare() const {
		string op = "Just take the ";
		op = op + this->getName() + " and pour it into a glass. Serve it at the temperature of: " + int2string(this->getTemperature());
		char *to_ret = strdup(op.c_str());
		return to_ret;

	};
	//returning the name of the wine (contains the year)
	virtual char* getName() const {
		string name;
		name = name + Wine::getName() + " (year " + int2string(this->getYear()) + ")";
		char* to_ret = strdup(name.c_str());
		return to_ret;
	}
};
//Jordan Chardonnay Wine
class JordanChardonnay : public Wine {
public:
	//C'tor, calling wine C'tor with the year and serving temperature
	JordanChardonnay(int year) :Wine(year, 12) { this->setName("Jordan Chardonnay"); }
	//D'tor
	virtual ~JordanChardonnay() {}
	//how to prepare the glass of wine
	virtual char* prepare() const {
		string op = "Just take the ";
		op = op + this->getName() + " and pour it into a glass. Serve it at the temperature of: " + int2string(this->getTemperature());
		char *to_ret = strdup(op.c_str());
		return to_ret;

	};
	//returning the name of the wine (contains the year)
	virtual char* getName() const {
		string name;
		name = name + Wine::getName() + " (year " + int2string(this->getYear()) + ")";
		char* to_ret = strdup(name.c_str());
		return to_ret;
	}

};

//Chianti Wine
class Chianti : public Wine {
public:
	//C'tor, calling wine C'tor with the year and serving temperature
	Chianti(int year) :Wine(year, 17) { this->setName("Chianti"); }
	//D'tor
	virtual ~Chianti() {}
	//how to prepare the glass of wine
	virtual char* prepare() const {
		string op = "Just take the ";
		op = op + this->getName() + " and pour it into a glass. Serve it at the temperature of: " + int2string(this->getTemperature());
		char *to_ret = strdup(op.c_str());
		return to_ret;

	};
	//returning the name of the wine (contains the year)
	virtual char* getName() const {
		string name;
		name = name + Wine::getName() + " (year " + int2string(this->getYear()) + ")";
		char* to_ret = strdup(name.c_str());
		return to_ret;
	}
};
 //Jordan Mount Hermon Red Wine
class JordanMountHermonRed : public Wine {
public:
	//C'tor, calling wine C'tor with the year and serving temperature
	JordanMountHermonRed(int year) :Wine(year, 16) { this->setName("Jordan Mount Hermon Red"); }
	//D'tor
	virtual ~JordanMountHermonRed() {}
	//how to prepare the glass of wine
	virtual char* prepare() const {
		string op = "Just take the ";
		op = op + this->getName() + " and pour it into a glass. Serve it at the temperature of: " + int2string(this->getTemperature());
		char *to_ret = strdup(op.c_str());
		return to_ret;

	};
	//returning the name of the wine (contains the year)
	virtual char* getName() const {
		string name;
		name = name + Wine::getName() + " (year " + int2string(this->getYear()) + ")";
		char* to_ret = strdup(name.c_str());
		return to_ret;
	}
};
//Cabernet Sauvignon Wine
class CabernetSauvignon : public Wine {
public:
	//C'tor, calling wine C'tor with the year and serving temperature
	CabernetSauvignon(int year) :Wine(year, 18) { this->setName("Cabernet Sauvignon"); }
	//D'tor
	virtual ~CabernetSauvignon() {}
	//how to prepare the glass of wine
	virtual char* prepare() const {
		string op = "Just take the ";
		op = op + this->getName() + " and pour it into a glass. Serve it at the temperature of: " + int2string(this->getTemperature());
		char *to_ret = strdup(op.c_str());
		return to_ret;

	};
	//returning the name of the wine (contains the year)
	virtual char* getName() const {
		string name;
		name = name + Wine::getName() + " (year " + int2string(this->getYear()) + ")";
		char* to_ret = strdup(name.c_str());
		return to_ret;
	}
};
//Chadeau Margot Wine
class ChadeauMargot : public Wine {
public:
	//C'tor, calling wine C'tor with the year and serving temperature
	ChadeauMargot(int year) :Wine(year, 18) { this->setName("Chadeau Margot"); }
	//D'tor
	virtual ~ChadeauMargot() {}
	//how to prepare the glass of wine
	virtual char* prepare() const {
		string op = "Just take the ";
		op = op + this->getName() + " and pour it into a glass. Serve it at the temperature of: " + int2string(this->getTemperature());
		char *to_ret = strdup(op.c_str());
		return to_ret;

	};
	//returning the name of the wine (contains the year)
	virtual char* getName() const {
		string name;
		name = name + Wine::getName() + " (year " + int2string(this->getYear()) + ")";
		char* to_ret = strdup(name.c_str());
		return to_ret;
	}
};

static char* int2string(int num) {
	//creating a copy of the number
	int cpnum = num;
	int num_digits = 0;
	//finding the length of the number
	while (cpnum != 0){
		++num_digits;
		cpnum = cpnum / 10;
	}
	//allocating the memory for the string of the number
	char* str_num = new char[num_digits + 1];
	//creating the string
	for (int i = 0; i < num_digits; ++i) {
		str_num[num_digits - i - 1] = '0' + (num % 10);
		num = num / 10;
	}
	//adding the null terminator
	str_num[num_digits] = '\0';
	return str_num;
}
