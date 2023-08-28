//program to find out shortest distance between 1 node to another node in a weighted graph

// This problem is a part of dijkstra algorithm

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
const int N = 1e3+5;
const int INF = 1e9;

vector<pii>adj[N];// adjacency list er pair er vector

vector<int>dist(N,INF); // infinite dia initialize kora aca
bool visited[N]; // false dia initialize kora aca

void BFS(int source)
{
    // priority_queue<pii>pq; // pair first pert distance and second part is vertex
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source]  = 0;
    pq.push({0, source});
    visited[source] = true;
    // ekhon pq nia operation chalata hoiba

    while(!pq.empty())
    {
        int u = pq.top().second;
		pq.pop();
		visited[u] = true;

        for(pii v_pair : adj[u])
        {
            int v = v_pair.first; // vertex of adjacency list
            int w = v_pair.second; // edge of adjacency list
            if(visited[v]) continue;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    int numberOfNode, numberOfEdge; cin >> numberOfNode >> numberOfEdge;
    int node1 , node2, weight;

    while(numberOfEdge --)
    {
        cin >> node1 >> node2 >> weight;
        adj[node1].push_back({node2,weight});
        adj[node2].push_back({node1,weight});

    }
    int source, destination; cin >> source >> destination;
    BFS(source);
    cout<< dist[destination];
    return 0;
}