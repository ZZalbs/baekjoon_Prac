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
#include <map>
#include <cmath>
using namespace std;

#define MAX 40000001

bool isSosu[MAX];
vector<long long> sosuVec;
  
void DoEratosthenes(long long end)
{
    for(int i=2;i*i<end;i++) 
    {
        if(isSosu[i]==false)
            continue;

        long long j=2;
        while(i*j<=end)
        {
            isSosu[i*j] = false;
            j++;
        }
    }
}

void SosuInit()
{
    memset(isSosu,true,sizeof(isSosu));
    isSosu[1] = false;
    isSosu[2] = true;
    isSosu[3] = true;
}


int main()
{
    SosuInit();
    DoEratosthenes(MAX);

    int num;
    cin>>num;
    
    for(int i=1;i<MAX;i++)
        if(isSosu[i])
            sosuVec.push_back(i);

    long long sumStart=0, sumEnd=0, sum=0,resultCnt=0;
    while(sosuVec[sumStart]<=num||sumEnd>sosuVec.size()) // 투포인트 풀이
    {
        sum=0;
        for(int i=sumStart;i<=sumEnd;i++)
            sum+=sosuVec[i];
        
        //cout<<sum<<" ";
        if(sum==num)
            resultCnt++;
        
        if(sum<num){
            sumEnd++;
        }
        else{
            sumStart++;
            sumEnd=sumStart;
        }
    }
    
    cout<<resultCnt;
}
