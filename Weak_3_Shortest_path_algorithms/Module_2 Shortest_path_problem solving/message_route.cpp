//program to find out minimus path distance from one node to another node
//problem link: https://cses.fi/problemset/task/1667

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<vector<int>>graph(N);
bool visited[N];
vector<int>parent(N,-1);

void bfs(int source, int p)// p for  parent
{
    queue<int>q;
    visited[source] = true;
    q.push(source);
    
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        
        for(int v : graph[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
        }
    }
}
int main()
{
    int numberOfNode, numberOfEdge; cin >> numberOfNode >> numberOfEdge;
    int node1, node2;
    while(numberOfEdge --)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    bfs(1,numberOfNode);
    if(parent[numberOfNode] == -1) cout<<"IMPOSSIBLE";
    else
    {
        vector<int>path;
        int current = numberOfNode;
        while(current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());
        cout<<path.size()<<endl;

        for(auto val: path)
        {
            cout<< val<<" ";
        }
    }
    return 0;
}