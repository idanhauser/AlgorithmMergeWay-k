#include "KWayMergeSort.h"

#include <algorithm>

#include "Pair.h"
#include <math.h> 
#include <iostream>



namespace KWayMergeAlgo {


	KWayMergeSort::KWayMergeSort(int* arr, int n, int k, string outputName) :_kParts(k), _nSize(n), _arr(new int[n]),
		_minHeap(k), _pfile(outputName), _newSortedArr(new int[n])
	{
		if (!_pfile)
		{
			cout << "wrong input" << endl;
			exit(2);
		}
		for (int i = 0; i < n; ++i)
		{
			_arr[i] = arr[i];
		}
	}

	void KWayMergeSort::ExcecuteKMergeSort()
	{
		KMergeSort(_arr, 0, _nSize - 1, _kParts);
		for (int i = 0; i < _nSize; ++i)
		{
			cout << _arr[i] << endl;
		}
	}

	int KWayMergeSort::getArraySize() const
	{
		return _nSize;
	}

	int KWayMergeSort::getK() const
	{
		return _kParts;
	}

	void KWayMergeSort::setK(int k)
	{
		_kParts = k;
	}

	int* KWayMergeSort::getArray() const
	{
		return _arr;
	}

	void KWayMergeSort::KMergeSort(int* arr, int left, int right, int k)
	{
		int len = right - left + 1;
		if (len < k)
		{
			QuickSort(arr, left, right);
			return;
		}
		int m = left + (right - left) / k;
		int leftOver = len % k;
		for (int i = 0; i < k; i++) {
			//KMergeSort(arr, left, m, k);
			if (leftOver && (left + (i * m + (m)-1 + m) >= _nSize))
			{
				KMergeSort(arr, (i * m) + left, left + (i * m + (m)), k);
				mergeKArraysWithHeap(arr, (i * m) + left, _nSize - 1, k);
			}
			else 
			{
				if (left + (i * m + (m)-1) < _nSize)
				{
					KMergeSort(arr, (i * m) + left,
						left + (i * m + (m)-1), k);
				}
				//else
				//{//is that ok? i am not sure
				//	KMergeSort(arr, (i * m) + left, _nSize - 1, k);
				//}
				cout << "left = " << left << " right = " << right << endl;
			}
		}
		mergeKArraysWithHeap(arr, left, right, k);
		//	cout << "left = " << left << " right = " << right << endl;	
		//KMergeSort(arr, m + 1, right, k);
	}

	KWayMergeSort::~KWayMergeSort()
	{
		delete[] _arr;
		_arr = nullptr;
		_pfile.close();
	}

	void KWayMergeSort::mergeKArraysWithHeap(int* arr, int left, int right, int k)
	{
		int leftC = left;
		int counter = 0;
		Pair newPair;
		Pair currPair;
		int len = right - left + 1;
		int newLeft;
		int m = len / k + (len%k);
		//m += len % k;
		Pair item;
		//Init the Heap		
		_minHeap.makeEmpty();
		//todo: fix

		for (int i = 0; i < k; i++)
		{
			if (i * m + left + m - 1 <= _nSize - 1)
			{
				item.setKey(arr[(i * m) + left]);
				item.setIndexes((i * m) + left,
					i * m + left + m - 1);
			}
			else 
			{
				item.setKey(arr[(i * m) + left]);
				item.setIndexes((i * m) + left, _nSize - 1);
			}
			_minHeap.insert(item);
		}

		while (!_minHeap.isEmpty())
		{
			currPair = _minHeap.DeleteMin();
			_newSortedArr[leftC++] = currPair.getMinElement();
			newLeft = currPair.getArrayIndexes().start + 1;
			counter++;

			if (newLeft <= currPair.getArrayIndexes().end)
			{
				newPair.setKey(arr[newLeft]);
				newPair.setIndexes(newLeft, currPair.getArrayIndexes().end);
				_minHeap.insert(newPair);
			}
		}
		for (int i = 0; i < counter && left + i < _nSize; ++i)
		{
			_arr[left + i] = _newSortedArr[leftC - counter + i];
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

