#pragma once

#include <fstream>
#include "MinHeap.h"
#include <math.h> 
#include "Pair.h"
namespace KWayMergeAlgo {
	class KWayMergeSort
	{
	public:
		KWayMergeSort(int* arr, int n, int k, string outputName);
		void ExcecuteKMergeSort();
		int getArraySize() const;
		int getK() const;
		void setK(int k);
		int* getArray() const;
		~KWayMergeSort();
	private:
		int _kParts;
		int _nSize;
		int* _arr;
		MinHeap _minHeap;
		ofstream _pfile;
		KWayMergeSort(const KWayMergeSort& other) = delete;
		const KWayMergeSort& operator=(const KWayMergeSort& other) = delete;


		void mergeKArraysWithHeap(int* pArr, int left, int right, int k);
		void KMergeSort(int* arr, int left, int right, int k);
		void QuickSort(int* arr, int left, int right);
		int Partition(int* arr, int left, int right);
		void swap(int* pnum1, int* pnum2);


	
		
		
	};
}