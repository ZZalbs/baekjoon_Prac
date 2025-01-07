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
(a^n * a^m) mod k = ( (a^n)mod k * (a^m)mod k ) mod k
모듈러 연산에 성립하는 곱셈 법칙

이걸 재귀함수로 구현하면, a와 n이 아무리 커도 쪼개 풀 수 있다
라는 아이디어
*/

long long num, upper, modular;

long long SquareMod(long long num,long long upper)
{
    //기저
    if(upper==1)
    {
        return num%modular;
    }
    
    //메인
    if(upper%2==0)
        return (SquareMod(num,upper/2)*SquareMod(num,upper/2)) % modular;
    else
        return (SquareMod(num,upper/2)*SquareMod(num,upper/2+1)) % modular;

    
}

int main()
{
    
    cin>>num>>upper>>modular;
    cout<<SquareMod(num,upper);
}