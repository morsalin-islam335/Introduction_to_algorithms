//program to find out connected componant from DFS

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int visited[N];
vector<vector<int>>adj(N);

void dfs(int u)
{
    
    visited[u] = true;
    for(int v: adj[u])
    {
        if(visited[v] != true) dfs(v);
    }
}
int main()
{
    int numberOfNode; cin >> numberOfNode;
    int numberOfEdge; cin >> numberOfEdge;
    int node1, node2; 
    for(int i = 1; i<= numberOfEdge; i++)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    int cc  = 0; // connected componant
    for(int i = 1; i<= numberOfEdge; i++)
    {
        if(visited[i]) continue;
        dfs(i);
        cc++;
    }
    cout<<cc;
    return 0;
}