#pragma once
#include <ostream>
using namespace std;
namespace KWayMergeAlgo
{
	class Pair
	{
		struct Indexes
		{
			int idx_arr = -1;
			int start;
			int end;
		};
	public:
		Pair();
		Pair(int key, int left,int right,int idx_arr);
		Pair(int key,Indexes arrIndexes);
		Pair(const Pair& other);
		~Pair() = default;
		int getMinElement() const;
		Indexes getArrayIndexes() const;
		const Pair& getPair() const;
		bool setKey(int key);
		bool setIndexes(Indexes data);
		bool setIndexes(int left, int right);
		bool setIndexArr(int idxArr);
		int getIndexArr() const;
		friend std::ostream& operator<<(ostream& os, const Pair& pair);
		//good to use defult operator for =
	private:
		int _minElementInArr;
		Indexes _arrayIndexes;


	};
}