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

#define fastio ios::sync_w

map<string,string> strSet;

int main()
{
    int setNum,checkNum;
    cin>>setNum>>checkNum;
    string str;
    for(int i=0;i<setNum;i++)
    {
        cin>>str;
        strSet.insert(make_pair(str,str));
    }
    int result=0;
    for(int i=0;i<checkNum;i++)
    {
        cin>>str;
        if(strSet.find(str)!=strSet.end())
            result++;
    }
    cout<<result;
}