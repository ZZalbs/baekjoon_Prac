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

/*
1
1+ 6*1
1+ 6*3
1+ 6*6
...

n칸 이동시 도착:  입력수    <=    1+ 6*(n-1번째 삼각수)
(입력수 - 1)/6     <=     n-1번째 삼각수
n-1을 구한 뒤, +1 하면 정답이네

*/

int main()
{
    long long num;
    long long triangleNum = 0;
    long long plusNum = 1;
    long long cnt=0;
    cin>>num;
    
    double compare = (num-1)/6.0;
    while(compare>triangleNum)
    {
        cnt++;
        triangleNum+=plusNum;
        plusNum++;
        //cout<<cnt<<" "<<triangleNum<<"\n";
    }
    cout<<cnt+1;

}