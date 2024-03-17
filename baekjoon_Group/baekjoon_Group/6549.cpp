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

    //사각형이 중간을 포함할때
    int lo = mid, hi = mid+1;
    long long height = min(hist[lo],hist[hi]);
    res = max(res, height * 2); // 초기값 : mid, mid+1의 최대사각형
    while(left < lo || hi < right)
    {
        if(hi < right && (lo==left || hist[lo-1] < hist[hi+1]))
        {
            hi++;
            height = min(height,hist[hi]);
        }
        else // (hi == right || hist[lo-1] > hist[hi+1]) 의 경우
        {
            lo--;
            height = min(height,hist[lo]);
        }
        res = max(res, height * (lo-hi+1));
    }
    return res;
}

int main()
{
    fastio;
    long long imsi;
    while(n!=0)    
    {
        hist.clear();
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            cin>>imsi;
            hist.push_back(imsi);
        }
        cout<<Square(0,n)<<"\n";
    }
}