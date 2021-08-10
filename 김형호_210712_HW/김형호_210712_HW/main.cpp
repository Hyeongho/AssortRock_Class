#include <iostream>

using namespace std;

int main()
{
	//1 - 1

	cout << "1 - 1" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	//1 - 2

	cout << "1 - 2" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	//1 - 3

	cout << "1 - 3" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	//1 - 4

	cout << "1 - 4" << endl;

	for (int i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			for (int j = 0; j < 3 - i; j++)
			{
				cout << " ";
			}

			for (int j = 0; j < i * 2 + 1; j++)
			{
				cout << "*";
			}
		}

		else if (i == 3)
		{
			for (int j = 0; j < i * 2 + 1; j++)
			{
				cout << "*";
			}
		}

		else
		{
			for (int j = 0; j < i - 3 ; j++)
			{
				cout << " ";
			}

			for (int j = 0; j < (7 - i) * 2 - 1; j++)
			{
				cout << "*";
			}
		}

		cout << endl;
	}

	return 0;
}