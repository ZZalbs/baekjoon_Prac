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


/*
문제 걍 여따써야지

어떤 선수가 A구역에서 B구역으로 이동하게 하는 움직임을 (A, B)로 표현한다.
다른 모든 구역에 도달할 수 있는 시작 구역을 찾아라.


첫 번째 줄에 테스트 케이스의 개수가 주어지며, 이는 11보다 작거나 같은 정수이다.
그 다음 줄부터 여러 개의 테스트 케이스가 주어지는데, 
각 테스트 케이스마다 첫 번째 줄에 구역의 수 N, 지시한 움직임의 수 M이 주어지며 1 ≤ N, M ≤ 100,000 이다. 
그 다음 M개의 줄에 걸쳐서 움직임 (A, B)가 주어지며, A, B는 0 ≤ A, B < N인 정수이다.
각 테스트 케이스는 하나의 빈 줄로 구분된다.

각 테스트 케이스마다 가능한 모든 시작 구역을 오름차순으로 한 줄에 하나씩 출력한다. 
만약 그러한 시작 구역이 없으면, "Confused"를 출력한다.
각 테스트 케이스의 끝에는 하나의 빈 줄을 출력한다.
*/

//고민노트

/*
일단 다 scc로 묶은 다음에, 차수 0인 scc가 1개 있는지 찾기.
-> 대신, 들어오는 간선 없는 scc가 2개 이상이면 무조건 confused 떠야함. 
*/

const int ARRAYLIMIT = 100002;

int testcaseCount;
int areaCount,moveCount;
vector<vector<int>> moveSet;
vector<vector<int>> scc;


stack<int> stackForScc;
bool isDfsFinished[ARRAYLIMIT];
int nodeId[ARRAYLIMIT];
int idUnused;

int sccZeroIndegreeCount;



int FindSccByTarzan(int nowNode)
{
    nodeId[nowNode]=++idUnused;
    int parentNode = nodeId[nowNode];
    stackForScc.push(nowNode);

    for(int i=0;i<moveSet[nowNode].size();i++)
    {
        int nextNode = moveSet[nowNode][i];
        if(nodeId[nextNode] == 0) 
            parentNode = min(parentNode,FindSccByTarzan(nextNode));
        else if(!isDfsFinished[nextNode])
            parentNode = min(parentNode,nodeId[nextNode]);
    }

    if(parentNode == nodeId[nowNode])
    {
        vector<int> sccRow;
        while(1)
        {
            int sccPiece = stackForScc.top();
            sccRow.push_back(sccPiece);
            isDfsFinished[sccPiece]=true;
            stackForScc.pop();
            if(sccPiece==nowNode) break;
        }
        scc.push_back(sccRow);
    }

    return parentNode;
}

void Initialize()
{
    moveSet.clear();
    moveSet.assign(ARRAYLIMIT,vector<int>(0,0));

    memset(nodeId,0,sizeof(nodeId));
    memset(isDfsFinished,false,sizeof(isDfsFinished));
    idUnused = 1;

    scc.clear();
    sccZeroIndegreeCount=0;
}

int main()
{
    fastio;
    
    cin>>testcaseCount;
    for(int t=0;t<testcaseCount;t++)
    {
        Initialize();
        cin>>areaCount>>moveCount;
        for(int i=0;i<moveCount;i++)
        {
            int moveStartPos, moveEndPos;
            cin>>moveStartPos>>moveEndPos;
            moveSet[moveStartPos].push_back(moveEndPos);
        }
        
        for(int i=0;i<areaCount;i++)
            FindSccByTarzan(i);
        
    // https://dbstndi6316.tistory.com/86 참고해서 수정하기

        if()
            cout<<"confused\n\n";
        else{
            for(int i=0;i<scc[0].size();i++)
            {
                cout<<scc[0][i]<<"\n";
            }
            cout<<"\n";
        }
    }
}