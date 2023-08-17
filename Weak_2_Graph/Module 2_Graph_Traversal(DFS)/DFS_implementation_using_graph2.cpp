//program to implement DFS by using graph
//undirected
#include<bits/stdc++.h>
using namespace std;
const int N =1e3+5;
vector<vector<int>>adj(N);//(N,vector<int>(N));
bool marked[N];

void dfs(int u)
{
    cout<<u <<" ";
    marked[u] = true;
    for(int v: adj[u])
    {
        if(marked[v] == false) dfs(v);
    }
}
int main()
{

    int numberOfNode; cin >> numberOfNode;
    int node1, node2;
    for(int i = 1; i < numberOfNode; i++)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);//for undirected
    }
    dfs(1);
    return 0;
}