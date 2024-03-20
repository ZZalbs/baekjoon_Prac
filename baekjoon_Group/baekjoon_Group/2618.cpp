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
carx = event[1].first 
cary = event[1].second
eventind = 3

dp[k][k]는 존재할 수 없는 값이므로, 여기에  넣어놓으면 될듯
*/



int GetDistance(int carx,int cary,int eventInd)
{
    return abs(carx - event[eventInd].first) + abs(cary - event[eventInd].second);
}

int Police(int first,int second)
{
    //마지막 사건 도달
    if(first==w || second==w) return 0;
    
    //dp
    int& res = dp[first][second];
    if(res !=-1) return res;
    

    

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
    dp[0][1] = GetDistance(0,0,1);
    dp[1][0] = GetDistance(n,n,1);
}