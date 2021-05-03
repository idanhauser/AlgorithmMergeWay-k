// AlgorithmMergeWay-k.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include "KWayMergeSort.h"
using namespace std;
using namespace KWayMergeAlgo;

void ReadDataFromUser(int size, const string& inFileName, int* arr)
{
	int i = 0;
	ifstream inData(inFileName);
	if (!inData)
	{
		cout << "wrong input." << endl;
		exit(2);
	}
	while (!inData.eof()) {
		inData >> arr[i];
	}
	inData.close();
}

int main()
{
	int* arr = nullptr;
	int size;
	int k;
	string inputName;
	string outputName;

	cout << "Enter how many numbers there are in the file" << endl;
	cin >> size;

	cout << "Enter k";
	cin >> k;

	cout << "Enter name of input file:" << endl;
	cin >> inputName;

	cout << "Enter name of output file" << endl;
	cin >> outputName;
	arr = new int[size];
	ReadDataFromUser(size, inputName, arr);


	KWayMergeSort sortingRunner(arr, size, k,outputName);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
