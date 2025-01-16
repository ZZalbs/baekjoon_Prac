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

#define MAX 100000000001

long long num;

/*
k의 오일러 피 함수 값을 구하자.
소인수 p에 대해
k * (p-1/p)
*/

int main()
{
    cin>>num;
    long long res = num;

    for(long long i=2;i*i<=num;i++)
    {
        if(num%i==0)
            res = res/i * (i-1); // 곱하기 먼저하면 숫자 커져서 틀린다!
        while(num%i==0)
            num = num/i;
    }
    //예외 : num이 지수가 1인 소인수라서 안걸러질 경우( ex. 5 )
    //해당 소인수로 오일러 피 계산 한번 더 해주면 댐

    if(num == 1)
        cout << res;
    else
        cout << res/num * (num-1);
}