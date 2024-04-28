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


/*
문제 걍 여따써야지

어떤 선수가 A구역에서 B구역으로 이동하게 하는 움직임을 (A, B)로 표현한다.
다른 모든 구역에 도달할 수 있는 시작 구역을 찾아라.


첫 번째 줄에 테스트 케이스의 개수가 주어지며, 이는 11보다 작거나 같은 정수이다.
그 다음 줄부터 여러 개의 테스트 케이스가 주어지는데, 
각 테스트 케이스마다 첫 번째 줄에 구역의 수 N, 지시한 움직임의 수 M이 주어지며 1 ≤ N, M ≤ 100,000 이다. 
그 다음 M개의 줄에 걸쳐서 움직임 (A, B)가 주어지며, A, B는 0 ≤ A, B < N인 정수이다.
각 테스트 케이스는 하나의 빈 줄로 구분된다.

각 테스트 케이스마다 가능한 모든 시작 구역을 오름차순으로 한 줄에 하나씩 출력한다. 
만약 그러한 시작 구역이 없으면, "Confused"를 출력한다.
각 테스트 케이스의 끝에는 하나의 빈 줄을 출력한다.
*/

int areaCount,moveCount;
vector<vector<int>> moveSet;


int FindSccByTarzan(int nowNode)
{
    
}

int main()
{

}