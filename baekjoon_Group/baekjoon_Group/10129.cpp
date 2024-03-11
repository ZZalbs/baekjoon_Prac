//dp[i] = i에서 느끼는 최소 피로감

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
#include <string.h>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;

const int MAX = 1000001;
const int INF = 100000001;

long long n,k,q;
long long dp[MAX];
long long tree[MAX];
long long bird[25];
deque <pair<long long, int>> dq; // 값, 인덱스
//이번에도 점프는 우측으로만 한다고 하자.
//점프길이 k일때, dp[i] = dp[i-k] 중 피로도 더한 것 고려했을때 최소




int main()
{
    memset(dp,-1,sizeof(dp));
    memset(tree,-1,sizeof(tree));
    memset(bird,-1,sizeof(bird));
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>tree[i];
    cin>>q;
    for(int j=0;j<q;j++)
        cin>>bird[j];
    

}
