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

long long escRank[31][3];
//0 : esin2, 1 = ecos2, 2 = esc

/*
1     2 (esin2 미분)
   1 -2 (ecos2 미분)
-1 1 1 (esc 미분)

*/

void DebugEscRank(int now)
{
    for(int j=0;j<3;j++)
        cout<<escRank[now+1][j]<<" ";
    cout<<"\n";
}

int main()
{
    long long num;
    cin>>num;
    memset(escRank,0,sizeof(escRank));
    escRank[1][0] = -1;
    escRank[1][1] = 1;
    escRank[1][2] = 1;
    for(int i=1;i<num;i++)   
    {
        escRank[i+1][0] = escRank[i][0]-escRank[i][2];
        escRank[i+1][1] = escRank[i][1]+escRank[i][2];
        escRank[i+1][2] = 2*escRank[i][0]-2*escRank[i][1]+escRank[i][2];
    }
    cout<<escRank[num][0]+escRank[num][1]+escRank[num][2];
}