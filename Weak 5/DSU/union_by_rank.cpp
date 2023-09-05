//program to implement union by rank

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int>parent(N,-1);
vector<int>level(N,1);

int find(int node)
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}


void dsu_union(int a, int b) // which complexity O(alpha(N))
{
    int leaderA = find(a), leaderB = find(b);
    if(leaderA != leaderB)
    {
        if(level[leaderA] > level[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if(level[leaderA] < level[leaderB])
        {
            parent[leaderA] = leaderB;
        }
        else  // if both level are equal
        {
            parent[leaderA] = leaderB;
            level[leaderB]++; 
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    while(edge --) 
    {
        int a, b; cin >> a >> b;
        dsu_union(a,b);
        cout<<find(a)<<endl;
    }
    return 0;
} 