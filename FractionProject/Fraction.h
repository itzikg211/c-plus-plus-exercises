#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
	//mone
	int m_numinator;
	//mechane
	int m_denominator;
public:
	//c'tors
	Fraction(const int numinator,const int denuminator = 1);
	//copy c'tor
	Fraction(const Fraction &otherFraction);
	//d'tor
	~Fraction();
	
	//getters and setters
	
	void setNuminator(const int numinator) { m_numinator = numinator; }
	int getNuminator() const { return m_numinator; }
	void setDenominator(const int denominator) { m_denominator = denominator; }
	int getDenominator() const { return m_denominator; }
	
	//simplify the Fraction, for example: 5/10 will become 1/2
	Fraction simplify() const;
	//operators between Fractions
	
	Fraction operator* (const Fraction& other)const;
	Fraction operator+ (const Fraction& other)const;
	Fraction operator- (const Fraction& other)const;
	Fraction operator/ (const Fraction& other)const;
	Fraction& operator *= (const Fraction& other);
	Fraction& operator += (const Fraction& other);
	Fraction& operator -= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);
	//operators between a Fraction and an int
	
	Fraction operator* (const int num)const;
	Fraction operator+ (const int num)const;
	Fraction operator- (const int num)const;
	Fraction operator/ (const int num)const;
	Fraction& operator*= (const int num);
	Fraction& operator+= (const int num);
	Fraction& operator-= (const int num);
	Fraction& operator/= (const int num);
	//operators on a Fraction
	
	Fraction& operator++();
	Fraction& operator--();
	Fraction& operator++(int);
	Fraction& operator--(int);
	//boolean value operators between fractions
	
	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	//printing a Fraction
	friend ostream& operator<< (ostream& os, const Fraction& other);
	//returns the counter Fraction
	Fraction operator- () const;
	//Convertion operators
	//convert to double
	operator double() const;
	//convert to float
	operator float() const;
	//convert to int
	operator int() const;
};

//operators between an int and a Fraction
Fraction operator*(int num,const Fraction& other);
Fraction operator+(int num, const Fraction& other);
Fraction operator-(int num, const Fraction& other);
Fraction operator/(int num, const Fraction& other);
Fraction operator*=(int num, const Fraction& other);
Fraction operator+=(int num, const Fraction& other);
Fraction operator-=(int num, const Fraction& other);
Fraction operator/=(int num, const Fraction& other);
