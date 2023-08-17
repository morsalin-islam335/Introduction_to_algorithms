
//program to find out depth of a graph by using dfs

#include<bits/stdc++.h>
using namespace std;
const int N =1e3+5;
vector<vector<int>>adj(N);
bool marked[N];
// vector<int>depth(N,0);
int depth[N];
void dfs(int u)
{
    marked[u] = true;
    for(int v: adj[u])
    {
        
        if(marked[v] == false){
            depth[v] = depth[u] + 1;
            dfs(v);
        } 
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
    for(int i = 1; i<= numberOfNode; i++)
    {
        cout<<"Depth of "<<i<<" is :"<<depth[i]<<endl;
    }
    return 0;
}