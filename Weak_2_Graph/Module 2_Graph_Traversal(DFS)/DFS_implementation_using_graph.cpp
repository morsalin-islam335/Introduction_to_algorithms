//program to implementation DFS by using graph
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<vector<int>>adj(N);
bool visited[N];  

void dfs(int node)
{
    visited[node] = true;   	
    cout<<node<<" ";  // section 1: first step
    for(int v: adj[node])
    {
        if(visited[v] == false) {dfs(v);}
        
    }

}

int main()
{
    //graph input process
    int number_of_node; cin >> number_of_node;
    int node1,node2;
    for(int i  = 1; i < number_of_node; i++)
    {
        cin >>node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    //check if properly connected or not
    // for(int i = 1; i<= number_of_node; i++)
    // {
    //     cout<<i<<" :";
    //     for(int val: adj[i]) cout << val<<" ";
    //     cout << endl;
    // }

    dfs(1);
    
    return 0;
}