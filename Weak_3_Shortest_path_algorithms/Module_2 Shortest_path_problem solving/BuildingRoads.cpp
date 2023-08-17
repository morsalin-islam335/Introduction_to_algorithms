// program to build minimum roads from one city to another city
//problem link: https://cses.fi/problemset/task/1666

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<vector<int>>graph(N);
bool visited[N]; // false dia initialize kora aca

void dfs(int u)
{
    visited[u] = true;
    for(int v: graph[u])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}
int main()
{
    int numberOfNode, numberOfRoad;
    cin >> numberOfNode >> numberOfRoad;
    int node1, node2;
    while(numberOfRoad --)
    {
        cin>> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);

    }

    vector<int>ans;
    for(int i = 1; i<= numberOfNode; i++)
    {
        if(visited[i]) continue;
        ans.push_back(i);
        dfs(i);

    }

    cout<<ans.size() - 1 << endl;
    for(int i = 1; i<ans.size(); i++)
    {
        cout<<ans[i-1]<<" "<<ans[i] << endl;
    }

    return 0;
}