#include <bits/stdc++.h>
using namespace std;

//나무자르기
long long* treeArray;
int length;

int TreeCheck(int k)
{
	int upper = length - 1;
	int lower = 0;
	while (true)
	{
		int mid = (lower + upper) / 2;
		if (k < treeArray[mid]) {
			upper = mid;
		}
		else if (k > treeArray[mid]) {
			lower = mid;
		}
		else
			return 1;

		if (upper - lower <= 1)
			break;

		if (k == treeArray[upper] || k == treeArray[lower])
			return 1;
	}
	if (k == treeArray[upper] || k == treeArray[lower])
		return 1;
	else
		return 0;
}

int numCheck(int k)
{ 
	
}

int main()
{

}