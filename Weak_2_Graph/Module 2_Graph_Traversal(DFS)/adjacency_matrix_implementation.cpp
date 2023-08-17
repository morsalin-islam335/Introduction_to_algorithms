//program to implementation adjacency matrix for undirected graph
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int adjacency_matrix[N][N];
int main()
{
    int n, m; // n for nodes m for edges
    cin >> n >> m;
    //int adjacency_matrix[N][N];
    int u, v;
    while(m--)
    {
        cin >> u >> v;
        adjacency_matrix[u][v] = 1; // for directed
        adjacency_matrix[v][u] = 1; // only for undirected

    } 
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}