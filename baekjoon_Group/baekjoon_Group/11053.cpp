#include <bits/stdc++.h>
using namespace std;


int main()
{

	/// cout, cin ����ȭ �Լ�.
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	/// printf, scanf ��� �Ұ��ɿ� ����!
	



	int num;
	cin >> num;
	int p[1000] = { 0 };
	int vs = 0;
	int cnt=0; // �� �κм��� ����
	int res = 0; // �ִ� ��
	for (int i = 0; i < num; i++){	
		cin >> p[i];
	}
	for (int i = 0; i < num; i++)
	{
		cnt = 1;
		vs = p[i];
		//cout << p[i] << "����\n";
		for (int j = i; j < num; j++)
		{
			if (vs < p[j]) {
				//cout << p[j] << "<<<<<<<<<<\n";
				cnt++;
				vs = p[j];
			}
		}
		if (res < cnt)
			res = cnt;
		
	}
	cout << res;
}