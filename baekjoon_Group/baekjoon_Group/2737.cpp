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
		//�����ڵ� ��ó��
		cnt = 0;
		cin >> k;
		imsi = k;
		insu.clear();

		//�Է¹��� ���� Ȧ���϶�!
		if (k % 2 != 0)
		{
			//ù��° ó�� : ���� ������ ������ Ȧ��
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

			//�ι�° ó�� : ���� ������ ������ ¦��
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


		//�Է¹��� ���� ¦���϶�!
		if (k % 2 == 0)
		{
			while (imsi % 2 == 0) { imsi /= 2; }

			//ù��° ó�� : ���� ������ ������ Ȧ��
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
			//�ι�° ó�� : ���� ������ ������ ¦��
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