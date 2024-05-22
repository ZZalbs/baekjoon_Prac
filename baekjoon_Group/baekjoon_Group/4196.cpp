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


const int ARRAYLIMIT = 100002;


//이거까지 풀고 트리로 넘어가기!
int testcaseCount;

int dominoCount;
int linkCount;
vector<vector<int>> dominoLink;

int nodeGroupIdSet[ARRAYLIMIT];
int nodeGroupId=0;
int sccId[ARRAYLIMIT];
bool isDfsFinished[ARRAYLIMIT];
stack<int> stackForScc;
vector<vector<int>> scc;

int sccIndegree[ARRAYLIMIT];


void Initialize()
{
    dominoLink.assign(ARRAYLIMIT,vector<int>(0,0));
    memset(nodeGroupIdSet,0,sizeof(nodeGroupIdSet));
    nodeGroupId=0;
    memset(sccId,0,sizeof(sccId));
    memset(isDfsFinished,false,sizeof(isDfsFinished));
    scc.clear();
    memset(sccIndegree,0,sizeof(sccIndegree));
    while(!stackForScc.empty())
        stackForScc.pop();
}

void InputLink()
{
    int firstDomino,secondDomino;
    cin>>dominoCount>>linkCount;
    for(int i=0;i<linkCount;i++)
    {
        cin>>firstDomino>>secondDomino;
        dominoLink[firstDomino].push_back(secondDomino);
    }
}



int FindSccDfs(int nowNode)
{
    nodeGroupIdSet[nowNode] = ++nodeGroupId;
    int parent = nodeGroupIdSet[nowNode];
    stackForScc.push(nowNode);
    
    for(int i=0;i<dominoLink[nowNode].size();i++)
    {
        int nextNode = dominoLink[nowNode][i];
        if(nodeGroupIdSet[nextNode]==0)
            parent = min(parent,FindSccDfs(nextNode));
        if(!isDfsFinished[nextNode])
            parent = min(parent,nodeGroupIdSet[nextNode]);
    }

    if(parent==nodeGroupIdSet[nowNode])
    {
        vector<int> sccRow;
        while(true)
        {
            int targetNode = stackForScc.top();
            stackForScc.pop();
            isDfsFinished[targetNode]=true;
            sccId[targetNode] = scc.size();
            sccRow.push_back(targetNode);
            if(targetNode==nowNode) break;
        }
        sort(sccRow.begin(),sccRow.end());
        scc.push_back(sccRow);
    }

    return parent;
}

void FindScc()
{
    for(int i=1;i<=dominoCount;i++)
    {
        if(nodeGroupIdSet[i] == 0 )
            FindSccDfs(i);
    }
}

void PrintScc()
{
    for(int i=0;i<scc.size();i++)
    {
        cout<<":";
        for(int j=0;j<scc[i].size();j++)
        {
            cout<<scc[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void CheckSccIndegree()
{
    for(int i=1;i<=dominoCount;i++)
    {
        for(int j=0;j<dominoLink[i].size();j++)
        {
            int linkedDomino = dominoLink[i][j];
            if(sccId[linkedDomino] == sccId[i]) continue;
            sccIndegree[sccId[linkedDomino]]++;
        }
    }
}

void PrintSccIndegree()
{
    for(int i=0;i<scc.size();i++)
    {
        cout<<sccIndegree[i]<<" ";
    }
    cout<<"\n";
}

int CountSccIndegreeZero()
{
    int countIndegreeZero=0;
    for(int i=0;i<scc.size();i++)
    {
        if(sccIndegree[i]==0) countIndegreeZero++;
    }
    return countIndegreeZero;
}

int main()
{
    fastio;
    cin>>testcaseCount;
    for(int i=0;i<testcaseCount;i++){
        Initialize();
        InputLink();
        FindScc();
        //PrintScc();
        CheckSccIndegree();
        //PrintSccIndegree();
        cout<<CountSccIndegreeZero()<<"\n";
    }
    
}
