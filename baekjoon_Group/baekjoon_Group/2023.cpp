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

#define MAX 100000001

//bool isSosu[MAX];
int nextOddNum[5] = {1,3,5,7,9};
int oneZariSosu[4] = {2,3,5,7};

bool BoolEratosResult(long long end)
{
    for(int i=2;i*i<=end;i++) 
    {
        if(end%i==0)
            return false;
    }
    return true;
}


int main()
{
    int num;
    cin>>num;

    vector<long long> lastSosu;
    vector<long long> weirdSosu;
    for(int j=0;j<4;j++)
    {
        lastSosu.push_back(oneZariSosu[j]);
    }
    weirdSosu = lastSosu;

    int i = 1;
    while(i<num)
    {
        lastSosu.clear();
        for(int k=0;k<weirdSosu.size();k++){
            for(int j=0;j<5;j++)
            {
                long long checkNum = weirdSosu[k]*10 + nextOddNum[j];
                if(BoolEratosResult(checkNum))
                    lastSosu.push_back(checkNum);
            }
        }
        weirdSosu = lastSosu;
        i++;
    }

    for(int j=0;j<weirdSosu.size();j++)
    {
        cout<<weirdSosu[j]<<"\n";
    }
    
}