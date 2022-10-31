#include <bits/stdc++.h>
using namespace std;

long long* numArray;
int length;

int arrayCheck(int k)
{
	int upper = length - 1;
	int lower = 0;
	while (true)
	{
		int mid = (lower + upper) / 2;
		if (k < numArray[mid]) {
			//printf("%lld %lld\n", numArray[lower], numArray[upper]);

			upper = mid;

		}
		else if (k > numArray[mid]) {
			//printf("%lld %lld\n", numArray[lower], numArray[upper]);

			lower = mid;

		}
		else
			return 1;

		if (upper - lower <= 1)
			break;

		if (k == numArray[upper] || k == numArray[lower])
			return 1;
	}
	if (k == numArray[upper] || k == numArray[lower])
		return 1;
	else
		return 0;

}

int main()
{

}