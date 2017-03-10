#include "Fraction.h"

//finds the biggest common divider
static int biggestCommonDivider(int x, int y);
Fraction::Fraction(const int numinator, const int denuminator): m_numinator(numinator),m_denominator(denuminator)
//initialize a new Fraction
{}
Fraction::Fraction(const Fraction &otherFraction){
	//a copy c'tor, copies a fraction
	this->m_numinator = otherFraction.getNuminator();
	this->m_denominator = otherFraction.getDenominator();
}
Fraction Fraction::simplify() const{
	//takes a fraction and simplifies it, for example: 5/10 will become 1/2
	//find the biggest common divider
	int bcd = biggestCommonDivider(this->getNuminator(),this->getDenominator());
	return (Fraction((this->getNuminator() / bcd),(this->getDenominator() / bcd)));

}
//operator * between 2 fractions
Fraction Fraction::operator*(const Fraction& other) const{
	return (Fraction(this->getNuminator()*other.getNuminator(),this->getDenominator()*other.getDenominator()));
}
//operator + between 2 fractions
Fraction Fraction::operator+(const Fraction& other) const {
	return (Fraction((this->getNuminator()*other.getDenominator()) + (this->getDenominator()*other.getNuminator())
					,(this->getDenominator()*other.getDenominator())));
}
//operator - between 2 fractions
Fraction Fraction::operator-(const Fraction& other) const {
	return (Fraction((this->getNuminator()*other.getDenominator()) - (this->getDenominator()*other.getNuminator())
		, (this->getDenominator()*other.getDenominator())));
}
//operator / between 2 fractions
Fraction Fraction::operator/(const Fraction& other) const {
	return (Fraction(this->getNuminator()*other.getDenominator(),this->getDenominator()*other.getNuminator()));
}
//operator *= between 2 fractions
Fraction& Fraction::operator*=(const Fraction& other) {
	Fraction temp = this->operator*(other);
	*this = temp;
	return *this;
}
//operator += between 2 fractions
Fraction& Fraction::operator+=(const Fraction& other) {
	Fraction temp = this->operator+(other);
	*this = temp;
	return *this;
}
//operator -= between 2 fractions
Fraction& Fraction::operator-=(const Fraction& other) {
	Fraction temp = this->operator-(other);
	*this = temp;
	return *this;
}
//operator /= between 2 fractions
Fraction& Fraction::operator/=(const Fraction& other) {
	Fraction temp = this->operator/(other);
	*this = temp;
	return *this;
}
//operator * between a fraction and an integer
Fraction Fraction::operator*(const int num) const {
	return (Fraction(this->getNuminator()*num,this->getDenominator()));
}
//operator + between a fraction and an integer
Fraction Fraction::operator+(const int num) const {
	return (Fraction(this->getNuminator() + (this->getDenominator()*num), this->getDenominator()));
}
//operator - between a fraction and an integer
Fraction Fraction::operator-(const int num) const {
	return (Fraction(this->getNuminator() - (this->getDenominator()*num), this->getDenominator()));
}
//operator / between a fraction and an integer
Fraction Fraction::operator/(const int num) const {
	return (Fraction(this->getNuminator(), (this->getDenominator()*num)));
}
//operator *= between a fraction and an integer
Fraction& Fraction::operator*=(const int num){
	Fraction temp = this->operator*(num);
	*this = temp;
	return *this;
}
//operator += between a fraction and an integer
Fraction& Fraction::operator+=(const int num) {
	Fraction temp = this->operator+(num);
	*this = temp;
	return *this;
}
//operator -= between a fraction and an integer
Fraction& Fraction::operator-=(const int num) {
	Fraction temp = this->operator-(num);
	*this = temp;
	return *this;
}
//operator /= between a fraction and an integer
Fraction& Fraction::operator/=(const int num) {
	Fraction temp = this->operator/(num);
	*this = temp;
	return *this;
}
//operator ++ prefix adds the Fraction 1
Fraction& Fraction::operator++(){
	this->setNuminator(this->getNuminator() + this->getDenominator());
	this->setDenominator(this->getDenominator());
	return *this;
}
//operator -- prefix subs 1 from the Fraction
Fraction& Fraction::operator--(){
	this->setNuminator(this->getNuminator() - this->getDenominator());
	this->setDenominator(this->getDenominator());
	return *this;
}

//operator ++ postfix adds the Fraction 1
Fraction & Fraction::operator++(int){
	//save the original Fraction
	Fraction *f = new Fraction(this->getNuminator(),this->getDenominator());
	this->setNuminator(this->getNuminator() + this->getDenominator());
	this->setDenominator(this->getDenominator());
	return *f;
}
//operator -- postfix subs 1 from the Fraction
Fraction & Fraction::operator--(int){
	//save the original Fraction
	Fraction *f = new Fraction(this->getNuminator(), this->getDenominator());
	this->setNuminator(this->getNuminator() - this->getDenominator());
	this->setDenominator(this->getDenominator());
	return *f;
}
//returns true if both the fractions are the same
bool Fraction::operator==(const Fraction & other) const {
	if ((this->simplify().getNuminator() == other.simplify().getNuminator())
		&& (this->simplify().getDenominator() == other.simplify().getDenominator())) {
		return true;
	}
	return false;
}
//returns true if both the fractions are not the same
bool Fraction::operator!=(const Fraction & other) const {
	if ((this->simplify().getNuminator() == other.simplify().getNuminator())
		&& (this->simplify().getDenominator() == other.simplify().getDenominator())) {
		return false;
	}
	return true;
}
//f1 >= f2, returns true if f1 fraction is bigger or the same as f2 fraction 
bool Fraction::operator>=(const Fraction & other) const {
	float f1 = (float)*this;
	float f2 = (float)other;
	if (f1 >= f2) { return true; }
	return false;
}
//f1 <= f2, returns true if f1 fraction is smaller or the same is f2 fraction
bool Fraction::operator<=(const Fraction & other) const {
	float f1 = (float)*this;
	float f2 = (float)other;
	if (f1 <= f2) { return true; }
	return false;
}
//f1 > f2, returns true if f1 fraction is bigger than f2 fraction
bool Fraction::operator>(const Fraction & other) const {
	float f1 = (float)*this;
	float f2 = (float)other;
	if (f1 > f2) { return true; }
	return false;
}
//f1 < f2, returns true if f1 fraction is smaller than f2 fraction
bool Fraction::operator<(const Fraction & other) const {
	float f1 = (float)*this;
	float f2 = (float)other;
	if (f1 < f2) { return true; }
	return false;
}
//returns the counter number, for fraction f1 the returned value will be -f1
Fraction Fraction::operator-() const
{
	return Fraction(-this->getNuminator(),this->getDenominator());
}
//convert the fraction to double
Fraction::operator double() const{
	return (double)this->getNuminator() / (double)this->getDenominator();
}
//convert the fraction to float
Fraction::operator float() const {
	return (float)this->getNuminator() / (float)this->getDenominator();
}
//convert the fraction to int
Fraction::operator int() const {
	return (int)this->getNuminator() / (int)this->getDenominator();
}
Fraction::~Fraction() {

}

//prints the fraction to the ouput stream
ostream& operator<<(ostream & os, const Fraction & other)
{
	os << other.getNuminator() << '/' << other.getDenominator();
	return os;
}
//operator * between an integer and a fraction
Fraction operator*(int num, const Fraction& other) {
	return (Fraction(other.getNuminator()*num, other.getDenominator()));
}
//operator + between an integer and a fraction
Fraction operator+(int num, const Fraction& other) {
	return (Fraction(other.getNuminator() + (other.getDenominator()*num), other.getDenominator()));
}
//operator - between an integer and a fraction
Fraction operator-(int num, const Fraction& other) {
	return (Fraction(other.getNuminator() - (other.getDenominator()*num), other.getDenominator()));
}
//operator / between an integer and a fraction
Fraction operator/(int num, const Fraction& other) {
	return (Fraction(other.getNuminator(), (other.getDenominator()*num)));
}
//operator *= between an integer and a fraction
Fraction operator*=(int num, const Fraction & other)
{
	return other.operator*(num);
}
//operator += between an integer and a fraction
Fraction operator+=(int num, const Fraction & other)
{
	return other.operator+(num);
}
//operator -= between an integer and a fraction
Fraction operator-=(int num, const Fraction & other)
{
	return other.operator-(num);
}
//operator /= between an integer and a fraction
Fraction operator/=(int num, const Fraction & other)
{
	return other.operator/(num);
}

static int biggestCommonDivider(int x, int y) {
	//save the smaller integer so we don't have to run all iterations in the loop
	int smaller = abs(x) > abs(y) ? abs(y) : abs(x);
	int biggestCommonDivider = 1;
	//find the biggest common devider
	for (int i=1; i < smaller + 1; ++i) {
		if (x%i == 0 && y%i == 0) {
			biggestCommonDivider = i;
		}
	}
	return biggestCommonDivider;
}
