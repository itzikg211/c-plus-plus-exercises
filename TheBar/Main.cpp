#include "Beer.h"
#include "Wines.h"
#define SHELF_SIZE 11
#define INT_MAX 2147483647
//The function deletes the stock of drinks
void del(Drink **stock);
//The function lists the options in the bar 
void list_options(Drink **stock);
//main function
int main(void) {
	//integer representing the last drink that was ordered
	int lastDrink = 0;
	//integer representing the last operation that was asked
	int lastOp = 0;
	//initializing the stock in the bar
	Drink* stock[SHELF_SIZE];
	stock[0] = new Beer("Heineken");
	stock[1] = new Beer("Goldstar");
	stock[2] = new Beer("Maccabi");
	stock[3] = new Beer("Tuborg");
	stock[4] = new CarmelEmeraldRiesling(1986);
	stock[5] = new GolanSmadar(1989);
	stock[6] = new JordanChardonnay(1997);
	stock[7] = new Chianti(1997);
	stock[8] = new JordanMountHermonRed(1994);
	stock[9] = new CabernetSauvignon(1997);
	stock[10] = new ChadeauMargot(1997);
	cout << "What can I get you, sir? (0 - list options)" << endl;
	cin >> lastOp;
	//running while no one asked to leave the bar
	while (lastOp != 100) {
		//list operations avaliable
		if (lastOp == 0) {
			list_options(stock);
		}
		//A drink was ordered
		if (lastOp <= SHELF_SIZE && lastOp > 0)
		{
			lastDrink = lastOp - 1;
			if (lastOp >= 1 && lastOp <= 4) {
				cout << "One " << stock[lastDrink]->getName() << " coming up, sir." << endl;
			}
			else {
				cout << "A glass of " << stock[lastDrink]->getName() << " coming up, sir." << endl;
			}
		}
		//display how you prepared the last drink
		if (lastOp == 99) {
			if (lastDrink == 0) {
				cout << "You should order a drink first ;)" << endl;
			}
			else {
				cout << "You ordered a " << stock[lastDrink]->getName() << "." << endl;
				cout << stock[lastDrink]->prepare() << endl;
			}
		}
		//illeagal operations
		if (lastOp < 0 || lastOp > 100)
		{
			cout << "This is an illeagal operation. (0 - list options)" << endl;
		}
		cout << "What can I get you, sir? (0 - list options)" << endl;
		//clear input in case the operation was illeagal.
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cin >> lastOp;
	}
	cout << "Bar is closed. Good night." << endl;
	//delete the allocated memory of the stock in the bar
	del(stock);
	return 0;
}

void del(Drink **stock) {
	//delete each stock
	for (int i = 0; i < SHELF_SIZE; ++i) {
		delete stock[i];
	}
}

void list_options(Drink **stock) {
	//display operations
	cout << "(0)\tlist options" << endl;
	for (int i = 0; i < SHELF_SIZE; ++i) {
		cout << "(" << i + 1 << ")\t" << stock[i]->getName() << endl;
	}
	cout << "(99)\tHow did you prepare my last drink?" << endl;
	cout << "(100)\tLeave the bar" << endl;
}
