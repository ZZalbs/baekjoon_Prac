#include <bits/stdc++.h>
using namespace std;

//나무자르기
long long* treeArray;
long long length;

long long TreeCheck(long long target)
{
	long long upper = treeArray[length - 1];
	long long lower = 0;
	long long midHeight = 0;
	long long sum = 0;
	//printf("Target : %d\n\n", target);
	while (true)
	{
		midHeight = (lower + upper) / 2;
		sum = 0;
		for (long long i = 0; i < length; i++) {
			if (treeArray[i] > midHeight) {
				sum += treeArray[i] - midHeight;
			}
		}
		//printf(" lower : %lld\n upper : %lld\n mid : %lld\n sum: %lld\n\n", lower, upper, midHeight, sum);
		if (sum < target) upper = midHeight; // 합이 필요보다 작음 -> 목표보다 너무 높게 잘랐으므로 위를 낮춤
		else if (sum > target) {
			if (upper - lower == 1)
				break;				
			lower = midHeight; 
		}
		else break;
	}
	return midHeight;
}



int main()
{
	long long target;
	scanf("%lld", &length);
	scanf("%lld", &target);

	treeArray = (long long*)malloc(sizeof(long long) * length);
	for (int i = 0; i < length; i++)
		scanf("%lld", &treeArray[i]);

	sort(treeArray, treeArray + length);
	printf("%d", TreeCheck(target));
}