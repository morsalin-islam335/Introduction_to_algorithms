//program to find out shortest  path form a building to another building
//problem link: https://cses.fi/problemset/task/1193


#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
const int N = 1e3+5;

vector<string>graph;
bool visited[N][N];

pii parent[N][N];
int level[N][N]; // 0 dia initialize kora aca
vector<pii>direction= {{0,1},{0,-1},{1,0},{-1,0}};
int height, weight;

bool isValid(int i, int j)
{
    return (i>=0 && i<height && j >=0 && j<weight);
}
void BFS(int si, int sj)
{
    queue<pii>q;
    q.push({si,sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty())
    {
        pii u_pair = q.front();
        q.pop();

        int i = u_pair.first;
        int j = u_pair.second;
        for(auto d: direction)
        {
            int ni = i+d.first;
            int nj = j+d.second;

            if(isValid(ni,nj) && !visited[ni][nj] && graph[ni][nj] != '#')
            {
                visited[ni][nj] = true;
                q.push({ni,nj});
                level[ni][nj] = level[i][j]+1;
                parent[ni][nj]= {i,j};
            }
        }
    }
}

int main()
{
    string c;
    int si,sj,ei,ej;// si= starting i sj = starting j,  ei = ending i, ej = ending j
    cin >> height >> weight;
    for(int i = 0; i< height; i++) 
    {
        cin >> c;
        graph.push_back(c);

        for(int j = 0; j<weight; j++)
        {
            if(c[j] == 'A') {si = i; sj = j;};
            if(c[j] == 'B') {ei = i; ej = j;};
        }
    }
    BFS(si,sj);
    if(visited[ei][ej])
    {
        cout<<"YES"<<endl;
        cout<<level[ei][ej]<<endl;
        vector<pii>path;
        pii current = { ei,ej};
        while(!(current.first == si && current.second == sj))
        {
            path.push_back({current.first, current.second});
            current = parent[current.first] [current.second];
        }
        path.push_back({si,sj});

        reverse(path.begin(), path.end());

        for(int i=1;i<path.size();i++)
        {
            //path[i-1] -> path[i]
            if(path[i-1].first == path[i].first)
            {
                if(path[i-1].second == path[i].second-1)
                    cout << "R";
                else
                    cout << "L";
            }
            else
            {
                if(path[i-1].first == path[i].first-1)
                    cout << "D";
                else
                    cout << "U";
            }
        }

    }
    else { cout<< "NO";};
    
    return 0;
}