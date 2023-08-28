//program to implement Bellman ford algorithm which will work against negative weights
// main rule relaxation every edges in n-1 times

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
const int N = 1e3+5;
const int INF = 1e9;
vector<pii>graph[N];
vector<int>dist(N,INF); // infinite dia initialize kora aca

 int numberOfNode, numberOfEdge;

void bellman_ford(int source)
{
    dist[source] = 0;
    
    for(int i = 1; i<= numberOfNode; i++)
    {
        // now all edges relaxation in n-1 times
        for(int u = 1; u<= numberOfNode; u++)
        {
            // protiti node er kacha gelam
            for(auto v_pair : graph[u])
            {
                // protiti node er adjaceny list
                int node = v_pair.first;
                int edge = v_pair.second;  // Every element of adjacency list's first element is node and second element is edge

                if(dist[node] > dist[u]+ edge)
                {
                    dist[node] = dist[u] + edge;
                }
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
        graph[node1].push_back({node2, weight});
    }

    bellman_ford(1);

    // ekhon print least distance print korbo

    for(int i = 1; i<= numberOfNode; i++)
    {
        cout<<"Distance of "<<i<<" is "<<dist[i]<<endl;
    }
    return 0;
}