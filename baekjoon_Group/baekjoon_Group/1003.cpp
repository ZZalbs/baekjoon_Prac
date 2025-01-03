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
#define fastio ios::sync_w
#define MAX 41 
using namespace std;

long long fiboDPZeroOne[MAX][2];

int main()
{
    int testCaseNum,fiboNum;
    memset(fiboDPZeroOne,0,sizeof(fiboDPZeroOne));
    fiboDPZeroOne[0][0]=1;
    fiboDPZeroOne[1][1]=1;
    for(int i=2;i<=40;i++)
        for(int j=0;j<=1;j++)
            fiboDPZeroOne[i][j] = fiboDPZeroOne[i-1][j]+fiboDPZeroOne[i-2][j];
    
    cin>>testCaseNum;
    for(int i=0;i<testCaseNum;i++){
        cin>>fiboNum;
        cout<<fiboDPZeroOne[fiboNum][0]<<" "<<fiboDPZeroOne[fiboNum][1]<<"\n";
    }
}