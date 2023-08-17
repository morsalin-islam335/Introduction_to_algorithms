//program to implement BFS for tree
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<vector<int>>adj(N);
bool marked[N];
int level[N];

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    marked[u] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        cout<<front<<" ";
        for(int v: adj[front])
        {
            if(marked[v] != true)
            {
                q.push(v);
                marked[v] = true;
                level[v] = level[front] + 1;
            }
        }
    }
}
int main()
{
    int numberOfNode; cin >> numberOfNode;
    int numberOfEdge; cin >>numberOfEdge;
    int node1, node2; 
    while(numberOfEdge--)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    bfs(1);
    cout<<endl<<"********************"<<endl;
    for(int i = 1; i<=numberOfNode; i++)
    {
        cout<<"level of "<<i<<" is "<<level[i]<<endl;
    }
    return 0;
}