#include<stdio.h>
#include<stdlib.h>
#include<cmath>

int main()
{
	long long* code;
	long long num;
	int check[10] = { 0 };
	int length = 1; // 그냥 자릿수
	bool end = false;
	int result = 0; // 결론 자릿수

	scanf("%lld", &num);
	code = (long long*)malloc(sizeof(long long) * num);

	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &code[i]);
		//printf("%lld", code[i]);
	}

	int imsi = code[1];
	while (1)
	{
		if (imsi >= 10) {
			imsi /= 10;
			length++;
		}
		else
			break;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < num; j++) {
			check[code[j] % 10]++;
		}
		for (int k = 0; k < 9; k++) {
			if (check[k] >= 2)
				end = true;
		}
		if (end)
		{
			result++;
			for (int p = 0; p < num; p++) {
				code[p] /= 10;
				printf("\n%lld", code[p]);
			}
			end = false;
		}
		else {
			break;
		}
	}

}