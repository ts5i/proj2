// Tyler Storz
// Files: sort.cpp, sort.txt (program output)
// 11/16/16
// Lab2: Creates a 2-dimensional array and sorts
// 		 a user defined column in ascending order


#include <iostream>
using namespace std;

int** setArray(int, int);
int** sortArray(int**, int, int, int);
void  displayArray(int**, int, int);


int main()
{
	int row,
		col,
		sortC;
		
	int** intArray;
	
	cout << "Enter the size of the array: ";
	cin >> row >> col;
	cout << endl << endl;
	
	intArray = setArray(row, col);
	
	cout << endl << "Input Matrix:\n--------------";
	displayArray(intArray, row, col);
	
	cout << "\nEnter a column to sort: ";
	cin >> sortC;
	cout << endl << endl;
	
	intArray = sortArray(intArray, row, col, sortC);
	
	cout << endl << "Sorted Matrix:\n--------------";
	displayArray(intArray, row, col);
	
	delete [] intArray;
	
	return 0;
}

int** setArray(int r, int c)
{
	int val;
	int** a = new int* [r];
	
	for (int i = 0; i < r; i++)
	{
		cout << "Enter the array values for row " << (i+1) << ": ";
		a[i] = new int[c];
		
		for (int j = 0; j < c; j++)
		{
			cin >> val;
			a[i][j] = val;
		}
	}

	return a;
}

int** sortArray(int** a, int r, int c, int cSort)
{
	int** intArray = a;
	bool swap;
	
	int temp;  // compares column value
	
	// performs a bubble sort
	do
	{
		swap = false;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				// makes sure the number of rows isn't exceeded
				if ((i+1) < r)
				{
					// swaps current row with the following row
					if (intArray[i][cSort-1] > intArray[i+1][cSort-1])
					{
						temp = intArray[i][j];
						intArray[i][j] = intArray[i+1][j];
						intArray[i+1][j] = temp;
						swap = true;
					}
				}
			}
		}
	} while (swap);
	
	return intArray;
}

void displayArray(int** a, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		cout << endl;
		
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j] << " ";
		}
	}
}