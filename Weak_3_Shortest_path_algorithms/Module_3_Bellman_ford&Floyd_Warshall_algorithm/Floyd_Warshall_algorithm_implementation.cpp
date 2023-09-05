// Program to implement Floyd Warshall Algorithm

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
const int INF = 1e9 + 7;
vector<vector<int>>graph(N, vector<int>(N, INF));
int numberOfNode, numberOfEdge;

void make_proper()
{
    for(int i = 0; i<= numberOfNode; i++)
    {
        for(int j = 0; j<= numberOfNode; j++)
        {
            if(i == j) graph[i][j] = 0;
        }
    }
}

void floydWarshell()
{
    for(int k = 1; k<= numberOfNode; k++)
    {
        for(int i = 1; i<= numberOfNode; i++)
        {
            for(int j = 1; j <= numberOfNode; j++)
            {
                graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
            }
        }
    }
}

void print_matrix()
{
    for(int i = 0; i<= numberOfNode; i++)
    {
        for(int j = 0; j<= numberOfNode; j++)
        {
            if(graph[i][j] !=INF) cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cin >> numberOfNode >> numberOfEdge;
    int node1, node2, weight;
    while(numberOfEdge --)
    {
        cin >> node1 >> node2 >> weight;
        graph[node1][node2] = weight;

    }

    make_proper();  // sobgulor nij theka nij distance 0 kora

    floydWarshell();
    print_matrix();

    return 0;
}