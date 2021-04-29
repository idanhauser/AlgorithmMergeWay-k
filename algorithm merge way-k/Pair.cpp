#include "Pair.h"



namespace HuffmanCoding
{
	Pair::Pair()
	{
	}

	Pair::Pair(char key, int* freq) : _key(key),
	                                   _array(freq)
	{
	}

	Pair::Pair(const Pair& other)
	{
		_freq = other._freq;
		_key = other._key;
	}
	/// <summary>
	/// the key of pair
	/// </summary>
	char Pair::getKey() const
	{
		return _key;
	}
	/// <summary>
	///the freq of key
	/// </summary>
	int Pair::getFreq() const
	{
		return _freq;
	}
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
	bool Pair::setKey(const char key) 
	{
		_key = key;
		return true;
	}
	/// <summary>
/// the set key of a freq.
/// </summary>
/// <param name="freq">the freq we want to set</param>
/// <returns>true if succeed else false</returns>
	bool Pair::setFreq(const int freq) 
	{
		_freq = freq;
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
