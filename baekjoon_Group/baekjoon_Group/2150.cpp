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
int parentNodeNum[arrayLimit];
bool isBelongedToScc[arrayLimit];
vector<vector<int>> scc;
vector<vector<int>> graphForScc;
int nodeCount,lineCount;

int MakeSccByTarzan(int nowNode)
{   
    parentNodeNum[nowNode] = nowNode;
    stackForSccFind.push(nowNode);
    int parent = nowNode;

    for(int i=0;i<graphForScc[nowNode].size();i++){
        int nextNode = graphForScc[nowNode][i];

        //min을 쓰는 이유
        // -> DFS를 가장 낮은 정점부터 시작하기 때문에, 가장 차수 높은 부모는 낮은 숫자에 있기때문
        if(parentNodeNum[nextNode]==0) //방문 x 정점의 경우
            parent = min(parent,MakeSccByTarzan(nextNode)); 
        else if(!isBelongedToScc[nextNode]) // 방문했지만 scc에 속하지 않은 정점
            parent = min(parent,parentNodeNum[nextNode]); 
    }

    if(parent == nowNode)
    {
        vector<int> sccArray;
        while(1)
        {    
            int sccPieceNum = stackForSccFind.top();
            sccArray.push_back(sccPieceNum);
            isBelongedToScc[sccPieceNum] = true; 
            stackForSccFind.pop();
            if(sccPieceNum == nowNode) break;
        }
        sort(sccArray.begin(),sccArray.end());
        scc.push_back(sccArray);
    }
    
    return parent;
}

int main()
{
    fastio;
    memset(parentNodeNum,0,sizeof(parentNodeNum));
    memset(isBelongedToScc,false,sizeof(isBelongedToScc));
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
        if(parentNodeNum[i]==0)
            MakeSccByTarzan(i);
    }
    
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