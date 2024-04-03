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

const int MAX = 101;
const int INF = 987654321;

vector<vector<int>> graph; // 그래프
vector<bool> visited;

void DFS(int here)
{
    visited[here]=true;
    for(int i=0;i<graph[here].size;i++)
    {
        if(!visited[i]) DFS(graph[here][i]);
    }
}


int main()
{

}