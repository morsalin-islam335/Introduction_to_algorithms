//program to convert adjacency matrix to adjacency list

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int adj[N][N];
vector<vector<int>>adj_list(N);

int main()
{
    int n; cin >> n;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cin >> adj[i][j];
        }
    }
    
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(adj[i][j] !=0) adj_list[i].push_back(j);
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int v: adj_list[i]) cout<< v<<" ";
        cout<<endl;
    }
    return 0;
}