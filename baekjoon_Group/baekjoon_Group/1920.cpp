#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	set<long long> s;
	set<long long> already; // 이미 나온 숫자들은 여기 보관
	long long k;
	for (int i = 0; i < a; i++)
	{
		scanf("%lld", &k);
		s.insert(k);
	}
	cin >> a;
	long long check;
	for (int j = 0; j < a; j++)
	{
		scanf("%lld", &check);
		if (already.count(check) == 1)
			cout << '1'<<endl;
		else		
			cout << s.count(check)<<endl;
		already.insert(check);
	}

}