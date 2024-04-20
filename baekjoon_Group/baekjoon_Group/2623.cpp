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

const int arrayLimit = 10002;

int singerCount,pdCount;
vector<vector<int>> performRules;
int frontSingerNum, backSingerNum;
int singerCountPerPD;
int headNodeCount[arrayLimit];
queue <int> queueForBFS;
vector<int> singerFinalOrder;
bool visited[arrayLimit]={false,};

void TopologicalSort()
{
    for(int i=1;i<=singerCount;i++)
    {
        if(headNodeCount[i] == 0 ) queueForBFS.push(i);
    }

    for(int i=1;i<=singerCount;i++)
    {
        if(queueForBFS.empty()) 
        {
            singerFinalOrder.clear();
            singerFinalOrder.push_back(0);
            return;
        }

        int nowSingerNum = queueForBFS.front();
    
        if(visited[nowSingerNum]) continue;
        visited[nowSingerNum]=true;    

        singerFinalOrder.push_back(nowSingerNum);
        queueForBFS.pop();
        for(int j=0;j<performRules[nowSingerNum].size();j++)
        {
            int linkedSinger = performRules[nowSingerNum][j];
            headNodeCount[linkedSinger]--;
            if(headNodeCount[linkedSinger]==0) queueForBFS.push(linkedSinger);
        }
    }
}

void PrintSingerOrder()
{
    for(int i=0;i<singerFinalOrder.size();i++)
    {
        cout<<singerFinalOrder[i]<<"\n";
    }
}

int main()
{
    fastio;
    performRules.assign(arrayLimit,vector<int>(0,0));
    memset(headNodeCount,0,sizeof(headNodeCount));

    cin>>singerCount>>pdCount;
    for(int i=0;i<pdCount;i++)
    {
        // 1 4 3 -> (1,4),(4,3)
        cin>>singerCountPerPD;
        cin>>frontSingerNum;
        for(int j=0;j<singerCountPerPD-1;j++)
        {
            cin>>backSingerNum;
            performRules[frontSingerNum].push_back(backSingerNum);
            headNodeCount[backSingerNum]++;
            frontSingerNum=backSingerNum;
        }
    }
    TopologicalSort();
    PrintSingerOrder();
}