#include<stdio.h>
#include<stdlib.h>
#include<cmath>

int main()
{
	long long* code;
	long long num;
	int check[10] = { 0 };
	int length = 0;
	scanf("%lld", &num);
	code = (long long*)malloc(sizeof(long long) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &code[i]);
		printf("%lld", code[i]);
	}
	int imsi = code[1];
	while (1)
	{
		length++;
		if (imsi >= 10) {
			imsi /= 10;
			length++;
		}
		else
			break;
	}
	printf("%d", length);
}