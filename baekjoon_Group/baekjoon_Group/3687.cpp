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

const int MAX = 101;
const int INF = 987654321;

int n,imsi;
int dp[MAX]={0,};// 성냥 i개로 만들 수 있는 최솟값
int nums[10] = {2,5,5,4,5,6,3,7,6,6}; // 각 숫자를 만드는 성냥개비


//최대 수 : 짝수면 싹다 1로 채우기, 홀수면 7 한번 넣고 1로 채우기
void MaximalPrint(int num){
    if(num%2!=0) 
    {
        num-=3;
        cout<<'7';
    }
    while(num>0)
    {
        num-=2;
        cout<<'1';
    }
    cout<<" ";
}
//최소 수 : 이건 dp쓰는게 맞을듯

int Minimal(int left){
    //기저사례
    if(left<=0) return 0;

    //dp
    int& res = dp[left];
    if(res!=-1) return res;

    res=INF;
    //메인함수
    for(int i=0;i<10;i++)
        res = min(res,Minimal(left-nums[i])+dp[left-nums[i]]*10);
    return res;
}

int main()
{
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>imsi;
        cout<<Minimal(imsi)<<" ";
        MaximalPrint(imsi);
    }
}