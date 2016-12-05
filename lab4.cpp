// Tyler Storz
// Files: lab4.cpp
// 12/5/16
// Lab4: Uses a finite state machine recognizer to read data from a file
#include <iostream>
using namespace std;

int main()
{
	char c;			// character being read from file
	bool cr = true; // checks if there is a carriage return
	int state = 0;	// program begins at state 0
	
	// lookup table for each state
	int stateT[4][2] =
	{
		{0, 1}, // S0 : S0, S2
		{0, 1}, // S1 : S1, S2
		{0, 0}, // S2 : S0, S3
		{0, 0}  // S3 : S0, S3
	};
	
	// reads data one character at a time from a file
	// format :  lab4.exe < filename
	while (cin.get(c))
	{
		switch (state)
		{
			// data is read in using 4 states
			case 0: 
				// displays output from current state if there
				// is new input
				if (cr == true)
					cout << stateT[2][0];
				if (c == 'a')
				{
					state = 1;
					cout << stateT[0][0];
				}
				else if (c == 'b')
				{
					state = 2;
					cout << stateT[0][1];
				}
				break;
			case 1:
				if (c == 'a')
				{
					state = 1;
					cout << stateT[1][0];
				}
				else if (c == 'b')
				{
					state = 2;
					cout << stateT[1][1];
				}
				break;
			case 2:
				if (c == 'a')
				{
					state = 0;
					cout << stateT[2][0];
				}
				else if (c == 'b')
				{
					state = 3;
					cout << stateT[2][1];
				}
				break;
			case 3:
				if (c == 'a')
				{
					state = 0;
					cout << stateT[3][0];
				}
				else if (c == 'b')
				{
					state = 3;
					cout << stateT[3][1];
				}
				break;
		}
		
		cr = false;
		
		// start at state 0 after a line has been read
		if (c == '\n')
		{
			cout << endl;
			cr = true;
			state = 0;
		}
	}
	
	return 0;
}