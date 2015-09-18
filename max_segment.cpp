#include <iostream>
#include <cstdlib>
#include <algorithm>
const int LEN = 3;

using namespace std;

struct segment
{
	int start;
	int end;
};

// assume a.end < b.end
segment commonSeg(const segment & a, const segment & b)
{
	segment CommonSeg;
	if(a.end < b.start)
	{
		CommonSeg.end = 0;
		CommonSeg.start = 0;
	}
	else
	{
		CommonSeg.end = a.end;
		CommonSeg.start = b.start;
	}
	return CommonSeg;
}

int findMaxSegment(int size, segment * Segment, segment & maxSeg)
{
	if(NULL == Segment)
	{
		cerr << "the segment array is NULL" << endl;
		return -1;
	}
	else if(1 == size)
	{
		maxSeg = Segment[0];
		return maxSeg.end-maxSeg.start;
	}
	else if(2 == size)
	{
		if(Segment[0].end <= Segment[1].start)
		{
			maxSeg.start = 0;
			maxSeg.end = 0;
			return maxSeg.end-maxSeg.start;
		}
		else
		{
			maxSeg.end = Segment[0].end;
			maxSeg.start = Segment[1].start;
			return maxSeg.end-maxSeg.start;
		}
	}
	else
	{
		segment tmpMaxSeg, tmpSeg,currMaxSeg;
		int currMaxLen = 0;
		findMaxSegment(size-1, Segment, tmpMaxSeg);
		for(int i=0; i<size-1; i++)
		{
			tmpSeg=commonSeg(Segment[i], Segment[size-1]);
			if(tmpSeg.end - tmpSeg.start > currMaxLen)
			{
				currMaxLen = tmpSeg.end - tmpSeg.start;
				currMaxSeg = tmpSeg;
			}
		}
		if(tmpMaxSeg.end - tmpMaxSeg.start > currMaxLen )
		{
			maxSeg = tmpMaxSeg;
		}
		else
		{
			maxSeg = currMaxSeg;
		}
		return maxSeg.end - maxSeg.start;
	}
}



bool isShorter(const segment & s1, const segment & s2)
{
	return s1.end < s2.end;
}

int main()
{
	segment * Segment = new segment[LEN];
	Segment[0].start = 1;
	Segment[0].end = 5;
	Segment[1].start = 2;
	Segment[1].end = 8;
	Segment[2].start = 3;
	Segment[2].end = 9;
	sort(Segment, Segment + LEN, isShorter);
	segment maxSeg;
	findMaxSegment(LEN, Segment, maxSeg);
	cout << maxSeg.start << endl;
	cout << maxSeg.end << endl;
	delete [] Segment;
	return 0;
}

