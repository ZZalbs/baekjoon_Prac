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

//4013 풀기전에 먼저 풀어야 할 문제
//scc(강한연결요소) 관련 기초문제임

/*
[타잔 알고리즘]
각 정점의 자기자신을 부모노드로 설정하고, 스택에 넣으며 DFS를 돌림
갔던 점을 또 갔을 때 (부모노드값이 이미 있을때)
역순으로 거슬러가 부모노드를 모두 수정하기
부모노드[x] = x라면 
스택에서 자기자신이 나올때까지 빼서 SCC 만들기
*/

const int arrayLimit = 10002;
stack<int> stackForSccFind;
bool isDfsFinishedOnThisNode[arrayLimit];
int parentNodeNum[arrayLimit];
vector<vector<int>> scc;
vector<vector<int>> graphForScc;
int nodeCount,lineCount;



int main()
{
    fastio;
    memset(parentNodeNum,0,sizeof(parentNodeNum));
    graphForScc.assign(arrayLimit,vector<int>(0,0));
    cin>>nodeCount>>lineCount;
    for(int i=0;i<lineCount;i++)
    {
        int lineStartNode,lineEndNode;
        cin>>lineStartNode>>lineEndNode;
        graphForScc[lineStartNode].push_back(lineEndNode);
    }
}