//program to find out shortest path by using BFS

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<vector<int>>adj(N);// adjacency list
bool visited[N];
int level[N];// 0 dia initialize kora aca
int parent[N]; // 0 dia initialize kora aca

void BFS(int s)
{
    queue<int>q;
    q.push(s);
    visited[s] = true;
    // level of s is 0

    parent[s] = -1;
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
            parent[v] = u; // parent dia track rekha shortest path ber kora jaba



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
    // complexity of BFS or DFS is O(N+E) where N = number of node, E = number of Edges
    BFS(source); 
    
    cout<<"shortest destination from source to level is "<<level[destination]<<endl;

    vector<int>path;
    int current = destination;
    while(current != - 1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end()); // reverse korla 1st theka shortest path pawa jaba noila last theka path pawa jaba

    for(int shortest_path: path)
    {
        cout<< shortest_path<<" ";
    }
    
    return 0;
}