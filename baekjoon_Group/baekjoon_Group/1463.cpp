#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int dp[1000001] = { 0 };
int imsi = 0;
int Calculate(int a)
{
    if (a == 1)
        return 0;
    if (dp[a] != 0)
        return dp[a];
    dp[a] = Calculate(a - 1) + 1; // a-1의 계산횟수
    if (a % 3 == 0) {
        imsi = Calculate(a / 3) + 1; // a/3의 계산횟수
        if (imsi < dp[a])
            dp[a] = imsi;
    }
    if (a % 2 == 0) {
        imsi = Calculate(a / 2) + 1; // a/2의 계산횟수
        if (imsi < dp[a])
            dp[a] = imsi;
    }
    return dp[a];
}

int main()
{
    int num;
    cin >> num;

    cout << Calculate(num);
}