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

	Pair::Pair(const Pair& other)
	{
		_arrayIndexes = other.getKey();
		_arrayIndexes = other.getArrayIndexes();
	}
	/// <summary>
	/// the key of pair
	/// </summary>
	char Pair::getKey() const
	{
		return _key;
	}

	Pair::indexes Pair::getArrayIndexes() const
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
		_key = key;
		return true;
	}
	/// <summary>
/// the set key of a freq.
/// </summary>
/// <param name="freq">the freq we want to set</param>
/// <returns>true if succeed else false</returns>
	bool Pair::setIndexes(Pair::indexes data)
	{
		_arrayIndexes=data;
		return true;
	}
	/// <summary>
	/// operator ++ to add one to freq.
	/// </summary>
	/// <param name=""></param>
	void Pair::operator++(int)
	{
		_freq++;
	}
	/// <summary>
	/// prints the pair
	/// </summary>

	ostream& operator<<(ostream& os, const Pair& pair)
	{
		os << pair.getKey() << ":" << pair.getFreq() << endl;
		return os;
	}
}
