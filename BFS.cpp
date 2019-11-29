#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    
    int index;
    string name;
    vector<int> neighbors;
    bool visited;
    
    Node( int i, string n )
    {
        index = i;
        name = n;
        neighbors.clear();
        visited = false;
    }
};

void BFS(Node[],int);

int main()
{
    Node nodes[] = {Node(0,"A"), Node(1,"B"), Node(2,"C"), Node(3,"D")};
    
    nodes[0].neighbors = {1,2,3};
    nodes[1].neighbors = {0};
    nodes[2].neighbors = {0,3};
    nodes[3].neighbors = {0,2};
    
    BFS(nodes,2);
    
    return 0;
}

void BFS(Node nodes[], int n)
{
    bool willPop;
    queue<Node> q;
    q.push(nodes[n]);
    nodes[n].visited = true;
    
    while(q.size()!=0)
    {
        for(long unsigned int i = 0; i < q.front().neighbors.size(); i++)
        {
            int current = q.front().neighbors[i];
            if(nodes[current].visited == false)
            {
                nodes[current].visited = true;
                q.push(nodes[current]);
            }
        }
        cout<<q.front().name<<" ";
        q.pop();
    }
}
