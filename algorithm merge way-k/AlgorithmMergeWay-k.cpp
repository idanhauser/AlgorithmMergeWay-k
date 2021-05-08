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
		inData >> arr[i++];
	}
	inData.close();
}

int main()
{
	int* arr = nullptr;
	int size = 20;
	int k = 5;
	string inputName = "input.txt";
	string outputName = "output.txt";
	int parts = 4;

	/*
		cout << "Enter how many numbers there are in the file" << endl;
		cin >> size;

		cout << "Enter k";
		cin >> k;

		cout << "Enter name of input file:" << endl;
		cin >> inputName;

		cout << "Enter name of output file" << endl;
		cin >> outputName;*/
	arr = new int[size];
	ReadDataFromUser(size, "input.txt", arr);


	KWayMergeSort sortingRunner(arr, size, k, outputName);
	sortingRunner.ExcecuteKMergeSort();
	free(arr);
}

