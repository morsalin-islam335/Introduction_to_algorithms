//program to determine if there is exist a  path form one point to another  point

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
typedef pair <int ,int>  pii;
vector<pii>direction = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

vector<string>graph;

vector<vector<bool>> visited(N, vector<bool>(N, false));
int row, column; 
bool isValid(int i, int j)
{
    return (i >= 0 && i< row && j >= 0 && j < column);
}
void DFS(int i, int j)
{

    visited[i][j] = true;
    for(auto par: direction)
    {
        int ni = i + par.first;
        int nj = j + par.second;

        if(isValid(ni,nj) && !visited[ni][nj] && graph[ni][nj] != 'x')
        {
            DFS(ni, nj);
        }
    }
}

int main()
{
    cin >> row >> column; int si, sj, ei, ej; // si = starting row, sj = starting column, ei = ending row, ej = ending column
    string s;

    for(int i = 0; i< row ; i++)
    {
       cin >> s; graph.push_back(s);

       for(int j = 0; j<column; j++) 
       {
            if(s[j] == 's') {si = i; sj = j;}
            if(s[j] == 'e') {ei = i; ej = j;}
       }
    }

    DFS(si, sj);
    (visited[ei][ej])? cout<< "YES" : cout << "NO";
    return 0;
}