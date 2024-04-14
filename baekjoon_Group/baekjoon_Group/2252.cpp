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

const int MAX = 32001;

queue<int> q; // kahn 위상정렬용 큐
int n,m;
vector<vector<int>> graph;
int nodeCount[MAX]; //간선 개수

void PrintGraph()
{
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void PrintNodeCount()
{
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {   
        cout<<nodeCount[i]<<" ";
    }
}

void TopologicalSort()
{
    for(int i=1;i<=n;i++)
    {
        if(nodeCount[i]==0) q.push(i);
    }
    
    
    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        cout<<curNode<<" ";
        for(int i=0;i<graph[curNode].size();i++)
        {
            int linkedNodeWithCurNode = graph[curNode][i];
            nodeCount[linkedNodeWithCurNode]--;
            if(nodeCount[linkedNodeWithCurNode] == 0)
                q.push(linkedNodeWithCurNode); 
        }
    }
}

int main()
{
    fastio;
    int a,b;
    memset(nodeCount,0,sizeof(nodeCount));
    cin>>n>>m;
    graph.assign(n+1, vector<int>(0,0));
    for(int i=0;i<m;i++) // a가 b의 앞이다, 즉 a->b
    {
        cin>>a>>b;
        graph[a].push_back(b);
        nodeCount[b]++;
    }
    TopologicalSort();
}