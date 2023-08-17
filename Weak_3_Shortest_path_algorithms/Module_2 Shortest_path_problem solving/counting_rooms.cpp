//program to count total number of room from a house
// problem link: https://cses.fi/problemset/task/1192

#include<bits/stdc++.h>
using namespace std;
int row, col; // col for column
const int N = 1e3+5;
bool visited[N][N];
vector<string>graph(N);


bool isValid(int i, int j)
{
    return (i>=0 && i<row && j>=0 && j< col);
}

void dfs(int i, int j)
{
    if(!isValid(i,j)) return;
    if(graph[i][j] == '#') return;
    if(visited[i][j]) return;
    
    visited[i][j] = true;
    dfs(i,j+1);
    dfs(i, j-1);

    dfs(i+1,j);
    dfs(i-1, j);

}
int main()
{
    cin >> row >> col;
    string s;
    for(int i = 0; i< row; i++)
    {
        cin >> graph[i];
    }

    int ans= 0;
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j< col; j++)
        {
            if(graph[i][j] !='#' && !visited[i][j])
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}