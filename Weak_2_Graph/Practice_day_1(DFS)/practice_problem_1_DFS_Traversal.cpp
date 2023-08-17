//program to traverse DFS in reverse order
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<vector<int>>adj(N);
bool check[N];

stack<int>ans;
void dfs(int u)
{
    //ans.push(u);
    check[u] = true;
    for(int v: adj[u])
    {
        if(check[v] != true) dfs(v);
        // cout<<v<<" ";   
    }
    cout<<u<<" ";
}
int main()
{
    int n; cin >>n;
    int edge; cin >> edge;
    int node1, node2;
    while(edge --)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    dfs(1);
    return 0;
}