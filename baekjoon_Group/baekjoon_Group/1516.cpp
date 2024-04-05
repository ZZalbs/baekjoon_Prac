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


void DFS(int here)
{
    visited[here]=true;
    for(int i=0;i<graph.size();i++)
    {
        if(!visited[i]) DFS(graph[here][i]);
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
    for(int i=1;i<=n;i++)
    {
        value=0;
        need=0;
        cin>>value;
        while(need!=-1)
        {
            cin>>need;
            if(need==-1) break;
            graph[need][i] = value; 
        }
    }
    PrintGraph();
}