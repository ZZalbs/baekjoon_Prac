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

#define MAX 10000001
bool isSosu[MAX];

void DoEratosthenes(long long end)
{
    for(int i=2;i*i<end;i++) // i의 제곱근까지만 구하면 됨. 이유는 후술
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

/*
n까지의 소수를 알기 위해서는, 루트n 까지의 소수 배수만 구하면 된다.
why? n= a×b 일 때, a와 b가 둘다 루트 n을 초과하는 경우가 없기 때문!
*/

int main()
{
    memset(isSosu,true,sizeof(isSosu));
    isSosu[1] = false;
    isSosu[2] = true;
    isSosu[3] = true;

    long long num;
    cin>>num;
    DoEratosthenes(MAX);
    int checkNum,cnt=0;
    for(int i=1;i<=num;i++)
    {
        cin>>checkNum;
        if(isSosu[checkNum])
            cnt++;
    }
    cout<<cnt;
}