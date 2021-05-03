#pragma once
#include <ostream>
using namespace std;
namespace KWayMergeAlgo
{
	class Pair
	{
		struct Indexes
		{
			int start;
			int end;
		};
	public:
		Pair();
		Pair(int key, int left,int right);
		Pair(int key,Indexes arrIndexes);
		Pair(const Pair& other);
		~Pair() = default;
		int getKey() const;
		Indexes getArrayIndexes() const;
		const Pair& getPair() const;
		bool setKey(int key);
		bool setIndexes(Indexes data);
		friend std::ostream& operator<<(ostream& os, const Pair& pair);
		//good to use defult operator for =
	private:
		int _minElementInArr;
		Indexes _arrayIndexes;


	};
}