#include "Pair.h"



namespace KWayMergeAlgo

{
	Pair::Pair()
	{
	}

	Pair::Pair(int key, int left, int right) : _minElementInArr(key)
	{
		_arrayIndexes.start = left;
		_arrayIndexes.end = right;
	}

	Pair::Pair(int key, Indexes arrIndexes)
	{
		_minElementInArr = key;
		_arrayIndexes = arrIndexes;
	}

	Pair::Pair(const Pair& other)
	{
		_minElementInArr = other.getKey();
		_arrayIndexes = other.getArrayIndexes();
	}
	/// <summary>
	/// the key of pair
	/// </summary>
	int Pair::getKey() const
	{
		return _minElementInArr;
	}

	Pair::Indexes Pair::getArrayIndexes() const
	{
		return _arrayIndexes;
	}

	/// <summary>
	///the freq of key
	/// </summary>

	/// <summary>
	/// returns pair
	/// </summary>
	const Pair& Pair::getPair() const
	{
		return  *this;
	}
	/// <summary>
	/// the set key of a pair.
	/// </summary>
	/// <param name="key">the ket we want to set</param>
	/// <returns>true if succeed else false</returns>
	bool Pair::setKey(const int key) 
	{
		_minElementInArr = key;
		return true;
	}
	/// <summary>
/// the set key of a freq.
/// </summary>
/// <param name="freq">the freq we want to set</param>
/// <returns>true if succeed else false</returns>
	bool Pair::setIndexes(Pair::Indexes data)
	{
		_arrayIndexes=data;
		return true;
	}

	/// <summary>
	/// prints the pair
	/// </summary>

	ostream& operator<<(ostream& os, const Pair& pair)
	{
		os << "The minimum element in the array is " << pair.getKey() << "and the array indexes are :\n";
		os << "Start: " << pair.getArrayIndexes().start << " ,End:" << pair.getArrayIndexes().end << '.';
		return os;
	}
}
