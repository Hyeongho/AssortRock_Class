#include <iostream>

using namespace std;

/*
	1 - 1
	*****
	****
	***
	**
	* 

	1 - 2
	    *
	   **
	  ***
	 ****
	*****
	
	1 - 3
	*****
	 ****
	  ***
	   **
	    *
	
	1 - 4
	   *
	  ***
	 *****
	*******
	 *****
	  ***
	   *

	   7 - 4 = 3
	   7 - 5 = 2
	   7 - 6 = 1

*/

int main()
{
	for (int i = 0; i <= 10; i++)
	{
		cout << "i: " << i << endl;
	}

	cout << endl;

	for (int i = 1; i < 100; i *= 2)
	{
		cout << "i: " << i << endl;
	}

	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			cout << "i: " << i << endl;
		}
	}

	cout << endl;

	for (int i = 1; i <= 9; i++)
	{
		cout << "2 * " << i <<" = " << 2 * i << endl;
	}

	cout << endl;

	for (int i = 0; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}

		cout << endl;
	}

	cout << endl;

	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}

		cout << endl;
	}

	for (int i = 2; i <= 9; i++)
	{
		int j = 0;

		while (j < 10)
		{
			cout << i * j << endl;

			j++;
		}
	}

	cout << endl;

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > i; j--)
		{
			cout << " ";
		}

		for (int j = 0; j < (i * 2) + 1; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	return 0;
}