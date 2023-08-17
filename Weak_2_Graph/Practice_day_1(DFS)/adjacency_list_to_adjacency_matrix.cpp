//program to convert adjacency list to adjacency matrix

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<vector<int>>adj(N);
int adm[N][N];
int main()
{
    int n; cin >> n; 
    int edge; cin >> edge;
    int node1, node2;
    while(edge--)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
    }
    for(int i = 1; i<=n; i++)
    {
        for(int v: adj[i])
        {
            adm[i][v] = 1;
        }
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cout<<adm[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}