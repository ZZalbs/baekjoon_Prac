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



queue<int> q; // kahn 위상정렬용 큐
int n,m;
vector<vector<int>> graph;

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

int main()
{
    fastio;
    int a,b;
    cin>>n>>m;
    graph.assign(n+1, vector<int>(0,0));
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
    }
}