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

#define MAX 1000000000


int main()
{
    long long testcase;
    long long moneyUnit[4] = {25,10,5,1};
    long long money,resultByMoney;
    cin>>testcase;
    for(int t=0;t<testcase;t++){
        cin>>money;
        for(int i=0;i<4;i++)
        {
            resultByMoney = (long long)floor((double)money/moneyUnit[i]);
            cout<<resultByMoney<<" ";
            money -= (moneyUnit[i]*resultByMoney);
        }
        cout<<"\n";
    }
}