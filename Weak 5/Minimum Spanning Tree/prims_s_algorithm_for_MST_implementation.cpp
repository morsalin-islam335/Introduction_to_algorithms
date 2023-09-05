//program to implement prims algorithm for MST

#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

class Edge{
    public: 
        int a, b, w;
         Edge(int a, int b, int w)
         {
            this -> a = a , this -> b = b, this -> w = w;
         }
};

class cmp{
    public:
        bool operator()(Edge a, Edge b)
        {
            return a.w > b.w;
        }
};
const int N = 1e3;
vector<vector<pii>>adj(1e3);
vector<pii>lst;
bool visited[N];

void prims(int source)
{
    priority_queue<Edge, vector<Edge>,cmp>pq;
    pq.push(Edge(source, source, 0));

    while(!pq.empty())
    {
        Edge top = pq.top(); pq.pop();
        
        int a = top.a , b = top.b, w = top.w;
        if(visited[b]) continue;
        lst.push_back({a,b});

        visited[b] = true;
        
        for(int i = 0; i < adj[b].size(); i++)
        {
            pii child = adj[b][i];

            if(!visited[child.first]) pq.push(Edge(b,child.first, child.second));
        }


    }
}
int main()
{
    int node, edge; cin >> node >> edge;
    while(edge --)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        
    }

    prims(1);
    for(pii p : lst)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    return 0;
}