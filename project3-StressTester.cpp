// Stress Tester File:
// Generates arrays of random length that are either letters or numbers
//

#include <iostream>
#include <string>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	int n = 0;
	n = rand() % 10000+1;
	cout << n << endl;
	string* arr = new string[n];

	for (int i = 0; i < n; i++) 
	{
		int newN = rand() % 1000;

		string tempN = to_string(newN);
		arr[n] = tempN;

		cout << arr[n] << endl;
	}
	delete[] arr;
	return 0;
}