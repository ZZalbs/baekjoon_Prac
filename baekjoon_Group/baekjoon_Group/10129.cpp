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

long long n,q;
long long dp[MAX];
long long tree[MAX];
long long bird[25];
deque <pair<long long, int>> dq; // 피로도, 인덱스 // 나무값 : tree[인덱스]
//이번에도 점프는 우측으로만 한다.
//점프길이 k일때, dp[i] = dp[i-k] 중 피로도 더한 것 고려했을때 최소
//덱에서 피로도가 같을 때는 나무높이 값이 높은게 우선

//이번 이동에 피로도가 없는 대신 다른것보다 값이 1 큼 vs 이번 이동에 피로도가 있는 대신 값이 1 작음
/*
이 경우, 어떤 걸 골라도 값이 같다. 
즉, 이동에 피로도가 드냐 안드냐에 관계없이 현 피로도가 최대한 적기만 하면 문제 x 

*/

void PrintDQ()
{
	for(int i=0;i<dq.size();i++)
	{
		cout<<"("<<dq[i].first<<","<<dq[i].second<<")";
	}
	cout<<"\n";
}


long long BirdMove(int k) // 점프길이
{
    dp[0] = 0;
    dq.push_front(make_pair(dp[0],0));
    for(int i=1;i<n;i++)
    {
        //PrintDQ();
        //인덱스 넘어갔을때
        while(!dq.empty() && (dq.front().second) < i-k ) dq.pop_front();
        if(!dq.empty()){
            if(dq.front().second < tree[i]) dp[i] = dq.front().first + 1;
            else dp[i] = dq.front().first;

            while(!dq.empty() && dq.back().first > dp[i] ) dq.pop_back(); // dq의 피로값이 더 클때
            while(!dq.empty() && dq.back().first == dp[i] && tree[dq.back().second] < tree[i] ) dq.pop_back(); // 값은 같은데 지금 삽입되는 나무가 더 클때
        }
        else
            dp[i] = 0;
        dq.push_back(make_pair(dp[i],i));
    }
    return dp[n-1];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    memset(tree,-1,sizeof(tree));
    memset(bird,-1,sizeof(bird));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>tree[i];
    cin>>q;
    for(int j=0;j<q;j++){
        memset(dp,-1,sizeof(dp));
        dq.clear();
        cin>>bird[j];
        cout<<BirdMove(bird[j])<<"\n";
    }
    

}
