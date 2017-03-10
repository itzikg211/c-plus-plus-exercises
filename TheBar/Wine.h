#pragma once
#include "Drink.h"

class Wine : public Drink{
private:
	//The year the wine was created 
	int m_year;
	//The name of the wine
	char* m_name;
	//the temperature the wine should be served at
	int m_temperature;
public:
	//C'tor of a wine, setting the year of the wine
	Wine(int year, int temperature) :m_year(year),m_temperature(temperature) {}
	//D'tor of wine, deleting the name of the wine
	virtual ~Wine() {
		delete m_name;
	}
	//abstract function that shows the way a glass of wine was prepared
	virtual char* prepare() const = 0;
	//returns the name of the wine
	virtual char* getName() const { return this->m_name; }
	//set the name of the wine
	virtual void setName(char* name) { this->m_name = strdup(name); }
	//returns the year of the wine
	int getYear() const { return this->m_year; }
	//sets the year of the wine
	void setYear(int year) { this->m_year = year; }
	//returns the temperature the wine should be served at
	int getTemperature() const { return this->m_temperature; }
	//set the temperature the wine should be served at
	void setTemerature(int temperature) { this->m_temperature = temperature; }
};

