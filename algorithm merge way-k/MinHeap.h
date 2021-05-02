#pragma once
#include <ostream>

#include "Pair.h"

using namespace std;

namespace KWayMergeAlgo
{
	class MinHeap
	{
	public:
		MinHeap()=default;
		MinHeap(int phySize);
		MinHeap(int*& arr,const int size);
		~MinHeap();
		void BuildHeap() const;
		bool isEmpty() const;
		void makeEmpty();
		int* Min() const ;
		int& DeleteMin();
		void insert(int& item);
		int getHeapSize() const;
		int getPhyHeapSize() const;
		bool getIsAllocated()const;
		MinHeap& operator=(const MinHeap& other);
		MinHeap(const MinHeap& other) = default;
		friend ostream& operator<<(ostream& os, const MinHeap& queue);

		
		private:
		int** _data;
		int _phySize;
		int _heapSize;
		bool _allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void FixHeap(int node) const;
	};
}