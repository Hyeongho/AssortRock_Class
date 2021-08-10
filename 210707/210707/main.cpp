#include <iostream>

using namespace std;

int main()
{
	int Buf = 0;

	const int Attack = 0x1;		//		1
	const int Armor = 0x2;		//	   10
	const int HP = 0x4;			//	  100
	const int MP = 0x8;			//	 1000
	const int Critical = 0x10;	//	10000

	// Buf = 0 | 1 = 1

	Buf = Buf | Attack;

	// Buf = 0001 | 1000 = 0b1001 = 9

	Buf = Buf | MP;

	// Buf = 1001 | 10000 = 0b11001

	Buf = Buf | Critical;

	// Buf = 11001 | 00100 = 0b11101

	Buf = Buf | HP;

	cout << Buf << endl;

	cout << "Attack = " << (Buf & Attack) << endl;

	cout << "Armor = " << (Buf & Armor) << endl;

	cout << "HP = " << (Buf & HP) << endl;

	cout << "MP = " << (Buf & MP) << endl;

	cout << "Critical = " << (Buf & Critical) << endl;

	return 0;
}