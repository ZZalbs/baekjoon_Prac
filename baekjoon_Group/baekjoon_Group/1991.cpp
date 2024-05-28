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

class Node
{
    public:
        char data;
        Node left;
        Node right;
    Node(char value)
    {
        this.data = value;
        this.left = null;
        this.right = null;
    }
}


Node tree[27];


int main()
{
    fastio;
    cin>>nodeCount;
    for(int i=0;i<nodeCount;i++)
    {
        char nodeName, leftNode, rightNode;
        cin>>nodeName>>leftNode>>rightNode;
        tree[nodeName-'A'].data = nodeName;
    }
}