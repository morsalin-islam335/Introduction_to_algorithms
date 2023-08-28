//program to find out shortest distance on directed graph by using dijkstra algorithms

#include<bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 7;
typedef pair <int, int> pii;
bool visited[N];
const int INF  = 1e9;
vector<int>dist(N,INF);
vector<pii>adj[N];


void BFS(int source)
{
    priority_queue<pii, vector<pii>,greater<pii>>pq; // for ascending order 
    dist[source] = 0;
    pq.push({dist[source], source});

    while(!pq.empty())
    {
        pii v_pair = pq.top(); pq.pop();
        visited[v_pair.second] = true;
        int u = v_pair.second; 

        for(auto v : adj[u])
        {
            int node, weight;
            node = v.first; weight = v.second;

            if(visited[node]) continue;

            if(dist[u] != INF && dist[node] > dist[u] + weight)
            {
                dist[node] = dist[u] + weight;
                pq.push({dist[node], node});
            }
        }
    }
}

int main()
{
    int numberOfNode; cin >> numberOfNode; int numberOfEdge; cin >> numberOfEdge;
    int node1, node2, weight;
    while(numberOfEdge  --)
    {
        cin >> node1 >> node2 >> weight;
        adj[node1].push_back({node2, weight});
        // this is a directed graph
    }
    int source , destination; cin >> source >> destination;
    BFS(source);
    cout<<dist[destination];
    return 0;
}