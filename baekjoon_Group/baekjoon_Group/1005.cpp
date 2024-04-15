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

const int arrayLimit = 100002;

int testCaseCount,buildingCount,buildRulesCount;
int timeForEachBuilding[arrayLimit];
int preBuildNum,laterBuildNum;
int finalBuildNum;
vector<vector<int>> buildRules;
queue<int>  queueForBFS;
int nodeCount[arrayLimit];
int timeForFullBuilding[arrayLimit];

void ResetTestCase()
{
    buildingCount=0;
    buildRulesCount=0;
    finalBuildNum=0;
    memset(nodeCount,0,sizeof(nodeCount));
    memset(timeForEachBuilding,0,sizeof(timeForEachBuilding));
    memset(timeForFullBuilding,0,sizeof(timeForFullBuilding));
    buildRules.assign(arrayLimit,vector<int>(0,0));
}

void InputTestCaseAndSetBuildRules()
{
    cin>>buildingCount>>buildRulesCount;
    for(int i=1;i<=buildingCount;i++)
        cin>>timeForEachBuilding[i];
    for(int i=1;i<=buildRulesCount;i++)
    {
        cin>>preBuildNum>>laterBuildNum;
        buildRules[preBuildNum].push_back(laterBuildNum);
        nodeCount[laterBuildNum]++;
    }
    cin>>finalBuildNum;
}
void TopologicalSort() // 위상 정렬
{
    for(int i=1;i<=buildingCount;i++)
        if(nodeCount[i] == 0) 
        {
            queueForBFS.push(i);
            timeForFullBuilding[i] = timeForEachBuilding[i]; 
        }

    while(!queueForBFS.empty())
    {
        int nowNode = queueForBFS.front();
        queueForBFS.pop();
        
        for(int i=0;i<buildRules[nowNode].size();i++)
        {
            int connectedNode = buildRules[nowNode][i];
            nodeCount[connectedNode]--;
            timeForFullBuilding[connectedNode] = max(timeForFullBuilding[connectedNode], timeForFullBuilding[nowNode] + timeForEachBuilding[connectedNode]); 
            if(nodeCount[connectedNode] == 0) queueForBFS.push(connectedNode);
        }
    }
}

void PrintResult()
{
    cout<<timeForFullBuilding[finalBuildNum]<<"\n";
}

void PrintTimeForFullBuilding()
{
    for(int i=1;i<=buildingCount;i++)
        cout<<timeForFullBuilding[i]<<" "; // 임시로 each로 바꿈
    cout<<"\n";
}

void PrintBuildRules()
{
    for(int i=1;i<=buildingCount;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<buildRules[i].size();j++)
            cout<<buildRules[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    fastio;
    cin>>testCaseCount;
    for(int i=0;i<testCaseCount;i++)
    {
        ResetTestCase();
        InputTestCaseAndSetBuildRules();
        TopologicalSort();
        PrintResult();
    }
    
}

