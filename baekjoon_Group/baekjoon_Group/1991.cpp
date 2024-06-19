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


int nodeCount;

struct Node
{
    char data='.';
    char left='.';
    char right='.';
};

typedef struct Node Tree;
Tree tree[27];

void PreOrder(char node)
{
    if(node == '.') return;
    cout<<node;
    PreOrder(tree[node-'A'].left);
    PreOrder(tree[node-'A'].right);
}

void InOrder(char node)
{
    if(node == '.') return;
    
    InOrder(tree[node-'A'].left);
    cout<<node;
    InOrder(tree[node-'A'].right);
}

void PostOrder(char node)
{
    if(node == '.') return;
    
    PostOrder(tree[node-'A'].left);
    PostOrder(tree[node-'A'].right);
    cout<<node;
}

int main()
{
    fastio;
    cin>>nodeCount;
    for(int i=0;i<nodeCount;i++)
    {
        char nodeName, leftNode, rightNode;
        cin>>nodeName>>leftNode>>rightNode;
        Node& nowNode = tree[nodeName-'A'];
        nowNode.data = nodeName;
        if(leftNode!='.')   nowNode.left = leftNode;
        if(rightNode!='.')  nowNode.right = rightNode;
        
    }
    PreOrder(tree[0].data);
    cout<<"\n";
    InOrder(tree[0].data);
    cout<<"\n";
    PostOrder(tree[0].data);
    cout<<"\n";

}