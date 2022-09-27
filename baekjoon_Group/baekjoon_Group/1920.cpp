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
		if (k <= numArray[(lower + upper) / 2]){
			//printf("%lld %lld\n", numArray[lower], numArray[upper]);

			upper = (lower + upper) / 2;
			
		}
		else{
			//printf("%lld %lld\n", numArray[lower], numArray[upper]);
			
			lower = (lower + upper) / 2;
			
		}

		if (upper - lower <= 1)
			break;
		//printf(" %d ,  %d\n",lower, upper);
	}
	if (k == numArray[upper] || k == numArray[lower])
		return 1;
	else
		return 0;
}


int main()
{
	
	cin >> length;
	
	numArray = (long long*)malloc(sizeof(long long) * length);
	for (int i = 0; i < length; i++)
		scanf("%lld", &numArray[i]);
	
	sort(numArray, numArray + length);




	int length2;
	cin >> length2;
	int check;

	
	
	for (int i = 0; i < length2; i++)
	{
		cin >> check;
		cout<<arrayCheck(check)<<endl;
	}
	free(numArray);
	
}