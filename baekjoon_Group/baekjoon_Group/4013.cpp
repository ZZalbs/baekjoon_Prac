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

// ic와 레스토랑 모두 정점의 종류임. 목적지는 레스토랑, ic는 목적지가 될 수 없음

const int ARRAYLIMIT = 10002;


int icCount,roadCount;
int icHead,icTail;
int moneyAmount;
int startIcNum, restaurantCount;
vector<vector<int>> road;
int headNodeCount[ARRAYLIMIT];
int icValue[ARRAYLIMIT];
vector<int> restaurant;

stack<int> stackForScc;
vector<vector<int>> scc;
vector<int> sccRow;
int nodeGroupIdSet[ARRAYLIMIT];
int nowGroupId;
bool isDfsFinished[ARRAYLIMIT];


int FindSccWithTarzan(int nowNode)
{
    nodeGroupIdSet[nowNode]=++nowGroupId;
    int parentNode = nodeGroupIdSet[nowNode];
    stackForScc.push(nowNode);
    
    for(int i=0;i<road[nowNode].size();i++)
    {
        int nextNode = road[nowNode][i];
        if(nodeGroupIdSet[nextNode] == 0)
            parentNode = min(parentNode,FindSccWithTarzan(nextNode));
        else if(!isDfsFinished[nextNode])
            parentNode = min(parentNode,nodeGroupIdSet[nextNode]);
    }

    if(parentNode == nodeGroupIdSet[nowNode])
    {
        while(true)
        {
            int targetNode = stackForScc.top();
            isDfsFinished[targetNode] = true;
            sccRow.push_back(targetNode);
            stackForScc.pop();
            if(targetNode == nowNode) break;
        }
        sort(sccRow.begin(),sccRow.end());
        scc.push_back(sccRow);
    }

    return parentNode;
}

void Initialize()
{
    fastio;
    memset(headNodeCount,0,sizeof(headNodeCount));
    memset(icValue,0,sizeof(icValue));
    road.assign(ARRAYLIMIT,vector<int>(0,0));
    memset(nodeGroupIdSet,0,sizeof(nodeGroupIdSet));
    memset(isDfsFinished,false,sizeof(isDfsFinished));
    nowGroupId=0;
}

void GetInput()
{
    cin>>icCount>>roadCount;
    for(int i=0;i<roadCount;i++)
    {
        cin>>icHead>>icTail;
        road[icHead].push_back(icTail);
        headNodeCount[icTail]++;
    }
    for(int i=1;i<=icCount;i++)
       cin>>icValue[i];

    cin>>startIcNum>>restaurantCount;
    for(int i=1;i<=restaurantCount;i++){
        int imsiRestaurant;
        cin>>imsiRestaurant;
        restaurant.push_back(imsiRestaurant);
    }
}

void PrintScc()
{
    cout<<"\n";
    for(int i=0;i<scc.size();i++)
    {
        for(int j=0;j<scc[i].size();j++)
            cout<<scc[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    Initialize();
    GetInput();
    
    for(int i=1;i<=icCount;i++)
    {
        if(nodeGroupIdSet[i] != 0 )
            FindSccWithTarzan(i);
    }

    PrintScc();
    
}