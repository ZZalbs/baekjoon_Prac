#include <bits/stdc++.h>
using namespace std;


int main()
{

	/// cout, cin 최적화 함수.
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	/// printf, scanf 사용 불가능에 주의!
	



	int num;
	cin >> num;
	int p[1000] = { 0 };
	int vs = 0;
	int cnt=0; // 각 부분수열 개수
	int res = 0; // 최대 수
	for (int i = 0; i < num; i++){	
		cin >> p[i];
	}
	for (int i = 0; i < num; i++)
	{
		cnt = 1;
		vs = p[i];
		//cout << p[i] << "시작\n";
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