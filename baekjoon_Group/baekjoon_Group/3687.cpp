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
long long dp[MAX]={0,};// 성냥 i개로 만들 수 있는 최솟값
int nums[8] = {INF,INF,1,7,4,2,0,8}; // i개로 만들 수 있는 최소 한자리수
// 2 : 1 , 3 : 7, 4 : 4, 5 : 2, 6 : 0, 7 : 8

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
}
//최소 수 : 이건 dp쓰는게 맞을듯
long long Minimal(int left){
    for(int i=0;i<8;i++)
        dp[i] = nums[i];
    dp[6] = 6; // 숫자는 0으로 시작 불가
    for(int i=8;i<=left;i++)
    {   
        for(int j=2;j<8;j++)
        {
            if(dp[i]==-1) dp[i] = dp[i-j]*10 + nums[j]; 
            else dp[i] = min(dp[i],dp[i-j]*10 + nums[j]);
        }
    }
    
    return dp[left];
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
        cout<<"\n";
    }
}