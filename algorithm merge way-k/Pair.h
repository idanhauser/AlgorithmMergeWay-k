#pragma once
#include <ostream>
using namespace std;
namespace KWayMergeAlgo
{
	class Pair
	{
		struct indexes
		{
			int start;
			int end;
		};
	public:
		Pair();
		Pair(int key, int left,int right);
		Pair(const Pair& other);
		~Pair() = default;
		char getKey() const;
		indexes getArrayIndexes() const;
		const Pair& getPair() const;
		bool setKey(int key);
		bool setIndexes(indexes data);
		void operator++(int);
		friend std::ostream& operator<<(ostream& os, const Pair& pair);
		//good to use defult operator for =
	private:
		int _minElementInArr;
		indexes _arrayIndexes;


	};
}