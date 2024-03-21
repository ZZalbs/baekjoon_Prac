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
queue<pair<int,int>> q;
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

void Police() // 바텀업이 유리할듯. 현재 메모리 오류 뜨ㅏㅁ. q에 2^w승 개수의 숫자 들어가서 터지나본데?
{
    //메인함수

    for(int i=1;i<w;i++)
    {   //bfs 이용 탐색할 예정
        int size_Q = q.size();
        for(int j=0;j<size_Q;j++){
            int nowA = q.front().first; // 지금 1번차의 사건인덱스
            int nowB = q.front().second;// 지금 2번차의 사건인덱스
            q.pop();

    // 2번차가 갈 때, 1번차는 기존 인덱스를 유지하고 2번차의 사건인덱스만 i로 변화
            int& fSearch = dp[nowA][i];
            if(nowA==0) event[nowA] = make_pair(0,0);
            if(fSearch==-1)
                fSearch = dp[nowA][nowB] + GetDistance(event[nowA],i);
            else
                fSearch = min(fSearch,dp[nowA][nowB] + GetDistance(event[nowA],i));
            q.push(make_pair(nowA,i));

    // 1번차가 갈 때, 2번차는 기존 인덱스를 유지하고 1번차의 사건인덱스만 i로 변화
            int& sSearch = dp[i][nowB];
            if(nowB==0) event[nowB] = make_pair(n,n);
            if(sSearch==-1)
                sSearch = dp[nowA][nowB] + GetDistance(event[nowB],i);
            else
                sSearch = min(sSearch,dp[nowA][nowB] + GetDistance(event[nowB],i));
            q.push(make_pair(i,nowB));
        }
    }
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
    
    q.push(make_pair(0,0));
    Police();
    PrintDP();
}