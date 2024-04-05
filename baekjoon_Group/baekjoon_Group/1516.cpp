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
vector<bool> visited;
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

    }
}

void PrintGraph()
{
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<graph[i][j];
        }
        cout<<"\n";
    }

}

int main()
{
    fastio;
    cin>>n;
    graph = vector<vector<int>>(n+1,vector<int>(n+1,0));
    memset(dp,-1,sizeof(dp));
    int value,need;
    bool haveLine; // 간선이 없는지 있는지 확인
    for(int i=1;i<=n;i++)
    {
        value=0;
        need=0;
        haveLine=false; 
        cin>>value;
        while(need!=-1)
        {
            cin>>need;
            if(need==-1) {
                if(!haveLine) q.push();
                break;
            }
            haveline=true;
            graph[need][i] = value; 
        }
    }
    PrintGraph();
}