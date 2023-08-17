//program to find out depth form input

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
vector<vector<int>>adj(N);
bool marked[N];
int depth[N];
void dfs(int u)
{
    marked[u] = true;
    for(int v: adj[u])
    {
        if(marked[v] != true)
        {
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}
int main()
{
    int numberOfNode; cin >> numberOfNode;
    int node1, node2;
    for(int i = 1; i< numberOfNode; i++)
    {
        cin >> node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    
    dfs(1);
    int k; cin >> k;
    cout<<"Depth of "<<k<<" = "<<depth[k];
    return 0;
}