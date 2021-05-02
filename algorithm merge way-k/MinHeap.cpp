#include "MinHeap.h"
#include <stdlib.h>
#include <iostream>

namespace KWayMergeAlgo
{


	MinHeap::MinHeap(int phySize) :_data(new int* [phySize]), _phySize(phySize), _heapSize(0), _allocated(true)
	{

	}

	MinHeap::MinHeap(int*& arr, const int size) : _phySize(size), _heapSize(size), _allocated(false)
	{
		_data = &arr;

	}

	MinHeap::~MinHeap()
	{
		if (_allocated)
		{
			delete[] _data;
		}
		_data = nullptr;
	}
	/// <summary>
	/// heap build by the algoritem of floyd.
	/// </summary>
	void MinHeap::BuildHeap() const
	{
		for (int i = _phySize / 2 - 1; i >= 0; i--)
		{
			FixHeap(i);
		}
	}
	/// <summary>
	/// checks if the heap is empty
	/// </summary>
	/// <returns>true if its</returns>
	bool MinHeap::isEmpty() const
	{
		return (_heapSize == 0);
	}

	void MinHeap::makeEmpty()
	{
		_heapSize = 0;
	}
	/// <summary>
	///  It returns the root element of Min Heap. Time Complexity of this operation is O(1).
	/// </summary>
	/// <returns>root element of Min Heap</returns>
	int* MinHeap::Min() const
	{
		return *_data;
	}
	/// <summary>
	/// Returns the left child node
	/// </summary>
	int MinHeap::Left(const int node)
	{
		return (2 * node + 1);
	}
	/// <summary>
	/// Returns the right child node
	/// </summary>
	int MinHeap::Right(const int node)
	{
		return (2 * node + 2);
	}
	/// <summary>
	/// Returns the parent node
	/// </summary>
	int MinHeap::Parent(const int node)
	{
		return (node - 1) / 2;
	}

	/// <summary>
	/// This function is the fix heap:
	/// A recursive method to fix  a subtree with the root at given index 
	/// This method assumes that the subtrees are already fixed. O(log(n))
	/// </summary>
	/// <param name="node">the node of the heap</param>
	void MinHeap::FixHeap(const int node) const
	{
		int min;
		int left = Left(node);
		int right = Right(node);
		/* find the smallest of parent, left, and right */

		if (left < _heapSize && _data[left]->_data.getFreq() < _data[node]->_data.getFreq())
		{
			min = left;
		}
		else
		{
			min = node;
		}
		if (right < _heapSize && _data[right]->_data.getFreq() < _data[min]->_data.getFreq())
		{
			min = right;
		}


		if (min != node) {
			int* temp = _data[node];
			_data[node] = _data[min];
			_data[min] = temp;
			FixHeap(min);
		}
	}


	/// <summary>
	///Remove the element at head of the queue 
	/// </summary>
	/// <returns>retuns the element with the minimum frequency.(the root in the MinHeap) </returns>
	int& MinHeap::DeleteMin()
	{
		int* MinTreeNode;
		if (_heapSize == 0) {
			cout << "ERROR: heap underflow! maybe file is empty?" << endl;
			exit(1);
		}
		MinTreeNode = _data[0];
		_heapSize--;
		_data[0] = _data[_heapSize];
		FixHeap(0);
		return *MinTreeNode;
	}
	/// <summary>
	/// insert item to the heap the priority is the frequency of the pair.
	/// </summary>
	/// <param name="item">the item we insert to the heap</param>
	void MinHeap::insert(int& item)
	{
		if (_phySize == _heapSize)
		{
			cout << "ERROR: heap Overflow!" << endl;
			exit(1);
		}
		int i = _heapSize;
		_heapSize++;

		while ((i > 0) && (_data[Parent(i)]->_data.getFreq() > item._data.getFreq())) {
			_data[i] = _data[Parent(i)];
			i = Parent(i);
		}
		_data[i] = &item;
	}


	int MinHeap::getHeapSize() const
	{
		return _heapSize;
	}

	int MinHeap::getPhyHeapSize() const
	{
		return _phySize;
	}
	/// <summary>
	/// Checks if the array of the minimum heap was allocated or not
	/// </summary>
	/// <returns> true if was allocated else false</returns>
	bool MinHeap::getIsAllocated() const
	{
		return _allocated;
	}
	/// <summary>
	/// implemented operator "==" for the minimum heap.
	/// </summary>
	/// <param name="other">the heap we copy from</param>
	/// <returns>the object</returns>
	MinHeap& MinHeap::operator=(const MinHeap& other)
	{
		if (this != &other)
		{
			_allocated = other._allocated;
			_heapSize = other._heapSize;
			_phySize = other._phySize;
			_data = new int * [_phySize];
		}
		return *this;
	}
	/// <summary>
	///  implemented operator from printing to the table of minimum heap.
	/// </summary>
	/// <param name="queue">the object we want to print</param>
	/// <returns>the stream</returns>
	ostream& operator<<(ostream& os, const MinHeap& queue)
	{
		for (int i = 0; i < queue._heapSize; ++i)
		{
			os << queue._data[i]->getData();
		}
		return os;
	}
}
