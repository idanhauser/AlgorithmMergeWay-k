// AlgorithmMergeWay-k.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include "KWayMergeSort.h"
using namespace std;
using namespace KWayMergeAlgo;

bool checkInput(char c)
{
	int digit = c - '0';
	if ((digit >= 0) && (digit <= 9))
	{
		return true;
	}
	else
	{
		if (c == '\n' || c == ' ')
			return false;
		else {
			cout << "Wrong Input";
			exit(1);
		}
	}

}
void ReadDataFromUser(int size, const string& inFileName, int* arr)
{
	int counter = 0;
	bool neg = false;
	int index = 0;
	
	ifstream inData(inFileName);
	string inTxt;
	
	if (!inData)
	{
		cout << "wrong input." << endl;
		exit(2);
	}
	
	while (!inData.eof()) {
		inData >> inTxt;
		counter++;
		
		int numBuilder = 0;
		for (int i = 0; i < inTxt.size(); ++i)
		{
			if(i==0 && inTxt.at(0)=='-')
			{
				neg = true;
				continue;
			}
			if (checkInput(inTxt.at(i)));
			numBuilder = numBuilder * 10 + int(inTxt.at(i)) - '0';
		}
	
		if (!neg)
		{
			arr[index++] = numBuilder;
		}
		else
		{
			arr[index++] = -numBuilder;
		}
		neg = false;
	}
	if(counter!=size)
	{
		cout << "wrong input." << endl;
		exit(2);
	}
	inData.close();
}


int main()
{
	int* arr = nullptr;
	int size;
	int k;
	string inputName;
	string outputName ;

		cout << "Enter how many numbers there are in the file" << endl;
		cin >> size;

		cout << "Enter K" <<endl;
		cin >> k;
	
		cout << "Enter name of input file:" << endl;
		cin >> inputName;

		cout << "Enter name of output file" << endl;
		cin >> outputName;
	arr = new int[size];
	ReadDataFromUser(size, inputName, arr);
	if (k <= 0)
	{
		cout << "wrong input." << endl;
		exit(2);
	}

	KWayMergeSort sortingRunner(arr, size, k, outputName);
	sortingRunner.ExcecuteKMergeSort();
	delete[] arr;
}

