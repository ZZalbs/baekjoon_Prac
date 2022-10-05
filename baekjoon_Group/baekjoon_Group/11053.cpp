#include <bits/stdc++.h>
using namespace std;

set <long long > s;

int main()
{

	/// cout, cin 최적화 함수.
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	/// printf, scanf 사용 불가능에 주의!
	



	int num;
	cin >> num;
	int p;
	int vs = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> p;
		if (vs<p) {
			s.insert(p);
			cout << p<<'\n';
			vs = p;
		}
		
	}
}