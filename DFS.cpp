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

void DFS(Node[],int);

int main()
{
    Node nodes[] = {Node(0,"A"), Node(1,"B"), Node(2,"C"), Node(3,"D")};
    
    nodes[0].neighbors = {1,2,3};
    nodes[1].neighbors = {0};
    nodes[2].neighbors = {0,3};
    nodes[3].neighbors = {0,2};
    
    DFS(nodes,2);
    
    return 0;
}

void DFS(Node nodes[], int n)
{
    bool willPop;
    stack<Node> s;
    s.push(nodes[n]);
    nodes[n].visited = true;
    cout<<s.top().name<<" ";
    
    while(s.size()!=0)
    {
        willPop = true;
        for(long unsigned int i = 0; i < s.top().neighbors.size(); i++)
        {
            int current = s.top().neighbors[i];
            if(nodes[current].visited == false)
            {
                nodes[current].visited = true;
                willPop = false;
                s.push(nodes[current]);
                cout<<s.top().name<<" ";
                break;
            }
        }
        if(willPop == true)
        {
            s.pop();
        }
    }
}
