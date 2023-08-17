//program to find out height by using DFS

#include<bits/stdc++.h>
using namespace std;
const int N =1e3+5;
vector<vector<int>>adj(N);
bool marked[N];
int height[N];
void dfs(int u)
{
    marked[u] = true;
    for(int v: adj[u])
    {
        
        if(marked[v] == false){
            dfs(v);
            if(height[v] + 1 > height[u]) height[u] = height[v] + 1;
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
        cout<<"Height of "<<i<<" is :"<<height[i]<<endl;
    }
    return 0;
}  