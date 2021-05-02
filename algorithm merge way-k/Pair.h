#pragma once
#include <ostream>
using namespace std;
namespace KWayMergeAlgo
{
	class Pair
	{
	public:
		Pair();
		Pair(char key, int freq);
		Pair(const Pair& other);
		~Pair() = default;
		char getKey() const;
		int getFreq() const;
		const Pair& getPair() const;
		bool setKey(char key);
		bool setFreq(int freq);
		void operator++(int);
		friend std::ostream& operator<<(ostream& os, const Pair& pair);
		//good to use defult operator for =
	private:
		int _key;
		int *_array;
	};
}