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

const int MAX = 1000001;
const int INF = 100000001;

int n,w; // 판 넓이, 사건 수
vector<pair<int,int>> event;
int dp[MAX][MAX]; // 1번차의 현 사건 , 2번차의 현 사건
vector<int> record; // 자동차의 사건해결기록. 마지막 정답에 사용
/*
dp[2][1] -> dp[2][3]로 갈 때, 
p => event[1].first , event[1].second
eventind = 3

dp[k][k]는 존재할 수 없는 값이므로, 여기에  넣어놓으면 될듯
*/

void PrintDP()
{
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
}

int GetDistance(pair<int,int> p,int eventInd)
{
    return abs(p.first - event[eventInd].first) + abs(p.second - event[eventInd].second);
}

int Police(int first, int second) // 탑다운으로 해보죠
{
    // 기저사례
    if(first == w || second == w) return 0;

    //dp
    int& res = dp[first][second];
    if(res != -1) return INF;

    //메인함수
    //dfs ㄱㄱ
    int maxIndex = max(first,second)+1;
    // 2번차가 갈 때, 1번차는 기존 인덱스를 유지하고 2번차의 사건인덱스만 i로 변화
    int& fSearch = dp[first][maxIndex];
    fSearch = min(fSearch,Police(first,second+1) + GetDistance(event[first],i));
    // 1번차가 갈 때, 2번차는 기존 인덱스를 유지하고 1번차의 사건인덱스만 i로 변화
    int& sSearch = dp[maxIndex][second];
    sSearch = min(sSearch,Police(first+1,second) + GetDistance(event[second],i));
    
    return min(fSearch,sSearch);
}


int main()
{
    fastio;
    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
    int imsiX,imsiY;
    for(int i=0;i<w;i++)
    {
        cin>>imsiX>>imsiY;
        event.push_back(make_pair(imsiX,imsiY));
    }
    dp[0][0] = 0;
    Police();
    PrintDP();
}