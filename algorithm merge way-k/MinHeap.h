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
		MinHeap(Pair* arr,const int size);
		~MinHeap();
		void BuildHeap() const;
		bool isEmpty() const;
		void makeEmpty();
		Pair Min() const ;
		Pair& DeleteMin();
		void insert(Pair& item);
		int getHeapSize() const;
		int getPhyHeapSize() const;
		bool getIsAllocated()const;
		MinHeap& operator=(const MinHeap& other);
		MinHeap(const MinHeap& other) = delete;
		friend ostream& operator<<(ostream& os, const MinHeap& queue);

		
		private:
		Pair* _data;
		int _phySize;
		int _heapSize;
		bool _allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void FixHeap(int node) const;
	};
}