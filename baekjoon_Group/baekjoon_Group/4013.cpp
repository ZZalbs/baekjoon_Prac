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

// ic와 레스토랑 모두 정점의 종류임. 목적지는 레스토랑, ic는 목적지가 될 수 없음

const int arrayLimit = 10002;


int icCount,roadCount;
int icHead,icTail;
int moneyAmount;
int startIcNum, restaurantCount;
vector<vector<int>> road;
int headNodeCount[arrayLimit];
int icValue[arrayLimit];
vector<int> restaurant;




int main()
{
    fastio;
    memset(headNodeCount,0,sizeof(headNodeCount));
    memset(icValue,0,sizeof(icValue));
    cin>>icCount>>roadCount;
    road.assign(arrayLimit,vector<int>(0,0));
    for(int i=0;i<roadCount;i++)
    {
        cin>>icHead>>icTail;
        road[icHead].push_back(icTail);
        headNodeCount[icTail]++;
    }
    for(int i=1;i<=icCount;i++)
       cin>>icValue[i];

    cin>>startIcNum>>restaurantCount;
    for(int i=1;i<=restaurantCount;i++){
        int imsiRestaurant;
        cin>>imsiRestaurant;
        restaurant.push_back(imsiRestaurant);
    }
}