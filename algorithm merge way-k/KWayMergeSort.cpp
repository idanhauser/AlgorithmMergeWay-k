#include "KWayMergeSort.h"

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
	}

	void KWayMergeSort::KMergeSort(int* arr, int left, int right, int k)
	{
		int len = left - right + 1;
		if(len<k)
		{
			QuickSort(arr, left, right);
			return;
		}
		else
		{
			int parts = ceil(len / k);
			for (int i = 0; i < parts;i+=k)
			{
				KMergeSort(arr, left+i, k+i-1, k);
			}

			mergeKArraysWithHeap(_arr,left,right,k);
			//todo:Merge with Heap....https://medium.com/outco/how-to-merge-k-sorted-arrays-c35d87aa298e
		}
	}

	KWayMergeSort::~KWayMergeSort()
	{
		delete[] _arr;
		_pfile.close();
	}

	void KWayMergeSort::mergeKArraysWithHeap(int* p, int left, int right, int k)
	{
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
}

