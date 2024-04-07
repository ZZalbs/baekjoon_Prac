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

const int MAX = 501;
const int INF = 987654321;

vector<vector<int>> graph; // 그래프
int buildTime[MAX];
int haveline[MAX]; // haveline[i] = k 일때, k = i번째 건물이 요구로 하는 건물수
int dp[MAX];
int n;
queue <int> q;

//위상정렬 방법
/*
1. 큐에 진입차수(나한테 오는 간선) 0인 정점 집어넣기
2. 1에서 나온 정점의 간선 다 없애기
3. 1로 돌아가기
*/

void TSort() // 위상정렬. 미완성
{
    for(int i=1;i<=n;i++)
    {
        if(haveline[i]==0) q.push(i);
        dp[i] = buildTime[i];
    }

    //사이클이 없는 입력이므로, 사이클 예외처리는 생략

    for(int i=1;i<=n;i++)
    {
        int cur = q.front(); // cur : 삭제한 정점(진입차수가 0)
        q.pop();
        for(int i=0;i<graph[cur].size();i++)
        {
            int next=graph[cur][i]; // next : cur을 짓고 다음에 짓는 건물
            haveline[next]--; // cur과 연결된 간선 삭제

            dp[next] = max(dp[next], dp[cur]+buildTime[next]);
            if(haveline[next]==0) q.push(next);    // next가 진입차수가 0이면
        }
    }
}

void PrintDP()
{
    //cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<"\n";
    }
}


int main()
{
    fastio;
    cin>>n;
    graph = vector<vector<int>>(n+1,vector<int>(n+1,0));
    memset(dp,-1,sizeof(dp));
    memset(haveline,0,sizeof(haveline));
    int need;
    bool haveLine; // 간선이 없는지 있는지 확인
    for(int i=1;i<=n;i++)
    {
        
        need=0;
        cin>>buildTime[i];
        while(need!=-1)
        {
            cin>>need;
            if(need==-1) 
                break;
            graph[need].push_back(i);
            haveline[i]++;
        }
    }
    TSort();
    PrintDP();
}