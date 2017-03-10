#include "Fraction.h"

int main(void) {
	//a main function that demonstrates the functionality of Fraction class
	Fraction f1(5,10);
	Fraction f2(6,90);
	Fraction f3 = f1/f2;
	f2 += f1;
	Fraction f4 = -(1 + f3 + 2);
	cout << "f1 = " << f1.simplify() << endl;
	cout << "f2++ = " << f2++ << endl;
	cout << "f2 = " << f2 << endl;
	cout << "f3 = " << f3.simplify() << endl;
	cout << "f4 = " << f4.simplify() << endl;
	cout << "f4 to int " << int(f4) << endl;
	Fraction integer = 5;
	cout << "integer = " << -integer.simplify() << endl;
	int x = 5 - f1;
	x += 2 += f2;
	cout << "x = " << x << endl;
	Fraction y = f3;
	y *= x /= -1;
	cout << "y = " << y << ", and simplified: " << y.simplify() <<endl;
	if (f1 >= f2) {
		cout << "f1 is bigger than f2" << endl;
	}
	else {
		cout << "f2 is bigger than f1" << endl;
	}
	if (Fraction(6,12) == Fraction(30,60)) {
		cout << "It is great!" << endl;
	}
	return 0;
}
