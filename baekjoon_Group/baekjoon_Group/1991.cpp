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
    char data='\0';
    char left='\0';
    char right='\0';
};

typedef struct Node tree;


void PreOrder(char node)
{
    if(node == NULL) return;
    cout<<node;
    PreOrder(tree[node-'A'].left);
    PreOrder(tree[node-'A'].right);
}

void InOrder(char node)
{
    if(node == NULL) return;
    
    InOrder(tree[node-'A'].left);
    cout<<node;
    InOrder(tree[node-'A'].right);
}

void PostOrder(char node)
{
    if(node == NULL) return;
    
    PostOrder(tree[node-'A'].left);
    PostOrder(tree[node-'A'].right);
    cout<<node;
}

int main()
{
    fastio;
    tree tree[27];
    cin>>nodeCount;
    for(int i=0;i<nodeCount;i++)
    {
        char nodeName, leftNode, rightNode;
        cin>>nodeName>>leftNode>>rightNode;
        Node& nowNode = tree[nodeName-'A'];
        nowNode = new Node(nodeName);
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