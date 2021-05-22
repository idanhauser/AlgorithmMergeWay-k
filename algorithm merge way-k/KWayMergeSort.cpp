#include "KWayMergeSort.h"
#include "Pair.h"
#include <iostream>
#include <math.h> 



namespace KWayMergeAlgo {


	KWayMergeSort::KWayMergeSort(int* arr, int n, int k, string outputName) :_kParts(k), _nSize(n), _arr(new int[n]),
		_minHeap(k), _pfile(outputName), _newSortedArr(new int[n])
	{
		if (!_pfile)
		{
			cout << "wrong input" << endl;
			exit(2);
		}
		if (_kParts < 0)
		{
			cout << "wrong input" << endl;
			exit(2);
		}
		for (int i = 0; i < n; ++i)
		{
			_arr[i] = arr[i];
		}
	}

	KWayMergeSort::~KWayMergeSort()
	{
		delete[] _arr;
		delete[] _newSortedArr;
		_newSortedArr = nullptr;
		_arr = nullptr;
		_pfile.close();
	}

	void KWayMergeSort::ExcecuteKMergeSort()
	{
		KMergeSort(_arr, 0, _nSize - 1, _kParts);
		writeDataToFile();
	}

	int KWayMergeSort::getArraySize() const
	{
		return _nSize;
	}

	int KWayMergeSort::getK() const
	{
		return _kParts;
	}

	int* KWayMergeSort::getArray() const
	{
		return _arr;
	}

	void KWayMergeSort::setK(int k)
	{
		_kParts = k;
	}

	void KWayMergeSort::KMergeSort(int* arr, int left, int right, int k)
	{
		int len = right - left;

		if ((len < k) || (k == 1))
		{
			QuickSort(arr, left, right);
			return;
		}

		int parts = (len + 1) / k;
		int leftOver = (len + 1) % k;

		for (int i = 0; i < k - leftOver; i++)
		{

			KMergeSort(arr, left + (i * parts), left + ((i + 1) * parts) - 1, k);
		}

		for (int i = 0; i < leftOver; i++)
		{

			KMergeSort(arr, left + (k - leftOver + i) * parts + i,
				left + (k - leftOver + i + 1) * parts + i, k);
		}

		mergeKArraysWithHeap(arr, left, right, k);
	}




	void KWayMergeSort::mergeKArraysWithHeap(int* arr, int left, int right, int k)
	{
		int leftC = 0;
		int counter = 0;
		Pair newPair;
		Pair currPair;
		int newLeft;

		int len = right - left;
		int parts = (len + 1) / (k);
		int leftOver = (len + 1) % k;

		//Init the Heap		
		_minHeap.makeEmpty();

		for (int i = 0; i < k - leftOver; i++)
		{

			Pair item(arr[left + (i * parts)],
				(i * parts) + left,
				left + ((i + 1) * parts) - 1);

			_minHeap.insert(item);
		}

		for (int i = 0; i < leftOver; i++)
		{
			Pair item(arr[left + (k - leftOver + i) * parts + i],
				left + (k - leftOver + i) * parts + i,
				left + (k - leftOver + i + 1) * parts + i);

			_minHeap.insert(item);
		}

		while (!_minHeap.isEmpty())
		{
			currPair = _minHeap.DeleteMin();
			_newSortedArr[leftC] = currPair.getMinElement();
			leftC++;
			newLeft = currPair.getArrayIndexes().start + 1;
			counter++;

			if (newLeft < currPair.getArrayIndexes().end + 1)
			{
				newPair.setKey(arr[newLeft]);
				newPair.setIndexes(newLeft, currPair.getArrayIndexes().end);
				_minHeap.insert(newPair);
			}
		}

		for (int i = 0; i <= right - left; ++i)
		{
			_arr[left + i] = _newSortedArr[i];
		}
	}

	void KWayMergeSort::QuickSort(int* arr, int left, int right)
	{
		int pivot;

		if (left < right)
		{
			pivot = Partition(arr, left, right);
			QuickSort(arr, left, pivot - 1);
			QuickSort(arr, pivot + 1, right);
		}
	}


	int KWayMergeSort::Partition(int* arr, int left, int right)
	{
		int pivot = left;
		int indexStart = left;
		int indexEnd = right;

		while (indexStart != indexEnd)
		{
			if (pivot == indexStart)
			{
				if (arr[pivot] > arr[indexEnd]) {
					swap(arr + pivot, arr + indexEnd);
					pivot = indexEnd;
					indexStart++;
				}
				else
					indexEnd--;
			}
			else
			{
				if (pivot == indexEnd) {
					if (arr[pivot] < arr[indexStart]) {
						swap(arr + pivot, arr + indexStart);
						pivot = indexStart;
						indexEnd--;
					}
					else
						indexStart++;
				}
			}

		}
		return pivot;
	}



	void KWayMergeSort::swap(int* pnum1, int* pnum2)
	{
		double temp = *pnum1;
		*pnum1 = *pnum2;
		*pnum2 = temp;
	}
	void KWayMergeSort::writeDataToFile()
	{
		if (!_pfile)
		{
			cout << "wrong input." << endl;
			exit(2);
		}
		if (_pfile.is_open())
		{
			for (int i = 0; i < _nSize; i++)
			{
				_pfile << _arr[i] << endl;
			}
			_pfile.close();
		}


	}


	ostream& operator<<(ostream& os, const KWayMergeSort& sortingAlgo)
	{
		int* pArr = sortingAlgo.getArray();
		int arrSize = sortingAlgo.getArraySize();
		os << "The Sorted array: \n";
		for (int j = 0; j < arrSize; ++j)
		{
			os << pArr[j] << "\t";
		}
		return os;
	}
}

