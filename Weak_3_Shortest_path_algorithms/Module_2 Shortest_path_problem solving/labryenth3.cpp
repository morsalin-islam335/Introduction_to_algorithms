//program to find out shortest path form a graph
//problem link: https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
const int N = 1e3+5;
int row,col;
bool visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii> direction = {{1,0},{-1,0},{0,1},{0,-1}};

vector<string>graph;

bool isValid(int i, int j)
{
    return (i>=0 && i< row && j>=0 && j < col);
}
void BFS(int si, int sj)
{
    queue<pii>q;
    q.push({si,sj});
    visited[si][sj] = true;
    level [si][sj] = 0;
    while(!q.empty())
    {
        pii u_pair = q.front(); q.pop();
        int i = u_pair.first, j = u_pair.second;
        for(auto dir : direction)
        {
            int ni, nj; // new i, new j
            ni = i + dir.first;
            nj = j + dir.second;
            if(isValid(ni,nj) && graph[i][j] != '#' && !visited[ni][nj])
            {
                visited[ni][nj] = true;
                q.push({ni,nj});
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i,j};
            }
        }
    }
}



int main()
{
    int si,sj, ei,ej;

    cin >> row >> col; string s;
    for(int i = 0; i < row; i++)
    {
        cin >> s;
        graph.push_back(s);
        for(int j = 0; j < col; j++)
        {
            if(s[j] == 'A'){si = i; sj = j;}
            if(s[j] == 'B') {ei = i; ej = j;}
        }
    }

    BFS(si,sj);

    if(visited[ei][ej])
    {
        cout<<"YES"<<endl;
        cout<<level[ei][ej]<<endl;

        vector<pii>path;
        pii current = {ei,ej};

        while(current.first != si || current.second != sj)
        {
            path.push_back({current.first, current.second});
            current = parent[current.first][current.second];
        }
        path.push_back({si,sj});

        reverse(path.begin(), path.end()); // reverse kora dita hoiba
        // ekhon direction print korta hoiba

        for(int i = 1; i< path.size(); i++)
        {
            if(path[i-1].first == path[i].first) // row same ki na
            {
                if(path[i-1].second > path[i].second) cout<<"L";// right theka left a movement
                else cout<<"R";//left theka right a movement
            }
            else // row same na hoila column same hoiba
            {
                if(path[i-1].first > path[i].first) cout<<"U";
                else cout<<"D";
            }
        }
    }
    else cout<<"NO";
    return 0;
}