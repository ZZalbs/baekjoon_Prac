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

#define MAX 1000000000

int main()
{
    /*  야매 풀이 - 포문인데 시작점만 잡아줌
    long long up,down,height;
    long long nowHeight=0;
    cin>>up>>down>>height;
    long long startNum;
    startNum =(height-down)/(up-down);
    
    for(long long i=startNum;i<=MAX;i++)
    {
        nowHeight = up*i-down*(i-1);
        if(nowHeight >= height){
            cout<<i;
            return 0;
        }
    } */

   /* 정석 풀이
   i * (up-down) + down >= height
   i >= (height - down) / (up-down)
   이때, 우변 값이 나눠떨어지면 그 숫자가 정답이고,
   나눠떨어지지 않으면 다음 날 낮에 등반을 끝내는 케이스이므로 +1 을 해줌
   */
   long long up,down,height;
    long long nowHeight=0;
    cin>>up>>down>>height;
    long long result, leftover;
    result =(height-down)/(up-down);
    leftover = (height-down)%(up-down);
    if(leftover == 0)
        cout<<result;
    else
        cout<<result+1;
    
}