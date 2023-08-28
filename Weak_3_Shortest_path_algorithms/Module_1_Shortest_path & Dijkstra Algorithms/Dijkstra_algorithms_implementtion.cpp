// program to find out shortest path in a weighted graph by using dijkstra algorithms

#include<bits/stdc++.h>
using namespace std;



const int N = 1e3+5;
const int INF = 1e9;
vector<int>dist(N,INF); // sobaika infinite dia initialize kora dewa hoilo


typedef pair<int,int>pii;// pair data type er gaygay eta use korla pair data type er kaj korba
vector<pii>adj[N]; // adjacency list er pair

bool visited[N];  // sobai initially false dea dewa aca


void dijkstra(int source)
{
    priority_queue<pii , vector<pii>, greater<pii>>pq; // choto theka boro priority queue
    dist[source] = 0;
    pq.push({dist[source], source});
    
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(pii v_pair: adj[u])
        {
            int v = v_pair.first;
            int w = v_pair.second;

            if (visited[v]) continue;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

}
int main()
{
    int numberOfNode, numberOfEdge; 
    cin >> numberOfNode >> numberOfEdge;
    int node1, node2, weight; // weight hoilo ekta node theka onno ekta node er weight
    
    while(numberOfEdge --)
    {
        cin >> node1 >> node2 >> weight;
        adj[node1].push_back({node2,weight});
        adj[node2].push_back({node1,weight});
       
       
    }

    dijkstra(1);

    for(int i = 1; i<= numberOfNode; i++)
    {
        cout<<"Distance of node "<<i <<" :";
        cout<<dist[i]<<endl;
    }
    return 0;
}