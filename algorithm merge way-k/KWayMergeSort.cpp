#include "KWayMergeSort.h"
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
		else
		{
			int sizeOfSubArray = len / k;
			sizeOfSubArray += len % k;
			int leftOver = len % k;
			for (int i = 0; i < k; i++)
			{

				int leftOffset = (i * sizeOfSubArray);

				if (i < k - leftOver)
				{
					KMergeSort(arr, leftOffset + left,
						left + leftOffset + sizeOfSubArray - 1, k);
				}
				else
				{
					KMergeSort(arr, leftOffset + left,
						left + leftOffset + sizeOfSubArray, k);
				}
			}
			//cout << "left = " << left << " right = " << right << endl;
				//cout << "left = " << left << " right = " << right << endl;
			mergeKArraysWithHeap(arr, left, right, k);
			//done:Merge with Heap....https://medium.com/outco/how-to-merge-k-sorted-arrays-c35d87aa298e
		}
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
		Pair* sizeArr = new Pair[len];
		int newLeft;
		int sizeOfSubArray = len / k;
		sizeOfSubArray += len % k;
		int leftOver = len % k;
		Pair item;
		//Init the Heap		
		_minHeap.makeEmpty();

		for (int i = 0; i < k; i++)
		{
			int leftOffset = (i * sizeOfSubArray);
			sizeArr[i].setKey(i);
			item.setIndexArr(i);
			item.setKey(arr[leftOffset + left]);
			if (i < k - leftOver)
			{
				
				sizeArr[i].setIndexes(leftOffset + left,
					left + leftOffset + sizeOfSubArray - 1);

				item.setIndexes(leftOffset + left,
					left + leftOffset + sizeOfSubArray - 1);
			}
			else
			{
				sizeArr[i].setIndexes(leftOffset + left,
					left + leftOffset + sizeOfSubArray);
				
				item.setIndexes(leftOffset + left,
					left + leftOffset + sizeOfSubArray);
			}
			cout << "left = " << item.getArrayIndexes().start << " right = " << item.getArrayIndexes().end << endl;
			_minHeap.insert(item);
		}

		while (!_minHeap.isEmpty())
		{
			currPair = _minHeap.DeleteMin();
			_newSortedArr[leftC++] = currPair.getMinElement();
			newLeft = currPair.getArrayIndexes().start + 1;
			counter++;

			if (newLeft <= sizeArr[currPair.getIndexArr()].getArrayIndexes().end)
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

