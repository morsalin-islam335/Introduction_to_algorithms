//program to calculate height of graph by using dfs

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<vector<int>>adj(N);
bool marked[N];
int height[N];
void dfs(int u)
{
    marked[u] = true;
    for(int v: adj[u])
    {
        if(marked[v] != true) {dfs(v); if(height[v] + 1 > height[u]) height[u] = height[v] + 1;};
    }
}

int main()
{
    int numberOfNode; cin >> numberOfNode;
    int numberOfEdge; cin >> numberOfEdge;
    int node1, node2;
    while(numberOfEdge --)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    int k; cin >>k;
    dfs(1);
    cout<<"height of "<<k<<" = "<<height[k];
    return 0;
}