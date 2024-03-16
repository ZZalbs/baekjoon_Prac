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

int n=-1;
vector <long long> hist;

long long Square(int left, int right) // 분할정복으로 풀어볼거에요
{
    if(left==right) return hist[left];
    int mid = (left+right)/2;
    long long res;
    res=max(Square(left,mid),Square(mid+1,right));
    
    while()
    {
        
    }
}

int main()
{
    fastio;
    while(n!=0)    
    {
        hist.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>hist[i];
        }
        cout<<Square(0,n);
    }
}