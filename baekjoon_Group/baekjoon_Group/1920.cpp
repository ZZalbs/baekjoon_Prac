/////////////////////// 1번 풀이 : 이분 탐색 //////////////////

/*
#include <bits/stdc++.h>
using namespace std;


long long* numArray;
int length;






int arrayCheck(int k)
{
	int upper =length-1;
	int lower =0;
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
	
	scanf("%d", &length);
	
	numArray = (long long*)malloc(sizeof(long long) * length);
	for (int i = 0; i < length; i++)
		scanf("%lld",&numArray[i]);
	
	sort(numArray, numArray + length);




	int length2;
	scanf("%d",&length2);
	int check;

	
	
	for (int i = 0; i < length2; i++)
	{
		scanf("%d", &check);
		printf("%d\n",arrayCheck(check));
	}

	free(numArray);
	
}
*/

//////////////////// 2번 풀이 : set ///////////////////////

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	set<long long> s;
	long long k;
	for (int i = 0; i < a; i++)
	{
		scanf("%lld", &k);
		s.insert(k);
	}
	cin >> a;
	long long check;
	for (int j = 0; j < a; j++)
	{
		scanf("%lld", &check);
		printf("%d\n", s.count(check)>=1 ? 1 : 0 );
	}

}