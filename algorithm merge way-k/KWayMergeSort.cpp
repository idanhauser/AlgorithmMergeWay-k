#include "KWayMergeSort.h"
#include "Pair.h"
#include <math.h> 
#include <iostream>



namespace KWayMergeAlgo {


	KWayMergeSort::KWayMergeSort(int* arr, int n, int k, string outputName) :_kParts(k), _nSize(n), _arr(new int[n]),
		_minHeap(k), _pfile(outputName)
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
		KMergeSort(_arr, 0, _nSize, _kParts);
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
		int len = right - left;
		if (len <= k)
		{
			QuickSort(arr, left, right);
			return;
		}
		else
		{
			int parts = ceil((double)((len) / (k)));
			parts += len % k;
			for (int i = 0; i < k; i++)
			{
				KMergeSort(arr, (i*parts) , (i * parts + (parts)-1), k);
			}

			mergeKArraysWithHeap(_arr, left, right, k);
			//done:Merge with Heap....https://medium.com/outco/how-to-merge-k-sorted-arrays-c35d87aa298e
		}
	}

	KWayMergeSort::~KWayMergeSort()
	{
		delete[] _arr;
		_pfile.close();
	}

	void KWayMergeSort::mergeKArraysWithHeap(int* arr, int left, int right, int k)
	{
		Pair newPair;
		Pair currPair;
		int len = right - left;
		int* newSortedArr = new int[len];
		int idx = 0;
		int newLeft;
		int parts = ceil((double)((len + 1) / (k)));
		parts += len % k;

		//Init the Heap		
		_minHeap.makeEmpty();

		for (int i = 0; i < k; i++)
		{
			Pair item(arr[i], i*parts, (i * parts + (parts)-1));
			_minHeap.insert(item);
		}

		while (!_minHeap.isEmpty())
		{
			currPair = _minHeap.DeleteMin();

			newSortedArr[idx++] = currPair.getMinElement();
			newLeft = currPair.getArrayIndexes().start + 1;

			if (newLeft < currPair.getArrayIndexes().end)
			{
				newPair.setKey(arr[newLeft]);
				newPair.setIndexes(newLeft, currPair.getArrayIndexes().end);
				_minHeap.insert(newPair);
			}
		}
		for (int i = 0; i < _nSize; ++i)
		{
			cout << newSortedArr[i] << endl;
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

