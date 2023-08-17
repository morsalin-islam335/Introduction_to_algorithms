//program to implementation adjacency list for undirected graph

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<vector<int>>adj(N);
int main()
{
    int node, edge;
    cin >> node >> edge;
    int u,v;
    while(edge --)
    {
        cin >>u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i<=node; i++)
    {
        cout<<" list "<<i<<" :";
        for(int graph: adj[i])
        {
            cout<<graph<<" ";
        }
        cout<<endl;
    }
    return 0;
}