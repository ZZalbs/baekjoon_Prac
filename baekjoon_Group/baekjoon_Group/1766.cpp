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

const int arrayLimit = 100002;

int questionCount,informationCount;
vector<vector<int>> informationAboutQuestions;
int headNodeCount[arrayLimit];
set<int> setForBFS; // 원래는 우선순위 큐 만들어야되는데, set으로 대체되니까 그냥 set씀

void InputQuestionCntAndInfoCnt(){
    cin>>questionCount>>informationCount;
}

void TopologicalSort()
{
    for(int i=1;i<=questionCount;i++)
    {
        if(headNodeCount[i]==0) setForBFS.insert(i);
    }

    while(!setForBFS.empty())
    {
        int nowNode = *(setForBFS.begin());
        setForBFS.erase(setForBFS.begin());
        cout<<nowNode<<" ";
        for(int i=0;i<informationAboutQuestions[nowNode].size();i++)
        {
            int nextNode = informationAboutQuestions[nowNode][i];
            headNodeCount[nextNode]--;
            if(headNodeCount[nextNode]==0) setForBFS.insert(nextNode);
        }
    }
}


int main()
{
    fastio;
    InputQuestionCntAndInfoCnt();    
    memset(headNodeCount,0,sizeof(headNodeCount));
    informationAboutQuestions.assign(arrayLimit,vector<int>(0,0));
    int firstSolveQues, laterSolveQues;
    for(int i=0;i<informationCount;i++)
    {
        cin>>firstSolveQues>>laterSolveQues;
        informationAboutQuestions[firstSolveQues].push_back(laterSolveQues);
        headNodeCount[laterSolveQues]++;
    }

    TopologicalSort();
}