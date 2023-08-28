//program to implement Bellman ford algorithm by using list of edge

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5 + 5;
typedef pair<int,int>pii;
vector<pair<pii,int>>listOfEdge;

vector<int>dist(N,INF);
int numberOfNode, numberOfEdge;

void Bellman_ford(int source)
{
    dist[source] = 0;

    for(int i = 1; i < numberOfNode; i++)
    {
        for(auto edge : listOfEdge)
        {
            int u, v, w; // u = node1 , v = node2 , w = edge
            u = edge.first.first;
            v = edge.first.second;
            w = edge.second;

            if(dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}
int main()
{
    cin >> numberOfNode >> numberOfEdge;
    int node1, node2, weight;
    
    while(numberOfEdge --)
    {
        cin >> node1 >> node2 >> weight;
        listOfEdge.push_back({{node1,node2}, weight});

    }

    Bellman_ford(1);

    for(int i = 1; i <= numberOfNode; i++)
    {
        cout<<"Distance of "<<i <<" is "<<dist[i]<<endl;
    }
    return 0;
}