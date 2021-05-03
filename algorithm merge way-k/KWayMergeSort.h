#pragma once

#include <fstream>
#include "MinHeap.h"
#include "Pair.h"
namespace KWayMergeAlgo {
	class KWayMergeSort
	{
		int _k;
		int _n;
		int* _arr;
		MinHeap _minHeap;
		fstream _pfile;

		KWayMergeSort(const KWayMergeSort& other) = delete;
		const KWayMergeSort& operator=(const KWayMergeSort& other) = delete;

	public:
		KWayMergeSort(int* arr, int n, int k,string outputName);
		~KWayMergeSort();

	
		void mergeKArraysWithHeap(int* p, int left, int right, int k);
		void KMergeSort(int* arr, int left, int right, int k);
		void QuickSort(int* arr, int left, int right);
		int Partition(int* arr, int left ,int right);
		void swap(int* pnum1, int* pnum2);
	};
}