#include<stdio.h>
#include<stdlib.h>
#include<cmath>

//13458
int main()
{
	long long *roomstr,roomnum;
	long long mainjudge, subjudge;
	long long cnt; 
	scanf("%lld", &roomnum);
	roomstr = (long long*)malloc(sizeof(long long) * roomnum);
	for (int i = 0; i < roomnum; i++)
		scanf("%lld", &roomstr[i]);
	scanf("%lld %lld", &mainjudge, &subjudge);
	cnt = roomnum; // ������ ���� : �� ����
	for (int i = 0; i < roomnum; i++) {
		roomstr[i] -= mainjudge;
		if (roomstr[i] > 0) {
			cnt += roomstr[i] / subjudge;
			if (roomstr[i] % subjudge != 0)
				cnt++; // �ȳ����������� �ø�
		}


		//if (roomstr[i] >= mainjudge)
		//	cnt += ((roomstr[i] - mainjudge) + subjudge - 1 ) / subjudge;
	}
	printf("%lld", cnt);
	
	free(roomstr);
	
}


