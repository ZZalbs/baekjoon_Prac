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

const int MAX = 1003;
const int INF = 100000001;

int n,w; // 판 넓이, 사건 수
vector<pair<int,int>> event;
int dp[MAX][MAX]; // 1번차의 현 사건 , 2번차의 현 사건
int record[MAX]; // 자동차의 사건해결기록. 마지막 정답에 사용
queue<pair<int,int>> q;
/*
dp[2][1] -> dp[2][3]로 갈 때, 
p => event[1].first , event[1].second
eventind = 3

dp[k][k]는 존재할 수 없는 값이므로, 여기에 최소 넣어놓으면 될듯
*/

void PrintDP()
{
    for(int i=0;i<=w;i++){
        for(int j=0;j<=w;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
}

int GetDistance(int nowInd,int nextInd)
{
    return abs(event[nowInd].first - event[nextInd].first) + abs(event[nowInd].second - event[nextInd].second);
}

int Police(int first, int second) // (A위치, B위치) 탑다운 풀이.
{
    // 기저사례
    if(first == w+1 || second == w+1) return 0;

    //dp
    int& res = dp[first][second];
    if(res != -1) return res;

    //메인함수
    //dfs ㄱㄱ
    res = INF;
    int maxIndex = max(first,second)+1;

    // 2번차가 갈 때, 1번차는 기존 인덱스를 유지하고 2번차의 사건인덱스만 i로 변화
    //int& fSearch = dp[first][maxIndex];
    if(second==0) event[0] = make_pair(n,n);
        int fSearch = Police(first,maxIndex)+GetDistance(second,maxIndex);

    // 1번차가 갈 때, 2번차는 기존 인덱스를 유지하고 1번차의 사건인덱스만 i로 변화
    //int& sSearch = dp[maxIndex][second];
    if(first==0) event[0] = make_pair(0,0);
        int sSearch = Police(maxIndex,second) + GetDistance(first,maxIndex);
    
    return res=min(fSearch,sSearch);
}
/*
void Police() // 바텀업 풀이. dp는 잘 나오지만, 왔던길 체크가 너무 어려워서 기각
{
    //메인함수

    for(int i=1;i<=w;i++)
    {   //bfs 이용 탐색할 예정
        int size_Q = q.size();
        for(int j=0;j<size_Q;j++){
            int nowA = q.front().first; // 지금 1번차의 사건인덱스
            int nowB = q.front().second;// 지금 2번차의 사건인덱스
            q.pop();

    // 2번차가 갈 때, 1번차는 기존 인덱스를 유지하고 2번차의 사건인덱스만 i로 변화
            int& fSearch = dp[nowA][i];
            if(nowA==0) event[nowA] = make_pair(n,n);
            if(fSearch==-1)
                fSearch = dp[nowA][nowB] + GetDistance(event[nowB],i);
            else
                fSearch = min(fSearch,dp[nowA][nowB] + GetDistance(event[nowB],i));
            q.push(make_pair(nowA,i));

    // 1번차가 갈 때, 2번차는 기존 인덱스를 유지하고 1번차의 사건인덱스만 i로 변화
            int& sSearch = dp[i][nowB];
            if(nowB==0) event[nowB] = make_pair(0,0);
            if(sSearch==-1)
                sSearch = dp[nowA][nowB] + GetDistance(event[nowA],i);
            else
                sSearch = min(sSearch,dp[nowA][nowB] + GetDistance(event[nowA],i));
            q.push(make_pair(i,nowB));
        }
    }
}
*/

int main()
{
    fastio;
    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
    int imsiX,imsiY;
    event.push_back(make_pair(0,0));
    for(int i=0;i<w;i++)
    {
        cin>>imsiX>>imsiY;
        event.push_back(make_pair(imsiX,imsiY));
    }
    //q.push(make_pair(0,0));
    Police(0,0);
    PrintDP();
}