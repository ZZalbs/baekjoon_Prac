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
int nodeIdForGrouping[arrayLimit]; // 임의로 지정한 노드의 id. scc 탐색간 방문여부 판단 및 그룹핑에 사용
bool isDfsFinished[arrayLimit];
vector<vector<int>> scc;
vector<vector<int>> graphForScc;
int nodeCount,lineCount;
int idUnused;

int MakeSccByTarzan(int nowNode)
{   
    nodeIdForGrouping[nowNode] = ++idUnused;
    stackForSccFind.push(nowNode);
    int parent = nodeIdForGrouping[nowNode];

    for(int i=0;i<graphForScc[nowNode].size();i++){
        int nextNode = graphForScc[nowNode][i];

        //min을 쓰는 이유
        // -> DFS를 가장 낮은 정점부터 시작하기 때문에, 가장 차수 높은 부모는 낮은 숫자에 있기때문
        if(nodeIdForGrouping[nextNode]==0) //방문 x 정점의 경우
            parent = min(parent,MakeSccByTarzan(nextNode)); 
        else if(!isDfsFinished[nextNode]) // 방문했지만 dfs가 안끝난 정점
            parent = min(parent,nodeIdForGrouping[nextNode]); 
    }

    if(parent == nodeIdForGrouping[nowNode]) 
    {
        vector<int> sccArray;
        while(1)
        {    
            int sccPieceNum = stackForSccFind.top();
            sccArray.push_back(sccPieceNum);
            isDfsFinished[sccPieceNum] = true; 
            stackForSccFind.pop();
            if(sccPieceNum == nowNode) break;
        }
        sort(sccArray.begin(),sccArray.end());
        scc.push_back(sccArray);
    }
    
    return parent;
}

bool CompSccArray(vector<int>& vecA,vector<int>& vecB)
{
    return vecA[0]<vecB[0];
}

int main()
{
    fastio;
    idUnused=1;
    memset(nodeIdForGrouping,0,sizeof(nodeIdForGrouping));
    memset(isDfsFinished,false,sizeof(isDfsFinished));
    graphForScc.assign(arrayLimit,vector<int>(0,0));
    cin>>nodeCount>>lineCount;
    for(int i=0;i<lineCount;i++)
    {
        int lineStartNode,lineEndNode;
        cin>>lineStartNode>>lineEndNode;
        graphForScc[lineStartNode].push_back(lineEndNode);
    }

    for(int i=1;i<=nodeCount;i++)
    {
        if(nodeIdForGrouping[i]==0)
            MakeSccByTarzan(i);
    }
    
    sort(scc.begin(),scc.end(),CompSccArray);

    cout<<scc.size()<<"\n";
    for(int i=0;i<scc.size();i++)
    {
        for(int j=0;j<scc[i].size();j++)
        {
            cout<<scc[i][j]<<" ";
        }
        cout<<"-1\n";
    }
}