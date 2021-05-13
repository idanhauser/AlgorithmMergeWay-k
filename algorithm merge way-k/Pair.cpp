#include "Pair.h"



namespace KWayMergeAlgo

{
	Pair::Pair()
	{
	}

	Pair::Pair(int key, int left, int right, int idxArr) : _minElementInArr(key)
	{
		_arrayIndexes.idx_arr = idxArr;
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
		_minElementInArr = other.getMinElement();
		_arrayIndexes = other.getArrayIndexes();
	}
	/// <summary>
	/// the key of pair
	/// </summary>
	int Pair::getMinElement() const
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
	bool Pair::setIndexes(Pair::Indexes idxs)
	{
		_arrayIndexes= idxs;
		return true;
	}

	bool Pair::setIndexes(int left, int right)
	{
		_arrayIndexes.start = left;
		_arrayIndexes.end = right;
		return true;
	}

	bool Pair::setIndexArr(int idxArr)
	{
		_arrayIndexes.idx_arr = idxArr;
		return true;
	}

	int Pair::getIndexArr() const
	{
		return _arrayIndexes.idx_arr;
	}

	bool Pair::setFlag(bool flag)
	{
		_arrayIndexes.flag = flag;
		return true;
	}

	bool Pair::getFlag() const
	{
		return _arrayIndexes.flag;
	}

	/// <summary>
	/// prints the pair
	/// </summary>

	ostream& operator<<(ostream& os, const Pair& pair)
	{
		os << "The minimum element in the array is " << pair.getMinElement() << "and the array indexes are :\n";
		os << "Start: " << pair.getArrayIndexes().start << " ,End:" << pair.getArrayIndexes().end << '.';
		return os;
	}
}
