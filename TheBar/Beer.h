#pragma once
#include "Drink.h"

class Beer : public Drink{
private:
	//The name of the beer
	char* m_name;
public:
	//C'tor, set the name of the beer
	Beer(char* name) {
		this->m_name = strdup(name);
	}
	//D'tor, delete the name of the beer
	virtual ~Beer() { delete m_name; }
	//return the name of the beer
	virtual char* getName() const { return this->m_name; }
	//set the name of the beer
	virtual void setName(char* name) { this->m_name = name; }
	//return the way you prepare the beer
	virtual char* prepare() const { return "Well, all you need to do is pour it into a glass and serve.";}

};