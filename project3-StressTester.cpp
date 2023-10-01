// Stress Tester File:
// Generates arrays of random length that are either letters or numbers
//

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0)); // Allows all the random num generator s to be different by generating differnt time stamps for them

	// Intizlizes the dynamic array and generates a random size for it
	int n = 0;
	n = rand() % 1000;
	cout << n << endl;
	string* arr = new string[n];
	bool nOrS = false;

	if (nOrS == true) {
		// Allocates random numbers to each element
		for (int i = 0; i < n; i++)
		{
			int newN = rand() % 10000000;

			string tempN = to_string(newN);
			arr[i] = tempN;
			//cout << arr[i] << endl;
		}
		delete[] arr;
	}
	else if (nOrS == false) {
		for (int i = 0; i < n; i++)
		{
			// Generats random string of characters for testing
			int numCh = rand() %3+1;
			string randLet = " ";
			for (int j = 0;  j < numCh; j++) {
				char currentChar = 'a' + rand() % 26;
				randLet += currentChar;
				//cout << randLet << endl;
			}

			arr[i] = randLet;
			//cout << arr[i] << endl;
		}
		delete[] arr;
	}
	return 0;
}
