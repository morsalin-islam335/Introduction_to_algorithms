// program to find out shorted distance by using BFS

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<vector<int>>adj(N);// adjacency list
bool visited[N];
int level[N];// 0 dia initialize kora aca

void BFS(int s)
{
    queue<int>q;
    q.push(s);
    visited[s] = true;
    // level of s is 0
    while(!q.empty())
    {
        int u = q.front(); 
        q.pop();

        for(int v: adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1; //  parent er theka level 1 beshi
        }
    }
}
int main()
{
    int numberOfEdge; cin >> numberOfEdge;
    int node1, node2;
    while(numberOfEdge --)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    int source, destination; cin >> source >> destination;
    BFS(source);
    cout<<level[destination];
    
    return 0;
}