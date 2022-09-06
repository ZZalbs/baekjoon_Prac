#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long num,k;
	cin >> num;
	long long imsi = 0;
	int cnt=0;
	vector<long long> insu;
	
	
	for(int i=0;i<num;i++)
	{
		//메인코드 전처리
		cnt = 0;
		cin >> k;
		imsi = k;
		insu.clear();

		//입력받은 수가 홀수일때!
		if (k % 2 != 0)
		{
			//첫번째 처리 : 더한 숫자의 개수가 홀수
			for (long long i = 3; i <= imsi; i += 2)
			{

				if (imsi % i == 0)
				{
					cout << "qewrqwree :" << i << endl;
					if (k / i * 2 - 1 >= i) {
						cout << "holcase: " << i << endl;
						cnt++;
					}
				}
			}

			//두번째 처리 : 더한 숫자의 개수가 짝수
			imsi = k;
			for (long long i = 2; i<k; i += 4) {
				if (k % (i/2) == 0)
				{
					if (k / (i/2) > i) {
						cout << "holcase2: " << i << endl;
						cnt++;
					}
				}
			}
			cout << cnt << endl;
		}


		//입력받은 수가 짝수일때!
		if (k % 2 == 0)
		{
			while (imsi % 2 == 0) { imsi /= 2; }

			//첫번째 처리 : 더한 숫자의 개수가 홀수
			for (long long i = 3; i <= imsi; i += 2)
			{
				if (imsi % i == 0)
				{
					insu.push_back(i);
					//insu.push_back(k/i);
					if (k / i * 2 - 1 >= i) {
						//cout <<"1case: " << i << endl;
						cnt++;
					}
				}
			}
			//두번째 처리 : 더한 숫자의 개수가 짝수
			imsi = k;
			for (long long i = 0; i < insu.size(); i++)
			{
				if ((insu[i] - 1) / 2 > k / insu[i]) {
					//cout << "2case: " << insu[i] << endl;
					cnt++;
				}
			}
			cout << cnt<< endl;

		}
	}
	
}