//program to find out level of BFS

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<vector<int>>adj(N);
int level[N];
bool visited [N];

void bfs(int s)
{
    queue<int>q;
    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(int v : adj[front])
        {
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
            level[v] = level[front] + 1;
        }
    }
}

int main()
{
    int numberOfNode; cin >> numberOfNode;
    int numberOfEdge; cin >> numberOfEdge;
    int node1, node2;

    while(numberOfEdge --)    
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    int k; cin >> k;
    bfs(1);


    cout<<"Level of " <<k <<" = "<<level[k];
    return 0;
}